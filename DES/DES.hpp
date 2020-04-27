/*
Shreyash H. Turkar
COVID19 Special 2020
*/

#pragma once

#include<inttypes.h>
#include"binary.h"

//#define DEBUG

class DES{
    uint64_t key;
    uint64_t key_plus;
    uint64_t keys[16];

    void __definekeys();
    uint32_t __f(uint32_t,uint64_t);

    public:
        DES(uint64_t);
        uint64_t encrypt(uint64_t);
};