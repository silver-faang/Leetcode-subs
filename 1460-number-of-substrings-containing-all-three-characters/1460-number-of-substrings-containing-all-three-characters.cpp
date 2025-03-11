class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int c=0;
        int l=0;
        unordered_map<char,int> cf={{'a',0},{'b',0},{'c',0}};
        for(int r=0;r<n;++r){
            cf[s[r]]++;
            while(cf['a']>0 && cf['b']>0 && cf['c']>0){
                c+=n-r;
                cf[s[l]]--;
                l++;
            }
        }
        return c;
    }
};