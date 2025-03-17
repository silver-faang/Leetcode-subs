class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> v(501,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!v[nums[i]])
            v[nums[i]]++;
            else v[nums[i]]--;
        }
        for(int i=0;i<501;i++)
         if(v[i]) {
            return false;
         }
         return true;
    }
};