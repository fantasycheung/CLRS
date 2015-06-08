#include <iostream>
using namespace std;

void swap(int A[], int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = A[a];
}

void swap1(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int A[2] = {2,9};
    swap1(A[0],A[1]);
    cout<<A[0]<<"  "<<A[1]<<endl;
    return 0;
}
