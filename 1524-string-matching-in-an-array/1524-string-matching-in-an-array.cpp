#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool issubs(string s,string t){
        if(s.size()>t.size())return false;
        for(int i=0;i<t.size()-s.size()+1;i++){
            if(s==t.substr(i,s.size()))
             return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ss;
        for (int x= 0; x < words.size();x++) {
            for (int y = 0; y < words.size();y++) {
                if (x == y)
                    continue;
                if (issubs(words[x],words[y])) {
                    ss.push_back(words[x]);
                    break; 
                }
            }
        }

        return ss;
    }
};