/*
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

    Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.

    Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 
    Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length
*/

#include<bits/stdc++.h>
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        if(nums.size() == k){
            return 0;
        }
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        vector<int> frequencies;
        for(auto it : mpp){
            frequencies.push_back(it.second);
        }
        sort(frequencies.begin(), frequencies.end());
        int unique = frequencies.size();
        for(auto it : frequencies){
            if(k>=it){
                k = k-it;
                unique--;
            }
            else{
                break;
            }
        }
        return unique;
    }
};

/*
    Intuition
Creating a hashmap of elements along with their frequency and then removing the lowest frequency elements first, decreasing the unique elements counter.

    Approach
- Creating a map and storing all frequencies in it.
- Create a vector called frequencies where we store all the values of map, without keys. Then sort the vector to get lowest frequency values at the beginning.
- Number of unique elements in the vector is equal to the length of frequencies vector. Keep iterating through the frequencies vector and subtract the value from k as long as possible.

    Complexity
Time complexity:
O(NlogN
Space complexity:
O(N)
*/