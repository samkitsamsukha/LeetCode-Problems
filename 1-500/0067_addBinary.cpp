/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

 

Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.

*/

class Solution {
public:
    string addBinary(string a, string b) {
        char carry = '0';
        vector<char> result;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int k = 0;
        int al = a.length();
        int bl = b.length();
        while(k<al && k<bl){
            if(a[k]=='0' && b[k]=='0'){
                if(carry=='0'){
                    result.push_back('0');
                }
                else if(carry=='1'){
                    result.push_back('1');
                    carry='0';
                }
            }
            else if(a[k]=='0' && b[k]=='1'){
                if(carry=='0'){
                    result.push_back('1');
                }
                else if(carry=='1'){
                    result.push_back('0');
                    carry='1';
                }
            }
            else if(a[k]=='1' && b[k]=='0'){
                if(carry=='0'){
                    result.push_back('1');
                }
                else if(carry=='1'){
                    result.push_back('0');
                    carry='1';
                }
            }
            else if(a[k]=='1' && b[k]=='1'){
                if(carry=='0'){
                    result.push_back('0');
                    carry='1';
                }
                else if(carry=='1'){
                    result.push_back('1');
                    carry='1';
                }
            }
            k++;
        }
        while(k<al){
            if(a[k]=='0' && carry=='0'){
                result.push_back('0');
            }
            else if(a[k]=='0' && carry=='1'){
                result.push_back('1');
                carry='0';
            }
            else if(a[k]=='1' && carry=='0'){
                result.push_back('1');
            }
            else if(a[k]=='1' && carry=='1'){
                result.push_back('0');
                carry='1';
            }
            k++;
        }
        while(k<bl){
            if(b[k]=='0' && carry=='0'){
                result.push_back('0');
            }
            else if(b[k]=='0' && carry=='1'){
                result.push_back('1');
                carry='0';
            }
            else if(b[k]=='1' && carry=='0'){
                result.push_back('1');
            }
            else if(b[k]=='1' && carry=='1'){
                result.push_back('0');
                carry='1';
            }
            k++;
        }
        if(carry=='1'){
            result.push_back('1');
        }
        string s="";
        for(int i = result.size()-1; i>=0; i--){
            // cout << result[i];
            s = s+result[i];
        }

        return s;
    }
};