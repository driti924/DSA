//Find Excel column number from column title
#include <bits/stdc++.h>
 
using namespace std;
 
// Returns resul when we pass title.
int titleToNumber(string s)
{
    // This process is similar to
    // binary-to-decimal conversion
    int result = 0;
    for (const auto& c : s)
    {
        result *= 26;
        result += c  - 'A' + 1;
    }
 
    return result;
}
string titleToString(int s){
    string res="";
    while(s){
        if(s%26==0){
            res+='Z';
            s=s/(26) -1;//this is important
        } 
        else{
            res+=(s%26 + 'A'-1);
            s/=26;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
 
// Driver function
int main()
{
    cout<<titleToNumber("CDA") << endl;
    cout<<titleToString(52)<<endl;
    return 0;
}