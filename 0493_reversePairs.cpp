/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

    Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

    Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 
    Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while((left <= mid) && (right <= high)){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i<=high; i++){
            nums[i] = temp[i-low];
        }
    }

    int countPairs(vector<int>& nums, int low, int mid, int high){
        int count = 0;
        int right = mid+1;
        for(int i = low; i<=mid; i++){
            while(right<=high && nums[i]>2*(long long)nums[right]){
                right++;
            }
            count = count + (right - (mid + 1));
        }
        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high){
        int count = 0;
        if(low>=high){
            return count;
        }
        int mid = (low+high)/2;
        count = count+mergeSort(nums, low, mid);
        count = count+mergeSort(nums, mid+1, high);
        count = count+countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};