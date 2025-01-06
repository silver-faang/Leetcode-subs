class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> ans(n,0);
        int sc=0,ss=0,pc=0,ps=0;
        for(int i=0;i<n;i++){
            ans[i]=pc*i-ps;
            if(boxes[i]=='1'){
                pc++;
                ps+=i;
            }
        }
        for(int i=n-1;i>=0;i--){
            ans[i]+=ss-sc*i;
            if(boxes[i]=='1'){
                sc++;
                ss+=i;
            }
        }
        return ans;

    }
};