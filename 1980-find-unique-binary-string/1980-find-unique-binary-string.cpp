class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string> s;

        string t="";
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            t+='0';
        }
        
        int i=0,f=0,j=0;
        while(i<pow(2,n)){
            if(s.find(t)==s.end())
            {return t;
             break;}
            t[j]='0'+f;
            if(f)j++;
            f=1-f;
            i++;
        }
        return t;
    }
};