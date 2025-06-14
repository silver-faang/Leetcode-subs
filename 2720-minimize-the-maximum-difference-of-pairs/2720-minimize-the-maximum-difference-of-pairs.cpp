class Solution {
public:
    int cpairs(int t,vector<int>& nums){
        int i=0,c=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=t){
                c++;
                i++;
            }
            i++;
        }
        return c;
    }
    int minimizeMax(vector<int>& nums, int p) {
           sort(nums.begin(), nums.end());
           int n=nums.size();
           int l=0,r=nums[n-1]-nums[0];
           while(r>l){
            int md=l+(r-l)/2;
            if(cpairs(md,nums)>=p){
                r=md;
            }
            else l=md+1;
           }
           return l;
    }
};