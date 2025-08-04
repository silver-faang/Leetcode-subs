class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int s=0,mx=0,n=fruits.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[fruits[i]]++;
            while(mp.size()>2){
                mp[fruits[s]]--;
                if(mp[fruits[s]]==0) mp.erase(fruits[s]);
                s++;
            }
            mx=max(mx,i-s+1);
        }
        return mx;
    }
};