#include<iostream>
using namespace std;

void countsort(int arr[], int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int countarr[10]={0};
    /*for(int i=0;i<max;i++){
        countarr[i]=0;
    }*/
    for(int i=0;i<n;i++){
        countarr[arr[i]]++;
    }
    for(int i=1;i<=max;i++){
        countarr[i]+=countarr[i-1];
    }
    int sortedArr[n];
    for(int i=n-1;i>=0;i--){
        int temp = --countarr[arr[i]];
        sortedArr[temp]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=sortedArr[i];
    }
    //return sortedArr;
}

int main(){
    int arr[]={2,3,6,5,1,1,6,6,4};
    countsort(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}