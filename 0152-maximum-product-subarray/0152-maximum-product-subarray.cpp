class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p=1,s=1,ans=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++){
            if(!p) p=1;
            if(!s) s=1;
            p=p*nums[i];
            s=s*nums[n-i-1];
            
            ans=max(ans,max(p,s));
        }
        return ans;
    }
};