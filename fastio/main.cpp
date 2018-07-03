#include <cstdio>
#include <iostream>
#include "fastio.h"
using namespace std;
int main(){
	int integer;
	long long int llinteger;
	char c;
	
	integer=read(integer); //讀入 
	print(integer); //印出 
	
	llinteger=read(llinteger);
	print(llinteger);
	
	while(readEOF(integer)){ //讀入直到EOF
		print(integer);
	}
	
	return 0;
}
