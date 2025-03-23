class Solution {
public:
    void dfs(string word,string target,vector<string>& seq,unordered_map<string,int> & depth,vector<vector<string>> &ans ){
        if(word==target)
         {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
          return;}
        int step=depth[word];
        for(int i=0;i<word.size();i++){
            char org=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(depth.count(word) && depth[word]+1==step){
                    seq.push_back(word);
                    dfs(word,target,seq,depth,ans);
                    seq.pop_back();
                }
            }
            word[i]=org;
        }  
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> depth;
        vector<vector<string>> ans;
        unordered_set<string> wrdst(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        depth[beginWord]=1;
        wrdst.erase(beginWord);
        while(!q.empty()){
            string w=q.front();
            q.pop();
            int step=depth[w];
            if(w==endWord) break;
            for(int i=0;i<w.size();i++){
                char org=w[i];
                for(char ch='a';ch<='z';ch++){
                    w[i]=ch;
                    if(wrdst.count(w)){
                        q.push(w);
                        wrdst.erase(w);
                        depth[w]=step+1;
                    }
                }
                w[i]=org;
            }
        }
        vector<string> seq{endWord};
        dfs(endWord,beginWord,seq,depth,ans);
        return ans;
    }
};