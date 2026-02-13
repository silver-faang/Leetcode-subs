class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n=intervals.size();
        int i=0,j=0;
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merge={intervals[0]};
        while(i<n){
            if(merge[j][1]>=intervals[i][0]){
                if(merge[j][1]>=intervals[i][1])
                    i++;
                else
                {
                    merge[j][1]=intervals[i][1];
                    i++;
                }
            }
            else{
                merge.push_back({intervals[i][0],intervals[i][1]});
                i++;
                j++;
            }
        }
        return merge;
        
    }
};