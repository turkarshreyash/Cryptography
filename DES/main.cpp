#include"binary.h"
#include"DES.hpp"
#include<iostream>

#define DEBUG

int main(){
    uint64_t key = 0x133457799BBCDFF1;
    uint64_t plain = (uint64_t)0x0123456789ABCDEF;

    printf("Plain Text : %lx\n",plain);
    printf("Key : %lx\n",key);

    DES temp(key);
    
    uint64_t encrypt = temp.encrypt(plain);
    printf("Encrypt : %lx\n",encrypt);
}