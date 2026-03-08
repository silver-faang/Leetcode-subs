class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int i=0,j=0;
        int j1=0,j2=0,ans=INT_MAX;
        while(j<2*n){
            char c1=(j%2)?'1':'0';
            char c2=(j%2)?'0':'1';
            if(s[j%n]!=c1)j1++;
            if(s[j%n]!=c2)j2++;
            while(j-i+1>n){
                char nc1=(i%2)?'1':'0';
                char nc2=(i%2)?'0':'1';
                if(s[i%n]!=nc1)j1--;
                if(s[i%n]!=nc2)j2--;
                i++;
            }
            if(j-i+1==n){
                ans=min({ans,j1,j2});
            }
            j++;
        }
        return ans;
    }
};