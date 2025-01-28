#include<iostream>
#include<vector>
using namespace std;
/* FOR SORTED ARRAYS
vector<int> twoSum(vector<int>& nums, int target){

    int size = nums.size();
    // cout << size << endl;
    vector<int> ans(2, 0);
    int a = 0;
    int b = size - 1;
    while(a < b){
        int sum = nums[a] + nums[b];
        //cout << a << " " << b << endl; 
        //cout << sum << endl;
            if(sum == target){
            // cout << a << " " << b << endl;
            ans[0] = a;
            ans[1] = b;
            return ans;
        }
        else if(sum < target){
            a++;
        }
        else if(sum > target){
            b--;
        }
    }
    return ans;
}
*/
//BRUTE-FORCE
vector<int> twoSum(vector<int>& nums, int target){
    vector<int> ans(2, 0);
    for(int i=0; i<nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] + nums[j] == target){
                ans[0] = i;
                ans[1] = j;
            }
        }
    }
    return ans;
}

int main(){

    vector<int> nums = {3, 2, 4};
    int target = 6;
    
    vector<int> result = twoSum(nums, target);

    // Print the elements of the result vector
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}