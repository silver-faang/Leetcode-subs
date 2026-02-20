class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto n:nums)
         s.insert(n);
        unordered_map<int,int> mp;
        int n=nums.size();
        int ans=0;
        for(int no:s){
            int l=0,r=0;
            if(mp.find(no-1)!=mp.end()){
                l=mp[no-1];
            }
            if(mp.find(no+1)!=mp.end()){
                r=mp[no+1];
            }
            int v=1+l+r;
            mp[no-l]=v;
            mp[no+r]=v;
            ans=max(ans,v);
        }
        return ans;
    }
};