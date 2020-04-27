#include<iostream>
#include<inttypes.h>

void get(char *args[], uint16_t col, uint16_t no_cols, uint16_t l){
	uint16_t i = col;
	while(i < l){
		std::cout<<args[2][i];
		i += no_cols;
	}
}

int main(int argc, char *args[]){
	uint16_t *key = new uint16_t[26];

	uint16_t cols = 0;
	uint16_t i ;
	
	
	while(args[1][cols] != '\0'){
		key[args[1][cols] - '1'] = cols;
		//std::cout<<args[1][cols]<<"\t"<<key[cols]<<"\n";
		cols++;
	}
	uint16_t len = 0;
	while(args[2][len] != '\0'){
		len++;
	}
	i=0;
	std::cout<<"\n";
	while(i<cols){
		get(args,key[i],cols,len);
		i++;
	}
	std::cout<<"\n";
}
