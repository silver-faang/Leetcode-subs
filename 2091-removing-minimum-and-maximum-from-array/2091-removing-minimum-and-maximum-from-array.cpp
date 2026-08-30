class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX,mx=INT_MIN, mxi=-1,mni=-1;
        for(int i=0;i<nums.size();i++){
            if(mn>nums[i]){
                mn=min(mn,nums[i]);
                mni=i;
            }
            if(mx<nums[i]){
                mx=max(mx,nums[i]);
                mxi=i;
            }
        }
        int ans=0;
        ans=min(min(max(mxi+1,mni+1),max(n-mni,n-mxi)),min(mni+1,n-mni)+min(mxi+1,n-mxi));
        return ans; 
    }
};