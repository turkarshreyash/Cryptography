#include"_aes_binary.h"

void __display_block(block *input){
    for(uint8_t i = 0 ; i < 0x4 ; i++){
        for(uint8_t j = 0 ; j < 0x4 ; j++){
            printf("%x ",input->cell[i][j]);
        }
        printf("\n");
    }
}

block* __create_block(uint32_t row1, uint32_t row2, uint32_t row3, uint32_t row4){
    block *output = (block*)malloc(sizeof(block));
    uint32_t rows[4];
    rows[0] = row1; rows[1] = row2; rows[2] = row3; rows[3] = row4;
    for(uint8_t i = 0 ; i < 0x4 ; i++){
        for(uint8_t j = 0 ; j < 0x4 ; j++){
            output->cell[j][i] = (rows[i]>>(24-(8*j)))&0xff;
        }
    }
    return output;
}

void __step_one_subbyte(block *data){

    uint8_t temp;
    uint8_t temp2;

    for(uint8_t j = 0 ; j < 0x4 ; j++){
        for(uint8_t i = 0 ; i < 0x4 ; i++){
            data->cell[i][j] = __sbox[data->cell[i][j]>>4][data->cell[i][j]&0xf];
        }
    }
}

void __step_two_shiftrows(block *input){
    block *output = (block*)malloc(sizeof(block));
    uint8_t temp;
    for(uint8_t j = 0 ; j < 4 ; j++){
        for(uint8_t i = 0 ; i < 4 ; i++){
            temp = (i+j)%4;
            output->cell[i][j] = input->cell[i][temp];
        }
    }
    memcpy(input,output,sizeof(block));
}

void __gmix_column(uint8_t *r) {
    uint8_t a[4];
    uint8_t b[4];
    uint8_t c;
    uint8_t h;
    /* The array 'a' is simply a copy of the input array 'r'
     * The array 'b' is each element of the array 'a' multiplied by 2
     * in Rijndael's Galois field
     * a[n] ^ b[n] is element n multiplied by 3 in Rijndael's Galois field */ 
    for (c = 0; c < 4; c++) {
        a[c] = r[c];
        /* h is 0xff if the high bit of r[c] is set, 0 otherwise */
        h = (uint8_t)((int8_t)r[c] >> 7); /* arithmetic right shift, thus shifting in either zeros or ones */
        b[c] = r[c] << 1; /* implicitly removes high bit because b[c] is an 8-bit char, so we xor by 0x1b and not 0x11b in the next line */
        b[c] ^= 0x1B & h; /* Rijndael's Galois field */
    }
    r[0] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1]; /* 2 * a0 + a3 + a2 + 3 * a1 */
    r[1] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2]; /* 2 * a1 + a0 + a3 + 3 * a2 */
    r[2] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3]; /* 2 * a2 + a1 + a0 + 3 * a3 */
    r[3] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0]; /* 2 * a3 + a2 + a1 + 3 * a0 */
}


void __step_three_mixcolumn(block *input){
    uint8_t temp[4];

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            temp[j] = input->cell[j][i]; //place the current state column in temp
        }
        __gmix_column(temp); //mix it using the wiki implementation
        for(int j = 0; j < 4; j++)
        {
            input->cell[j][i] = temp[j]; //when the column is mixed, place it back into the state
        }
    }
}

void __step_four_addkey(block *input, block *key){
    for(uint8_t i = 0 ; i < 4 ; i++){
        for(uint8_t j = 0 ; j < 4 ; j++){
            input->cell[i][j] = input->cell[i][j] ^ key->cell[i][j];
        }
    }
}

void __next_key(block *input, uint8_t rn){
    uint8_t temp;
    for(uint8_t i = 0 ; i < 4 ; i++){
        temp = input->cell[(i+1)%4][3];
        temp = __sbox[temp>>4][temp&0xf];
        input->cell[i][0] = temp^input->cell[i][0];
    }
    input->cell[0][0] ^=__rk[rn];
    for(uint8_t i = 1 ; i < 4 ; i++){
        for(uint8_t j = 0 ; j < 4 ; j++){
            input->cell[j][i] = input->cell[j][i-1]^input->cell[j][i];
        }
    }
}


void encrypt(block *input, block *key){
    for(uint8_t i = 0 ; i < 11; i++){
        if(i!=0){
            __step_one_subbyte(input);
            printf("Round %d Step 1 : \n",i);
            __display_block(input);
            __step_two_shiftrows(input);
            printf("Round %d Step 2 : \n",i);
            __display_block(input);
        }
        
        if(i != 10 && i!=0){
            __step_three_mixcolumn(input);
            printf("Round %d Step 3 : \n",i);
            __display_block(input);
        }
        __step_four_addkey(input,key);
        printf("Round %d Step 4 : \n",i);
        __display_block(input);
        __next_key(key,i);
        printf("Round %d Key:  \n",i);
        __display_block(key);
        printf("-------------------------------------\n");
    }

}
