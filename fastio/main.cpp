#include <cstdio>
#include <iostream>
#include "fastio.h"
using namespace std;
int main(){
	int integer;
	long long int llinteger;
	char c;
	
	integer=read(integer);
	print(integer);
	
	llinteger=read(llinteger);
	print(llinteger);
	
	while(readEOF(integer)){ //read until EOF
		print(integer);
	}
	
	return 0;
}
