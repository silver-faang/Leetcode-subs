class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int v=0;
        for(int i:nums){
            //cout<<i<<" i "<<(i&1)<<"\n";
            if((i&1)==0)
             v=v|i;
            //cout<<v<<" "<<(v|i)<<"\n"; 
        }
        return v;
    }
};