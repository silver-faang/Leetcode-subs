class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long m=mass;
        for(int i=0;i<a.size();i++){
            if(m<a[i]) return false;
            m+=a[i];
        }
        return true;
    }
};