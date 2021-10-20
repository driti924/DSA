#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    return;
}
int partition(int arr[], int l, int r){
    int pi=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pi){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, r);
    return i+1;
}
void quicksort(int arr[], int l, int r){
    if(l<r){
        int pivot=partition(arr,l,r);
        quicksort(arr,l,pivot-1);
        quicksort(arr, pivot+1,r);
    }
}

int main(){
    int arr[]={2,3,5,1,6,4};
    quicksort(arr,0,5); //give r=n-1 
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}