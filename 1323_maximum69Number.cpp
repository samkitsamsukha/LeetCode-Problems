/*
You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

    Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.

    Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.

    Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
 
    Constraints:

1 <= num <= 104
num consists of only 6 and 9 digits.
*/

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        while(num>0){
            int d = num%10;
            arr.push_back(d);
            num = num/10;
        }
        bool flag = true;
        for(int i = arr.size()-1; i>=0 && flag == true; i--){
            if(arr[i] == 6){
                arr[i] = 9;
                flag = false;
            }
        }
        int m = 1;
        int newnum = 0;
        for(int i = 0; i<arr.size(); i++){
            newnum = newnum + m*arr[i];
            m = m * 10;
        }
        return newnum;
    }
};