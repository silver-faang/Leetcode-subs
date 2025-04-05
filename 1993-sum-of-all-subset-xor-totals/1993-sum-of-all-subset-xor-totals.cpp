class Solution {
    private:
    int xorrecur(vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()) return currentXOR;
        int withElement = xorrecur(nums, index + 1, currentXOR ^ nums[index]);
        int withoutElement = xorrecur(nums, index + 1, currentXOR);
        return withElement + withoutElement;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return xorrecur(nums,0,0);
    }
};