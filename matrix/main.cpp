#include <cstdio>
#include <cstdlib>
#include <string>
#include "matrix.h"

int main(){
	Matrix A(3,3); //�غc ��l�Ƭ�0 
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			scanf("%lf", &A.array[i][j]);
	A.print(); //�C�L 
	
	Matrix B(A); //�غc ��l�Ƭ�A
	Matrix C(4,4);
	
	//�B��l 
	C=B;
	C=-B;
	C=+B;
	C=A-B;
	C=A+B;
	C=A*B;
	C=A/B;
	
	C.inverse(); //�ܦ��ϯx�}
	C.swap(0, 1); //0,1��C����
	return 0;
}
