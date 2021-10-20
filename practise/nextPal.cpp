#include <iostream>
using namespace std;
void makePal(int a[], int n){
    int mid=n/2;
    int i=mid-1;
    int j= n%2==0 ? mid : mid+1;
    while(i>=0 && a[j]==a[i]){
        i--;j++;
    }

    bool leftsmaller=0;
    if(i<0 || a[j]>a[i]){
        leftsmaller=true;
    }
    while(i>=0){
        a[j]=a[i];
        i--;
        j++;
    }
    if(leftsmaller){
        int carry=1;
        i=mid-1;
        if(n%2==1){//odd case
            a[mid]+=carry;
            carry=a[mid]/10;
            a[mid]=a[mid]%10;
            j=mid+1;
        }
        else{//even
            j=mid;
        }
        while(i>=0){
            a[i]+=carry;
            carry=a[i]/10;
            a[i]=a[i]%10;
            a[j]=a[i];
            j++;i--;
        }
    }
}
string solve(string A) {
    int n=A.length();
    bool flag=1;
    for(int i=0;i<n;i++){
        if(A[i]!='9'){
            flag=0;
            break;
        }
    }
    if(flag){
        string s="1";
        for(int i=0;i<n-1;i++){
            s+='0';
        }
        s+='1';
        return s;
    }
    //
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=A[i]-'0';
    }
    makePal(a, n);

    /*for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    */

    string ans="";
    for(int i=0;i<n;i++){
        ans+=(a[i]+'0');
    }
    return ans;

}
// Driver code
int main()
{
    /*int num[] = { 7,4 };
 
    int n = sizeof(num) / sizeof(num[0]);
 
    generateNextPalindrome(num, n);
    */
    cout<<solve("83499469")<<endl;
 
    return 0;
}
 
// This code is contributed by rohan07