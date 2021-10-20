#include <bits/stdc++.h>
using namespace std;
 
// A recursive function to replace all 0s
// with 5s in an input number It doesn't
// work if input number itself is 0.
int convert0To5Rec(int num)
{
    // Base case for recursion termination
    if (num == 0)
        return 0;
 
    // Extraxt the last digit and
    // change it if needed
    int digit = num % 10;
    if (digit == 0)
        digit = 5;
 
    // Convert remaining digits and
    // append the last digit
    return convert0To5Rec(num / 10) * 10 + digit;
}
 
// It handles 0 and calls convert0To5Rec()
// for other numbers
int convert0To5(int num)
{
    if (num == 0)
        return 5;
    else
        return convert0To5Rec(num);
}
 
// Driver code
int main()
{
    int num = 10120;
    cout << convert0To5(num);
    return 0;
}
 