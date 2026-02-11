class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int l=0;
        for(int i=0;i<nums.size();i++){
            auto odd=unordered_map<int,int>();
            auto even=unordered_map<int,int>();
            for(int j=i;j<nums.size();j++){
                auto& c=(nums[j]&1)?odd:even;
                c[nums[j]]++;
                if(odd.size()==even.size()){
                    l=max(l,j-i+1);
                }
            }
        }
        return l;
    }
};