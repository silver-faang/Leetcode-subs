#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll s=0;
        int mnv=INT_MAX;
        int c=0;
        for(auto r:matrix){
            for (auto itr:r){
                s+=abs(itr);
                if(itr<0)c++;
                mnv=min(mnv,abs(itr));
            }
            
        }
        if(c%2) s-=2*mnv;
        return s;
    }
};