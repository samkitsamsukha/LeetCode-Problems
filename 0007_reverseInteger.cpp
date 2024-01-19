/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

    Example 1:

Input: x = 123
Output: 321

    Example 2:

Input: x = -123
Output: -321

    Example 3:

Input: x = 120
Output: 21
 
    Constraints:

-231 <= x <= 231 - 1
*/

#include<iostream>
using namespace std;

int reverse(int x) {
    int rev_sum = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        if (rev_sum > INT_MAX / 10 || (rev_sum == INT_MAX / 10 && digit > 7)) {
            return 0;
        }
        if (rev_sum < INT_MIN / 10 || (rev_sum == INT_MIN / 10 && digit < -8)) {
            return 0;
        }
        rev_sum = rev_sum * 10 + digit;
    }
    return rev_sum;
}

int main(){
    int n;
    cin >> n;
    cout << reverse(n);
}

/*
Approach

The main catch in this problem was dealing with size of reversed sum. For the 32 bit range, tha maximum value is +2147483647 so we constantly keep a check if the reverse goes beyond the INT_MAX value.
    if (rev_sum > INT_MAX / 10 || (rev_sum == INT_MAX / 10 && digit > 7))
The minimum value for 32 bits is -2147483648. Hence another condition is set up for the same.
    if (rev_sum < INT_MIN / 10 || (rev_sum == INT_MIN / 10 && digit < -8))

Complexity
    Time complexity: O(log10(n))
    Space complexity: O(1)
*/