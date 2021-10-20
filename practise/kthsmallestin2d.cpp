#include <bits/stdc++.h>
using namespace std;
 
int find(int arr[][4],int n, int i, int j,int k){
    if(k-1==0){
        return arr[i][j];
    }

    int right=find(arr,n,i,j+1,k-1);
    int down=find(arr,n, i+1, j, k-1);
    
    return min(down,right);
}

int main()
{
    int a[4][4]={{ 10, 20, 30, 40 },
                    { 15, 25, 35, 45 },
                    { 25, 29, 37, 48 },
                    { 32, 33, 39, 50 } };
    int k=7;
    if(k>16){
        cout<<-1<<endl;
    }
    else{
        cout<<find(a,4,0,0,k)<<endl;
    }
    return 0;
}
 