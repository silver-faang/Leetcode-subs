class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        unordered_map<int,int> mp;
        int n=fruits.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int v=1;
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j]){
                    baskets[j]=0;
                    v=0;
                    break;
                }
            }
            ans+=v;
        }
        return ans;
    }
};