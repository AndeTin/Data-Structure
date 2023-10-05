#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        int count = nums.size(); ;
        for(int i = 0;i<nums.size()-1;i++){
            for(int j=i;j<nums.size()-1;j++){
                if(nums[i]==nums[j+1] && nums[i]!=' '){
                    nums.erase(nums.begin()+j+1);
                    count--;
                }
            } 
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=' '){
                ans.push_back(nums[i]);
            }
        }
        for(int i = count;size.of(ans)>i;i++){
            ans.push_back(' ');
        }
        nums = ans;
        cout<<count<<", "<<"nums = "<<nums<<endl;
    }
};
int main(){
    solution s;

    removeDuplicates(nums);
}