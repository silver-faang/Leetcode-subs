class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            long long s=0;
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                s+=nums[j];
                long long ng=((2*(long long)nums[j])%k+k)%k;
                st.insert(ng);
                long long ss=((s%k)+k)%k;
                if(ss==0 || st.find(ss)!=st.end()) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};