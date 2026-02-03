class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums[0]>=nums[1]) return false;
        int count =0;
        for(int i=2;i<nums.size();i++){
            if(nums[i-1]==nums[i])return false;
            if((nums[i-2]-nums[i-1])*(nums[i-1]-nums[i])<0) count++;
        }
        return count==2;
    }
};