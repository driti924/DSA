// CPP Program for Checking double
// base Palindrome.
/*
Method 2 : This method is a little complex to understand but more advance than method 1. Rather than checking palindrome for two bases. This method generates palindrome in given range. 
Suppose we have a palindrome of the form 123321 in base k, then the first 3 digits define the palindrome. However, the 3 digits 123 also define the palindrome 12321. So the 3-digit number 123 defines a 5-digit palindrome and a 6 digit palindrome. From which follows that every positive number less than kn generates two palindromes less than k2n . This holds for every base k. Example : let’s say k = 10 that is decimal. Then for n = 1, all numbers less than 10n have 2 palindrome, 1 even length and 1 odd length in 102n. These are 1, 11 or 2, 22 or 3, 33 and so on. So, for 1000000 we generate around 2000 and for 108 we generate around 20000 palindromes. 

    Start from i=1 and generate odd palindrome of it.
    Check if this generated odd palindrome is also palindrome in base k
    If yes, then add this number to sum.
    Repeat the above three steps by changing i=i+1 until the last generated odd palindrome has crossed limit.
    Now, again start from i=1 and generate even palindrome of it.
    Check if this generated even palindrome is also palindrome in base k
    If yes, then add this number to sum.
    Repeat the above three steps by changing i=i+1 until the last generated even palindrome has crossed limit.

Below is the implementation of the above approach :  
*/
#include <bits/stdc++.h>
using namespace std;
 
// generates even and odd palindromes
int makePalindrome(int n, bool odd)
{
    int res = n;
    if (odd)
        n = n / 10;
    while (n > 0) {
        res = 10 * res + n % 10;
        n /= 10;
    }
    return res;
}
 
// Check if a number is palindrome
// in base k
bool isPalindrome(int n, int base)
{
    int reversed = 0;
    int temp = n;
    while (temp > 0) {
        reversed = reversed * base +
                   temp % base;
        temp /= base;
    }
    return reversed == n;
}
 
// function to print sum of Palindromes
void sumPalindrome(int n, int k){
     
    int sum = 0, i = 1;
     
    int p = makePalindrome(i, true);
     
    // loop for odd generation of
    // odd palindromes
    while (p < n) {
        if (isPalindrome(p, k))
            sum += p;
        i++;
     
        // cout << p << " ";
        p = makePalindrome(i, true);
    }
     
    i = 1;
 
    // loop for generation of
    // even palindromes
    p = makePalindrome(i, false);
    while (p < n) {
        if (isPalindrome(p, k))
            sum += p;
        i++;
        p = makePalindrome(i, false);
    }
     
    // result of all palindromes in
    // both bases.
    cout << "Total sum is " << sum
         << endl;
}
 
// driver code
int main()
{
    int n = 1000000, k = 2;
    sumPalindrome(n ,k);
    return 0;
}