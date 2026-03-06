/*
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

 

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.

Example 2:

Input: s = "110"
Output: true

 

Constraints:

    1 <= s.length <= 100
    s[i]​​​​ is either '0' or '1'.
    s[0] is '1'.
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool foundZero = false;
        for(int i = 0; i<s.length(); i++){
            if(foundZero){
                if(s[i]=='1'){
                    return false;
                }
            }
            if(!foundZero){
                if(s[i]=='0'){
                    foundZero = true;
                }
            }
        }
        return true;
    }
};