/*
Given an integer num, return a string of its base 7 representation.

    Example 1:

Input: num = 100
Output: "202"

    Example 2:

Input: num = -7
Output: "-10"

    Constraints:

-107 <= num <= 107
*/

#include<bits/stdc++.h>
class Solution {
public:
    string convertToBase7(int num) {
        int temp = abs(num);
        string s="";
        if(num == 0){
            return "0";
        }
        while(temp>0){
            int d = temp % 7;
            s = s + ('0' + d);
            temp = temp / 7;
        }
        temp = abs(num);
        if(temp != num){
            s = s + '-';
        }
        reverse(s.begin(), s.end());
        return s;
    }
};