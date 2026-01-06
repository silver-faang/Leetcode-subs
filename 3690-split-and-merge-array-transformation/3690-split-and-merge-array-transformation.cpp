class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        queue<pair<int,vector<int>>> q;
        q.push({0,nums1});
        int n=nums1.size();
        set<vector<int>>s;
        s.insert(nums1);
        while(!q.empty()){
            vector<int> v=q.front().second;
            int c=q.front().first;
            q.pop();
            if(v==nums2) return c;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    vector<int> n=v;
                    vector<int> sub(v.begin()+i,v.begin()+j+1);
                    n.erase(n.begin()+i,n.begin()+j+1);
                    int sz=n.size();
                    for(int k=0;k<sz;k++){
                        vector<int> nxt=n;
                        nxt.insert(nxt.begin()+k,sub.begin(),sub.end());
                        if(s.find(nxt)==s.end()){
                            s.insert(nxt);
                            q.push({c+1,nxt});
                        }
                    }
                }
            }
        }
        return -1;
    }

    

};