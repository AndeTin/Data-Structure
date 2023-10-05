#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = nums.size();
        for(int i = 0 ; i< nums.size(); i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i] == nums[j]){
                    nums.erase(nums.begin()+j);
                    j--;
                    count--;
                }
            }
        }
        vector<int> ans;
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i] !=' '){
                ans.push_back(nums[i]);
            }
        }
        return count;
    }
};