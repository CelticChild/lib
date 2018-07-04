#include <new>
#include <cstdio>
#include <cstring>

int min(const int &a, const int &b){
	return (a<b)? a:b;
}

class bignum{
	public:
		int *big;
		bool is_negative;
		int length;
		
		//constructor
		bignum() {big=new int[100]; length=100; memset(big, 0, 100); is_negative=false;}
		bignum(int len) {length=len>>2; big=new int[length]; memset(big, 0, length); is_negative=false;}
		bignum(const bignum &des){
			big=new int[100];
			memset(big, 0, 100);
			for(int i=0;i<des.length;i++) this->big[i]=des.big[i];
			length=des.length;
			is_negative=des.is_negative;
		}
		//destructor
		~bignum() {delete[] big;}
		//io
		void read();
		void print();
		//equal
		bignum operator=(const bignum&);
		//unary operator
		bignum operator-();
		//operator
		bignum operator+(bignum);
		bignum operator-(bignum);
		bignum operator*(const bignum&);
		bignum operator/(const bignum&);
		//comparator
		bool operator<(const bignum&);
		bool operator>(const bignum&);
		
	private:
		//helping functions
};

//io
void bignum::read(){
	char *str=new char[length*4+2];
	scanf("%s", str);
	if(str[0]=='-') is_negative=1;
	int tmp=strlen(str);
	length=(tmp-is_negative-1)>>2;
	for(int i=0;i<length;i++){
		for(int j=4;j;j--)
			big[i]=(big[i]<<3)+(big[i]<<1)+str[tmp-j]-48;
		tmp-=4;
	}
	for(int i=tmp-is_negative;i;i--)
		big[length]=(big[length]<<3)+(big[length]<<1)+str[tmp-i]-48;
	length++;
}
void bignum::print(){
	if(length==0){
		puts("0");
		return;
	}
	
	if(is_negative){
		printf("-%d", big[length-1]);
		for(int i=length-2;i>=0;i--){
			if(big[i]<10) printf("000%d", big[i]);
			else if(big[i]<100) printf("00%d", big[i]);
			else if(big[i]<1000) printf("0%d", big[i]);
			else printf("%d", big[i]);
		}
	}
	else
		printf("%d", big[length-1]);
		for(int i=length-2;i>=0;i--){
			if(big[i]<10) printf("000%d", big[i]);
			else if(big[i]<100) printf("00%d", big[i]);
			else if(big[i]<1000) printf("0%d", big[i]);
			else printf("%d", big[i]);
		}
	puts("");
}
//equal
bignum bignum::operator=(const bignum &des){
	for(int i=0;i<des.length;i++) this->big[i]=des.big[i];
	this->length=des.length;
	this->is_negative=des.is_negative;
	return *this;
}
//unary operator
bignum bignum::operator-(){
	this->is_negative=!this->is_negative;
	return *this;
}
//operator
bignum bignum::operator+(bignum des){
	bignum B(*this);
	if(B.is_negative && !des.is_negative){
		B.is_negative=false;
		return des-B;
	}
	else if(!B.is_negative && des.is_negative){
		des.is_negative=false;
		return B-des;
	}
	else if(B.is_negative && des.is_negative) B.is_negative=true;
	int len=min(B.length, des.length), remain=0;
	for(int i=0;i<len;i++){
		B.big[i]=this->big[i]+des.big[i]+remain;
		remain=B.big[i]/10000;
		B.big[i]%=10000;
	}
	if(remain!=0)
		B.big[len]=remain, B.length++; 
	
	return B;
}
bignum bignum::operator-(bignum des){
	bignum B(*this);
	int len=min(B.length, des.length);
	
	if(B.is_negative && !des.is_negative){
		des.is_negative=true;
		return des+B;
	}
	else if(!B.is_negative && des.is_negative){
		des.is_negative=false;
		return des+B;
	}
	else if(B.is_negative && des.is_negative){ //turn to des-this
		if(des<B){
			for(int i=0;i<len;i++){
				if(B.big[i] < des.big[i]){
					B.big[i]+=10000;
					B.big[i+1]--;
				}
				B.big[i]-=des.big[i];
			}
			for(int i=len-1;i>=0;i--){
				if(B.big[i]==0) length--;
				else break;
			}
			return -B;
		}
		else{
			for(int i=0;i<len;i++){
				if(des.big[i] < this->big[i]){
					des.big[i]+=10000;
					des.big[i+1]--;
				}
				B.big[i]=des.big[i]-this->big[i];
			}
			for(int i=len-1;i>=0;i--){
				if(B.big[i]==0) length--;
				else break;
			}
			return B;
		}
	}
	else{ //this-des
		if(B<des){
			for(int i=0;i<len;i++){
				if(des.big[i] < this->big[i]){
					des.big[i]+=10000;
					des.big[i+1]--;
				}
				B.big[i]=des.big[i]-this->big[i];
			}
			for(int i=len-1;i>=0;i--){
				if(B.big[i]==0) length--;
				else break;
			}
			return -B;
		}
		else{
			for(int i=0;i<len;i++){
				if(B.big[i] < des.big[i]){
					B.big[i]+=10000;
					B.big[i+1]--;
				}
				B.big[i]-=des.big[i];
			}
			for(int i=len-1;i>=0;i--){
				if(B.big[i]==0) B.length--;
				else break;
			}
			return B;
		}
	}
}
/*
	if(this->is_negative ^ des.is_negative)
		B.is_negative=true;
*/

//comparator
bool bignum::operator<(const bignum &des){
	if(this->is_negative && !des.is_negative) return true;
	else if(!this->is_negative && des.is_negative) return false;
	
	if(this->length < des.length) return true;
	else if(this->length > des.length) return false;
	
	if(!this->is_negative && !des.is_negative){
		for(int i=this->length-1;i>=0;i--){
			if(this->big[i] < des.big[i])
				return true;
			else if(this->big[i] > des.big[i])
				return false;
		}
	}
	else{
		for(int i=this->length-1;i>=0;i--){
			if(this->big[i] > des.big[i])
				return true;
			else if(this->big[i] < des.big[i])
				return false;
		}
	}
	return false;
}
bool bignum::operator>(const bignum &des){
	if(!this->is_negative && des.is_negative) return true;
	else if(this->is_negative && !des.is_negative) return false;
	
	if(this->length > des.length) return true;
	else if(this->length < des.length) return false;
	puts("here");
	if(!this->is_negative && !des.is_negative){
		for(int i=this->length-1;i>=0;i--){
			if(this->big[i] > des.big[i])
				return true;
			else if(this->big[i] < des.big[i])
				return false;
		}
	}
	else{
		for(int i=this->length-1;i>=0;i--){
			if(this->big[i] < des.big[i])
				return true;
			else if(this->big[i] > des.big[i])
				return false;
		}
	}
	return false;
}

int main(){
	bignum A;
	bignum B;
	
	A.read(); //input
	B.read(); //input
	
	bignum C;
	C=A-B; //minus
	C.print();
	
//	bignum D;
//	D=A+B; //plus
//	D.print();
	
	return 0;
}
