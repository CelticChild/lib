#include <cstdio>
#include <iostream>
#include "fastio.h"
using namespace std;
int main(){
	int integer;
	long long int llinteger;
	char c;
	
	integer=read(integer); //Ū�J 
	print(integer); //�L�X 
	
	llinteger=read(llinteger);
	print(llinteger);
	
	while(readEOF(integer)){ //Ū�J����EOF
		print(integer);
	}
	
	return 0;
}
