#include"DES.hpp"

DES::DES(uint64_t tkey){
    key = tkey;
    __definekeys();
}

void DES::__definekeys(){
    key_plus = permute(key,64,__pc_one,56);
    //c0 d0
    uint32_t ci = (key_plus>>28);
    uint32_t di = (key_plus)&0x0fffffff;
    uint64_t cidi;

    uint16_t i = 0;

    //1 to 16
    while(i<16){
        ci = left_bin_rotate(ci,28,__left_shifts[i]);
        di = left_bin_rotate(di,28,__left_shifts[i]);
        cidi = ((uint64_t)ci<<28)|di;
        keys[i] = permute(cidi,56,__pc_two,48);
        i++;
    }
}

uint64_t DES::encrypt(uint64_t data){
    
    uint64_t ip = permute(data,64,__ip,64);

    #ifdef DEBUG
        printf("ip : %lx\n",ip);
    #endif

    //l0 r0
    uint32_t li = ip>>32;
    uint32_t ri = ip&0xffffffff;
    uint32_t temp; 

    uint64_t _r16_l16;
    uint64_t ip_inv;

    uint16_t i = 0;

    while(i<16){
        temp = li;
        li = ri;
        ri = temp ^ __f(ri,keys[i]);
        i++;
        #ifdef DEBUG
            printf("l(%d) : %x\t",i,li);
            printf("r(%d) : %x\t",i,ri);
            printf("k(%d) : %lx\n",i,keys[i-1]);
        #endif
    }
    
    _r16_l16 = (((uint64_t)ri)<<32)|li;

    #ifdef DEBUG
        printf("r16l16 : %xl\n",_r16_l16);
    #endif

    ip_inv = permute(_r16_l16,64,__ip_inv,64);

   #ifdef DEBUG
        printf("ip_inv : %xl\n",ip_inv);
    #endif

    return ip_inv;
}

uint32_t DES::__f(uint32_t ri, uint64_t ki){
    
    uint64_t _e_ri = permute(ri,32,__e,48);
    uint64_t _ki_e_ri = ki^_e_ri;
    uint32_t output=0x0;

    uint16_t i = 0;
    uint8_t bi;
    uint8_t col;
    uint8_t row;

    while(i<8){
        bi = (_ki_e_ri>>(42-(i*6)))&0x3f;
        row = (bi>>4 & 0b10) | (bi & 0b01);
        col = (bi>>1 & 0b1111);
        output = (output<<4)|(__s[i][row][col]);
        i++;
    }
    output = permute(output,32,__p,32);
    return output;
}