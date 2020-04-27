#include"binary.h"

uint64_t left_bin_rotate(uint64_t input, uint16_t size, uint16_t rotate_by){
    //4
    //0 1 1 0 1 
    uint16_t shift = size - rotate_by;
    return (((input<<rotate_by))|(input>>shift)) & (0xffffffffffffffff>>(64-size)) ;
}

uint64_t permute(uint64_t input, uint16_t bit_size, const uint8_t* sbox, uint16_t array_size){
    uint64_t output = 0x0;
    uint8_t temp;
    uint16_t i = 0;
    while(i < array_size){
        temp = (input>>(bit_size-sbox[i]))&0x1;
        output = output<<1;
        output = output|temp;
        i++;
    }
    return output;
}

void display_binary(uint64_t input,uint16_t size, uint16_t chuck){
    uint16_t j = 0;
    for(int32_t i = size-1 ; i >= 0 ; i--,j++){
        if(j==chuck){
            std::cout<<" ";
            j=0;
        }
        std::cout<<((input>>i)&0x1);
    }
    std::cout<<"\n";
}