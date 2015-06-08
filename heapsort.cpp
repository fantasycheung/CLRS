#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define PARENT(i) (i / 2)
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void max_heapify(int A[], int index, int heap_size){
	int l = LEFT(index);
	int r = RIGHT(index);
	int largest = 0;
	if(l <= heap_size && A[l-1] > A[index-1])
		largest = l;
	else
		largest = index;
	if(r <= heap_size && A[r-1] > A[largest-1])
		largest = r;
	if(largest != index){
		swap(A[largest-1],A[index-1]);
		max_heapify(A,largest,heap_size);
	}
}
void build_max_heap(int A[],int length){
	int heap_size = length;
	for(int i = length/2;i>=1;i--){
		max_heapify(A,i,heap_size);
	}
}
void heapsort(int A[],int length){
	build_max_heap(A,length);
	int heap_size = length;
	for(int i = length;i>=2;i--){
		swap(A[i-1],A[1-1]);
		heap_size = heap_size - 1;
		max_heapify(A,1,heap_size);
	}
}
int main(){
	int A[10];
	srand(time(0));
	for(int i = 0;i<10;i++)
		A[i] = rand()%200+1;
	for(auto i : A)cout<<i<<" ";
	cout<<endl;
    heapsort(A,10);
    for(auto i : A)cout<<i<<" ";
    cout<<endl;	
	return 0;
}