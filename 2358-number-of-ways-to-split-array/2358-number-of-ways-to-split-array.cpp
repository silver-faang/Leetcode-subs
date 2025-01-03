class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long s=0;
        for(int i=0;i<n;i++)s+=nums[i];
        long long p=0;
        int c=0;
        for(int i=0; i<n-1; i++){
            p+=nums[i];
            c+=(p>=s-p);
        }
        return c;
    }
};