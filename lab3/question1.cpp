#include<iostream>
#include"../f32_printf/src/f32_printf.h"

char secret_key[5][5] = {{'L','G','D','B','A'}
						,{'Q','M','H','E','C'}
						,{'U','R','N','I','F'}
						,{'X','V','S','O','K'}
						,{'Z','Y','W','T','P'}};
uint16_t x_i = 3;
uint16_t x_j = 0;
uint16_t z_i = 4;
uint16_t z_j = 0;


int main(int argc, char *args[]){
	uint16_t i,j,i1,i2,j1,j2,t_i,t_j;
	uint16_t base = 0;
	uint16_t offset = 0;
	char prev_char = 0;
	f32_printf(F_GREEN,"Plain Text: ");
	std::cout<<args[1]<<"\n";
	f32_printf(F_RED,"Encrypted Text: ");
	while(args[1][base+offset] != '\0' || offset == 1){
		//std::cout<<"base: "<<base<<"\t offset: "<<offset<<"\n";
		if((args[1][base+offset] !='\0' && prev_char == args[1][base+ offset])){
			t_i = x_i;
			t_j = x_j;
		}else if(offset == 1 && args[1][base+offset] == '\0'){
			t_i = z_i;
			t_j = z_j;
		}else{
			//std::cout<<"OK\n";
			for(i = 0 ; i < 5; i++){
				for(j = 0 ; j < 5; j++){
					if(args[1][base+offset]==secret_key[i][j]){
						t_i = i;
						t_j = j;
						i = 6;
						j = 6;
						break;
					}
				}
			}
		}
		//std::cout<<"Char: "<<args[1][base+offset]<<" i: "<<i<<" j: "<<j<<"\n";
		if(offset == 0){
			i1 = t_i;
			j1 = t_j;
		}else{
			i2 = t_i;
			j2 = t_j;
		}
		prev_char = args[1][base+offset];
		offset++;
		if(offset == 2){
			if(i1 == i2){
				std::cout<<secret_key[i1][(j1+1)%5]<<secret_key[i2][(j2+1)%5];
			}else if(j1 == j2){

				std::cout<<secret_key[(i1+1)%5][j1]<<secret_key[(i2+1)%5][j2];
			}else{
				std::cout<<secret_key[i1][j2]<<secret_key[i2][j1];
			}
			if(args[1][base+offset-1] == '\0'){
				break;
			}
			base+=2;
			offset = 0;
		}
		
	}
	std::cout<<"\n";
}