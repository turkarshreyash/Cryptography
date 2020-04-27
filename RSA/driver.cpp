#include<iostream>
#include<cstring>
#include"RSA.hpp"


int main(){
    struct RSACryptosystem* sender = GET_RSA_INIT(3,7,2,2);
    display(sender);
    uint8_t *input = new uint8_t[8];
    uint8_t temp[8] = {(uint8_t)12,(uint8_t)1,(uint8_t)2,(uint8_t)9,(uint8_t)10,(uint8_t)1,(uint8_t)6,(uint8_t)8};
    memccpy(input,&temp,8,8);
    for(int i = 0 ; i < 8 ; i++){
        std::cout<<(((uint16_t)input[i])&0xff)<<"\t";
    }
    std::cout<<std::endl;
    uint8_t *output = new uint8_t[8];

    encrypt(input,output,8,sender);

    for(int i = 0 ; i < 8 ; i++){
        std::cout<<(((uint16_t)output[i])&0xff)<<"\t";
    }
     
    struct RSACryptosystem* recv = GET_RSA_INIT(3,7,2,4);

    uint8_t *output_dec = new uint8_t[8];

    decrypt(output,output_dec,8,recv);
    std::cout<<std::endl;
    for(int i = 0 ; i < 8 ; i++){
        std::cout<<(((uint16_t)output_dec[i])&0xff)<<"\t";
    }


}
