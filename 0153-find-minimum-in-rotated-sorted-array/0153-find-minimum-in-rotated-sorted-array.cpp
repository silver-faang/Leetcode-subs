class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1,n=h+1;
        int ans=INT_MAX;
        while(l<=h){
            int md=(l+h)>>1;
            if(nums[l]<=nums[h]){
                ans=min(ans,nums[l]);
                break;
            }
            if(nums[md]>=nums[l]){ans=min(ans,nums[l]);
             l=md+1;}
            else{
            ans=min(ans,nums[md]); h=md-1; }
        }
        return ans;
    }
};