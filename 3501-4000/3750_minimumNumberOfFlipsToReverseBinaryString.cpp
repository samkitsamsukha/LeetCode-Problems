/*
You are given a positive integer n.

Let s be the binary representation of n without leading zeros.

The reverse of a binary string s is obtained by writing the characters of s in the opposite order.

You may flip any bit in s (change 0 → 1 or 1 → 0). Each flip affects exactly one bit.

Return the minimum number of flips required to make s equal to the reverse of its original form.

 

Example 1:

Input: n = 7

Output: 0

Explanation:

The binary representation of 7 is "111". Its reverse is also "111", which is the same. Hence, no flips are needed.

Example 2:

Input: n = 10

Output: 4

Explanation:

The binary representation of 10 is "1010". Its reverse is "0101". All four bits must be flipped to make them equal. Thus, the minimum number of flips required is 4.

 

Constraints:

    1 <= n <= 109


*/

class Solution {
public:
    string convertToBinary(int n){
        string s = "";
        while(n>0){
            if(n%2==0) s = s+"0";
            else s = s+"1";
            n = n/2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    int minimumFlips(int n) {
        string b = convertToBinary(n);
        string r = b;
        reverse(b.begin(), b.end());
        int power = 0;
        int ans = 0;
        for(int i = b.length()-1; i>=0; i--){
            if(b[i] != r[i])    {
                ans++;
            }
        }
        return ans;
    }
};