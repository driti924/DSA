#include<iostream>
using namespace std;

void maxHeapify(int a[], int idx, int n){
    int l=2*idx + 1;
    int r=2*idx + 2;
    int largest=idx;
    if(l<n && a[l]>a[idx]){
        largest= l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=idx){
        int temp=a[largest];
        a[largest]=a[idx];
        a[idx]=temp;
        maxHeapify(a,largest,n);
    }
}

void buildMaxHeap(int a[], int n){
    for(int i=(n/2)-1 ;i>=0; i--){
        maxHeapify(a,i,n);
    }
}

int main(){
    int arr[]={1,3,5, 7, 8};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    buildMaxHeap(arr,5);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}