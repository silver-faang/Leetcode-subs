class Solution {
public:
    int total=0;
    bool isFound=false;
    vector<vector<int>>dp;
    bool fn(vector<int>& nums,int idx,int sum){
        if(2*sum==total)return true;
        if(idx==nums.size())return false;
        if(dp[idx][sum]!=-1)return dp[idx][sum];

        bool pick=fn(nums,idx+1,sum+nums[idx]);
        bool nonpick=fn(nums,idx+1,sum);

        return dp[idx][sum]= pick || nonpick;
    }
    bool canPartition(vector<int>& nums) {
        for(auto num:nums){
            total+=num;
        }
        dp.resize(nums.size(),vector<int>(total+1,-1));
        return fn(nums,0,0);
    }

};