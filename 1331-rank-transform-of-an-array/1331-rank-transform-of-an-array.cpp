class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       map<int,vector<int>> numToIdx;
       for(int i=0;i<arr.size();i++)
        numToIdx[arr[i]].push_back(i);
        int rank=1;
        for(auto e:numToIdx){
            for(int idx:e.second)
             arr[idx]=rank;
            rank++; 
        }
        return arr;
    }
};