#include <iostream>
#include <fstream>
#include <vector>
#include "heap.h"

using namespace std;

template <class T>
heap<T>::heap(){
	BT.push_back(0);
	length=0;
}

template <class T>
void heap<T>::swap(const int &m, const int &n){
	T tmp;
	tmp=BT[m];
	BT[m]=BT[n];
	BT[n]=tmp;
}

template<>
void heap<int>::swap(const int &m, const int &n){
	BT[m]^=BT[n]^=BT[m]^=BT[n];
}

template <class T>
void heap<T>::insert(const T& node){
	BT.push_back(node);
	length++;
	int tmp1=length, tmp2=length;
	while(tmp1>1){
		tmp1>>=1;
		if(tmp1<1 || BT[tmp1]>BT[tmp2])
			break;
		else if(BT[tmp1]<BT[tmp2])
			swap(tmp1, tmp2);
		tmp2=tmp1;
	}
}

template <class T>
void heap<T>::sort(){
	int left, right, tmp=1;
	while(length>1){
		swap(1, length);
		length--;
		tmp=1;
		while(tmp<=length){
			left=tmp*2;
			right=tmp*2 + 1;
			if(left<=length){
				if(right<=length){
					if(BT[left]>BT[tmp] || BT[right]>BT[tmp]){
						if(BT[left]>BT[right]){
							swap(tmp, left);
							tmp=left;
						}
						else{
							swap(tmp, right);
							tmp=right;
						}
					}
					else break;
				}
				else{
					if(BT[left]>BT[tmp]){
						swap(tmp, left);
						tmp=left;
					}
					else break;
				}
			}
			else break;
		}
	}
}

template <class T>
void heap<T>::print(){
	ofstream out("output.txt");
	typename vector<T>::iterator it;
	for(it=BT.begin()+1; it!=BT.end(); ++it)
		out << *it << endl;
}

template <class T>
int heap<T>::size() const{
	return BT.size()-1;
}

template <class T>
bool heap<T>::empty(){
	return BT.begin()==BT.end()-1;
}

template class heap<int>;
template class heap<float>;
template class heap<double>;
