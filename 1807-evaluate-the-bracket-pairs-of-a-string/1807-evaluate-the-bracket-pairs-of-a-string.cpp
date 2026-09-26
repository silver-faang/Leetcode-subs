class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;
        for(auto itr:knowledge){
            mp[itr[0]]=itr[1];
        }
        int n=s.size(),f=0;
        string sf,t;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                f=1;
                t="";
            }
            else if(!f && s[i]!=')')
             sf+=s[i];
            else if(f && s[i]!=')')
              t+=s[i];
            else {
                if(mp.find(t)!=mp.end())
                 sf+=mp[t];
                else sf+="?";
                f=0; 
            }  
        }
        return sf;
        
    }
};