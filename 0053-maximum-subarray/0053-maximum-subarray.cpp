class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s1=INT_MIN,s2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s2+=nums[i];
            if(s2>s1)
                s1=s2;
            if(s2<0)
                s2=0;
        }
        return s1;
    }
};