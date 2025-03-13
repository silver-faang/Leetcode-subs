class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),sum=0,k=0;
        vector<int> da(n+1);
        for(int idx=0;idx<n;idx++){
            while(sum+da[idx]<nums[idx]){
                k++;
                if(k>queries.size())return -1;
                int l=queries[k-1][0],r=queries[k-1][1],val=queries[k-1][2];
                if(r>=idx){
                    da[max(l,idx)]+=val;
                    da[r+1]-=val;
                }
            }
            sum+=da[idx];
        }
        return k;
    }
};