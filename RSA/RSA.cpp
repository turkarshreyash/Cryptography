#include"RSA.hpp"

struct key* getPrivateKey(double p,double q, double e,double k){
    
    struct key *new_system = new struct key;

    new_system->mod = p*q; 

    double sig = (p-1)*(q-1); 
    
    while (e < sig){
  
        if(std::__gcd((uint64_t)e,(uint64_t)sig)==1) {
            break;
        }
        else{
            e++;
        }
    } 
    new_system->exp = (1 + (k*sig))/e;

    return new_system;
}

struct key* getPublicKey(double p,double q, double e){
    
    struct key *new_system = new struct key;

    new_system->mod = p*q; 

    double sig = (p-1)*(q-1); 
    
    while (e < sig){
  
        if(std::__gcd((uint64_t)e,(uint64_t)sig)==1) {
            break;
        }
        else{
            e++;
        }
    } 
    new_system->exp = e;

    return new_system;
}


void encrypt(uint8_t *input_string, uint8_t *output_string, uint32_t size,struct key* system){
    uint32_t t = 0;
    double temp;
    while(t<size){
        temp = (double)input_string[t];
        temp = pow(temp,system->exp);
        temp = fmod(temp,system->mod);
        output_string[t] = ((uint8_t)temp);
        t++;
    }
}

void decrypt(uint8_t *input_string, uint8_t *output_string, uint32_t size, struct key* system){
    uint32_t t = 0;
    double temp;
    while(t<size){
        temp = (double)input_string[t];
        temp = pow(temp,system->exp);
        temp = fmod(temp,system->mod);
        output_string[t] = temp;
        t++;
    }
}