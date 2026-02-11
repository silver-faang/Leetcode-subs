class Solution {
public:
    int maxArea(vector<int>& height) {
        int  i=0, j=height.size()-1;
        int mxa=0;
        while(i<j){
            mxa=max(mxa,((j-i)*min(height[i],height[j])));
            if(height[i]<height[j])i++;
            else j--;
        }
        return mxa;
    }
};