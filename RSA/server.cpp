#include<iostream>
#include<cstring>
#include"RSA.hpp"
#include"udp.hpp"

#define MAXLINE 512

int main(){
    struct key* public_key = getPublicKey(3,7,2);
    UDPHost *server = new UDPHost(127,0,0,1,8000);
    uint8_t *plain_text = new uint8_t[MAXLINE];
    uint8_t *encrypted = new uint8_t[MAXLINE];
    uint16_t temp,i;
    while(true){
        i=0;
        std::cout<<"Type Message : ";
        std::cin>>temp;
        while(temp != 0){
            plain_text[i]= temp&0xff;
            i++;
            std::cin>>temp;
        }
        std::cout<<"\nPlain Text: "<<std::endl;
        for(uint16_t j = 0 ; j < i ; j++){
            std::cout<<(uint16_t)plain_text[j]<<"\t";
        }
        std::cout<<"\nEncrypted: "<<std::endl;
        encrypt(plain_text,encrypted,i,public_key);
        for(uint16_t j = 0 ; j < i ; j++){
            std::cout<<(uint16_t)encrypted[j]<<"\t";
        }
        encrypted[i] = '\0';
        std::cout<<"\nSending. . . "<<std::endl;
        server->send(i,(char*)encrypted,127,0,0,1,8008);  
        std::cout<<"Sent!"<<std::endl;
    }
    
}