#include <cstdio>
#include <cstdlib>
#include <string>
#include "matrix.h"

int main(){
	Matrix A(3,3); //建構 初始化為0 
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			scanf("%lf", &A.array[i][j]);
	A.print(); //列印 
	
	Matrix B(A); //建構 初始化為A
	Matrix C(4,4);
	
	//運算子 
	C=B;
	C=-B;
	C=+B;
	C=A-B;
	C=A+B;
	C=A*B;
	C=A/B;
	
	C.inverse(); //變成反矩陣
	C.swap(0, 1); //0,1兩列互換
	return 0;
}
