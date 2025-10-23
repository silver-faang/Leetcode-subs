class Solution {
public:
    bool hasSameDigits(string s) {
        int n =s.size();
        while(n!=2){
            string s1="";
           for(int i=0;i<n-1;i++){
            s1+=(s[i]-'0'+s[i+1]-'0')%10+'0';
           }
           n-=1;
           s=s1;
        }
        return (s[0]==s[1]);
    }
};