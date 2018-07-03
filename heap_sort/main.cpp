#include <iostream>
#include <vector>
#include <fstream>
#include "heap.h"

using namespace std;

int main() {
	ifstream in("out.txt");
	int tmp;
	heap<int> arr; //建構 
	while(in >> tmp){
		arr.insert(tmp); //插入 
	}
	arr.sort(); //排序 
	arr.print(); //列印
	cout << arr.size() << endl; //大小
	if(!arr.empty()) //檢查是否為空 
		puts("not empty!"); 
	return 0;
}
