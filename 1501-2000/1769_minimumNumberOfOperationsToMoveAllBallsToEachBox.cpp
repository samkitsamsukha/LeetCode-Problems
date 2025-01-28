/*
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

 

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.

Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]

 

Constraints:

    n == boxes.length
    1 <= n <= 2000
    boxes[i] is either '0' or '1'.

*/

class Solution {
public:
    vector<int> minOperations(string a) {
        if(a.length()==1){
            return {0};
        }
        vector<int> ans(a.size(), 0);
        vector<int> pre(a.size());
        vector<int> suf(a.size());
        pre[0] = a[0]-'0';
        for(int i = 1; i<a.size(); i++){
            pre[i] = pre[i-1] + (a[i]-'0');
        }
        suf[a.size()-1] = a[a.size()-1]-'0';
        for(int i = a.size()-2; i>=0; i--){
            suf[i] = suf[i+1] + (a[i]-'0');
        }
        for(int i = 1; i<pre.size(); i++){
            pre[i] = pre[i]+pre[i-1];
        }
        for(int i = suf.size()-2; i>=0; i--){
            suf[i] = suf[i]+suf[i+1];
        }
        // for(int i = 0; i<pre.size(); i++){
        //     cout << pre[i] << " | ";
        // }
        // cout << endl;
        // for(int i = 0; i<suf.size(); i++){
        //     cout << suf[i] << " | ";
        // }
        ans[0] = suf[1];
        ans[ans.size()-1] = pre[ans.size()-2];
        for(int i = 1; i<ans.size()-1; i++){
            ans[i] = pre[i-1] + suf[i+1];
        }
        return ans;
    }
};