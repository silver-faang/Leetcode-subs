class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int s=0;
        if(n<3){
            for(int i=0;i<n;i++)
             s+=cost[i];
        }
        else{
            int i=n-1;
        for(;i>=0;i-=3){
            s+=cost[i];
            if(i-1>=0)s+=cost[i-1];
        }
        if(i>0)
        while(i--) s+=cost[i];
        }
        return s;
    }
};