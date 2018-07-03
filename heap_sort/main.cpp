#include <iostream>
#include <vector>
#include <fstream>
#include "heap.h"

using namespace std;

int main() {
	ifstream in("out.txt");
	int tmp;
	heap<int> arr;
	while(in >> tmp){
		arr.insert(tmp);
	}
	arr.sort();
	arr.print();
	return 0;
}
