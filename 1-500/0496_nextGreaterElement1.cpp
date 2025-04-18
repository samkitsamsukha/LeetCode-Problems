/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

 

Constraints:

    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 104
    All integers in nums1 and nums2 are unique.
    All the integers of nums1 also appear in nums2.

 
Follow up: Could you find an O(nums1.length + nums2.length) solution?
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        for(int i = 0; i<a.size(); i++){
            for(int j = 0; j<b.size(); j++){
                if(b[j]==a[i]){
                    bool flag = true;
                    for(int k = j+1; k<b.size() && flag; k++){
                        if(b[k]>b[j]){
                            ans.push_back(b[k]);
                            flag = false;
                        }
                    }
                    if(flag){
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;
    }
};

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        stack<int> st;
        vector<int> g(b.size(), -1);
        for (int i = b.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= b[i]) {
                st.pop();
            }
            if (!st.empty()) {
                g[i] = st.top();
            }
            st.push(b[i]);
        }
        unordered_map<int, int> nextGreaterMap;
        for (int i = 0; i < b.size(); i++) {
            nextGreaterMap[b[i]] = g[i];
        }
        vector<int> result;
        for (int num : a) {
            result.push_back(nextGreaterMap[num]);
        }
        return result;
    }
};
