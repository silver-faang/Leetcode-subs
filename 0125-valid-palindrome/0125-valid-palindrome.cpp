class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int start=0,end=n-1;
        while(start<end){
            if(!isalnum(s[end])){end--; continue;}
            if(!isalnum(s[start])){start++;continue;} 
            if(tolower(s[start])!=tolower(s[end])) return false;
            else {
                start++;
                end--;
            }            
        }
        return true;
    }
};