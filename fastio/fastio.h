#ifndef _FASTIO_H_
#define _FASTIO_H_
#include <cstdio>

inline char readchar();

template<class T>
inline T read(T);

template<class T>
inline bool readEOF(T&);

template<class T>
inline void write(T);


inline char readchar() {
	const int N=1048576;
	static char buf[N];
	static char *p=buf, *end=buf;
	if(p==end){
		if((end=buf+fread(buf, 1, N, stdin))==buf) return EOF;
    	p=buf;
	}
	return *p++;
}

template<class T>
inline T read(T type){
    char tmp=getchar();
	T neg=1, num=0;
	while((tmp<'0'|| tmp>'9') && tmp!='-') tmp=getchar();
	if(tmp=='-') tmp=getchar(), neg=-1;
    while (tmp>='0' && tmp<='9')
		num=(num<<3)+(num<<1)+tmp-48, tmp=getchar();
	return num*neg;
}

template<class T>
inline bool readEOF(T& num){
    char tmp;
	T neg=1;
	num=0;
	do{
		tmp=getchar();
		if(tmp==EOF) return false;
	}while((tmp<'0'|| tmp>'9') && tmp!='-');
	if(tmp=='-') tmp=getchar(), neg=-1;
    while (tmp>='0' && tmp<='9')
		num=(num<<3)+(num<<1)+tmp-48, tmp=getchar();
    return true;
}

template<class T>
inline void print(T num){
	const int N=1048576;
	char buf[N];
	int piv=0;
	if(num<0) putchar('-'), num*=-1;
	do{
		buf[piv++]='0'+(num%10), num/=10;
	}while(num>0);
	for(piv=piv-1;piv>=0;piv--)
		putchar(buf[piv]);
	putchar('\n');
}

#endif
