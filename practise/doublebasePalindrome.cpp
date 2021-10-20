#include <bits/stdc++.h>
using namespace std;
 
// converts number to base k by changing
// it into string.
string integer_to_string(int n, int base)
{
    string str;
    while (n > 0) {
        int digit = n % base;
        n /= base;
        str.push_back(digit + '0');
    }
    return str;
}
 
// function to check for palindrome
int isPalindrome(int i, int k)
{
    int temp = i;
     
    // m stores reverse of a number
    int m = 0;
    while (temp > 0) {
        m = temp % 10 + m * 10;
        temp /= 10;
    }
     
    // if reverse is equal to number
    if (m == i) {
     
        // converting to base k
        string str = integer_to_string(i, k); //either of i and m will work
        string str1 = str;
     
        // reversing number in base k
        reverse(str.begin(), str.end());
     
        // checking palindrome in base k
        if (str == str1) {
            return i;
        }
    }
    return 0;
}
 
// function to find sum of palindromes
void sumPalindrome(int n, int k){
     
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += isPalindrome(i, k);
    }
    cout << "Total sum is " << sum;
}
 
// driver function
int main()
{
    int n = 100;
    int k = 2;
 
    sumPalindrome(n, k);
    return 0;
}