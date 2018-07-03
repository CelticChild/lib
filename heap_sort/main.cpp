#include <iostream>
#include <vector>
#include <fstream>
#include "heap.h"

using namespace std;

int main() {
	ifstream in("out.txt");
	int tmp;
	heap<int> arr; //�غc 
	while(in >> tmp){
		arr.insert(tmp); //���J 
	}
	arr.sort(); //�Ƨ� 
	arr.print(); //�C�L
	cout << arr.size() << endl; //�j�p
	if(!arr.empty()) //�ˬd�O�_���� 
		puts("not empty!"); 
	return 0;
}
