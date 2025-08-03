class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> p(31,-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int idx=i;
            for(int b=0;b<31;b++){
                if(!(nums[i] & 1<<b)){
                    if(p[b]!=-1)
                     idx=max(idx,p[b]);
                }
                else p[b]=i;
            }
            ans[i]=idx-i+1;
        }
        return ans;
    }
};