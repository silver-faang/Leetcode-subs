class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> sc(n+1,0);
        for(int i=0;i<n;i++){
            if(words[i][0]=='a'||words[i][0]=='e'||words[i][0]=='i'||words[i][0]=='o'||words[i][0]=='u')
             {
                int li = words[i].size() - 1;
                if(words[i][li]=='a'||words[i][li]=='e'||words[i][li]=='i'||words[i][li]=='o'||words[i][li]=='u')
                 sc[i+1]=sc[i]+1;
                else 
                 sc[i+1]=sc[i]; 
             }
            else 
             sc[i+1]=sc[i]; 
            //cout<<sc[i+1]<<" ";  
            
        }
        //cout<<"sc\n"; 
        int m=queries.size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int v=sc[queries[i][1]+1]-sc[queries[i][0]];
            ans.push_back(v);
        }
        return ans;

    }
};