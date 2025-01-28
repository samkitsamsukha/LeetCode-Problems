/*
Given two positive integers num1 and num2, find the positive integer x such that:

    x has the same number of set bits as num2, and
    The value x XOR num1 is minimal.

Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

 

Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.

 

Constraints:

    1 <= num1, num2 <= 109


*/

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int sb = 0;
        while(num2>0){
            if(num2%2 == 1){
                sb++;
            }
            num2 = num2/2;
        }
        cout << sb << endl;
        string s = "";
        while(num1>0){
            s+=(num1%2)+'0';
            num1 = num1/2;
        }
        reverse(s.begin(), s.end());
        if (s.length() < 32) {
            s.insert(0, 32 - s.length(), '0');
        }
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1'){
                if(sb>0){
                    sb--;
                }
                else{
                    s[i] = '0';
                }
            }
        }
        if(sb>0){
            for(int i = s.length()-1; i>=0 && sb>0; i--){
                if(s[i] == '0'){
                    s[i] = '1';
                    sb--;
                }
            }
        }
        long long int m = 1;
        long long int ans = 0;
        for(int i = s.length()-1; i>=0; i--){
            ans = ans + m*(s[i]-'0');
            m*=2;
        }
        return ans;
    }
};