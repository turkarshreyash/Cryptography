#include<stdio.h>
#include"_aes_binary.h"

int main(){
    block *key = __create_block(0x54686174, 0x73206D79, 0x204B756E,0x67204675);
    __display_block(key);
    printf("\n");
    block *data = __create_block(0x54776F20, 0x4F6E6520, 0x4E696E65, 0x2054776F);
    __display_block(data);

    encrypt(data,key);
    printf("\n");
    __display_block(data);
}