/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

    Example 1:

Input: columnNumber = 1
Output: "A"

    Example 2:

Input: columnNumber = 28
Output: "AB"

    Example 3:

Input: columnNumber = 701
Output: "ZY"
 
    Constraints:

1 <= columnNumber <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while (columnNumber > 0) {
            // Decrement columnNumber as the character mapping starts from 1 for 'A'
            columnNumber--;
            s = char(columnNumber % 26 + 'A') + s;
            columnNumber /= 26;
        }
        return s;
    }
};
