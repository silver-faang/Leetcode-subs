#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll v=0;
        ll mx=0,mn=INT_MAX;
        for(ll i:nums){
            mx=max(mx,i);
            mn=min(mn,i);
        }
        v=k*(mx-mn);
        return v;
    }
};