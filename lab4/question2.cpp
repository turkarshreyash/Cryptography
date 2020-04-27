#include<iostream>
#include<inttypes.h>

uint16_t ctoi(char *arr){
	uint16_t i = 0;
	uint16_t number = 0;
	while(arr[i] != '\0'){
		number += arr[i] - '0';
		number *= 10;
		i++;
	}
	return number/10;
}

int main(int argc, char *args[]){
	//seed len
	uint16_t len = ctoi(args[2]);
	std::cout<<"Len : "<<len<<"\n";
	uint16_t stream;
	stream = stream^stream;
	uint16_t i = 0;
	while(args[1][i] != '\0'){
		stream = stream<<1;
		stream = stream | (args[1][i]=='0'?0x0:0x1);
		i++;
	}
	uint16_t seed_size = i;
	uint16_t seed_len = i;
	i = 0;
	len -= seed_len;
	uint16_t temp = 0;
	temp = temp^temp;
	while(i<len){
		temp = ((stream&0x8>>3)^(stream&0x4>>2))&0x1;
		stream = stream<<1;
		stream = stream | temp;
		i++;
	}
	i=0;
	len+=seed_len;
	while(i<len){
		std::cout<<(stream&0x1);
		stream = stream>>1;
		i++;
	}
}
