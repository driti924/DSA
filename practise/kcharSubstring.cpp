//Number of substrings with count of each character as k
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
 
// Returns true if all values
// in freq[] are either 0 or k.
bool check(int freq[], int k)
{
    for (int i = 0; i < MAX_CHAR; i++)
        if (freq[i] && freq[i] != k)
            return false;
    return true;
}
 
// Returns count of substrings where frequency
// of every present character is k
int substrings(string s, int k)
{
    int ans=0;;
    for(int i=0; s[i]; i++){
        int freq[MAX_CHAR]={0};
        for(int j=i;s[j];j++){
            int index= s[j]-'a';
            freq[index]++;
            if(freq[index]>k){
                break;
            }
            else{
                if(freq[index]==k && check(freq, k)){
                    ans++;
                }
            }
        }
    }
    return ans;
}
 
// Driver code
int main()
{
    string s = "aabbcc";
    int k = 2;
    cout << substrings(s, k) << endl;
 
    s = "aabbc";
    k = 2;
    cout << substrings(s, k) << endl;
}