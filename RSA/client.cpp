#include<iostream>
#include<cstring>
#include"RSA.hpp"
#include"udp.hpp"

#define MAXLINE 512

int main(){
    struct key* private_key = getPrivateKey(3,7,2,2);
    UDPHost *client = new UDPHost(127,0,0,1,8008);
    uint8_t *plain_text = new uint8_t[MAXLINE];
    uint8_t *encrypted = new uint8_t[MAXLINE];
    uint16_t temp,i;
    struct message *new_mail = new struct message;
    while(true){
        new_mail = client->recv(new_mail);
        std::cout<<"Received Message!\nEncrypted: "<<std::endl;
        i=0;
        for(uint16_t j = 0 ; new_mail->buffer[j] != '\0' ; j++){
            std::cout<<(uint16_t)new_mail->buffer[j]<<"\t";
            i++;
        }
        std::cout<<"\n("<<i<<")Plain Text: "<<std::endl;
        decrypt((uint8_t*)new_mail->buffer,plain_text,i,private_key);
        for(uint16_t j = 0 ; j < i ; j++){
            std::cout<<(uint16_t)plain_text[j]<<"\t";
        }
        std::cout<<std::endl;
    }
    
}