#ifndef _HEAP_H_
#define _HEAP_H_
#include <vector>

using namespace std;

template <class T>
class heap{
	public:
		heap();
		void insert(const T&);
		void swap(const int&, const int&);
		void print();
		void sort();
		int size() const;
		bool empty();
		
	private:
		vector<T> BT;
		int length;
};

template<>
void heap<int>::swap(const int&, const int&);


#endif
