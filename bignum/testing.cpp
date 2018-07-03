#include <new>
#include <cstdio>
#include <cstring>

class bignum{
	public:
		int *big;
		bool is_negative;
		int length;
		
		//constructor
		bignum() {big=new int[100]; length=100; memset(big, 0, 100);}
		bignum(int len) {length=len>>2; big=new int[length]; memset(big, 0, length);}
		//destructor
		~bignum() {delete[] big;}
		//io
		void read();
		void print();
		//operator
		bignum operator+(const bignum&);
		bignum operator-(const bignum&);
		bignum operator*(const bignum&);
		bignum operator/(const bignum&);
		//comparator
		
};

//io
void bignum::read(){
	char *str=new char[length*4+2];
	scanf("%s", str);
	int end=0;
	if(str[0]=='-') end=1;
	int tmp=strlen(str);
	length=((tmp-end)>>2)+1;
	for(int i=length-1;i>;i++){
		for(int j=4;j;j--)
			big[i]=(big[i]<<3)+(big[i]<<1)+str[tmp-j]-48, tmp-=4;
	}
	length&=3;
	
	
	
}
void bignum::print(){
	for(int i=0;i<length;i++){
		printf("%d\n", big[i]);
	}
}

int main(){
	bignum B;
	B.read();
//	B.print();
	
	return 0;
}
