/*
Shreyash H. Turkar
COVID19 Special 2020
*/

#pragma once 

#include<iostream>
#include<inttypes.h>
#include<algorithm>
#include<cmath>

struct key{
    double mod;
    double exp;
};

struct key* getPrivateKey(double,double,double,double);

struct key* getPublicKey(double,double,double);

void encrypt(uint8_t*,uint8_t*,uint32_t, struct key*);

void decrypt(uint8_t*,uint8_t*,uint32_t, struct key*);