class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size(),m=matrix[0].size();
        int t=0,b=n-1,l=0,r=m-1;
        while(t<=b && l<=r){
            for(int i=l;i<=r;i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            for(int j=t;j<=b;j++){
                ans.push_back(matrix[j][r]);
            }
            r--;
            if(t<=b){
                for(int k=r;k>=l;k--){
                    ans.push_back(matrix[b][k]);
                }
                b--;
            }
            if(l<=r){
                for(int x=b;x>=t;x--){
                    ans.push_back(matrix[x][l]);
                }
                l++;
            }
        }
return ans;
        }
        
    
};