class Solution {
public:
    int minMaxDifference(int num) {
     string s=to_string(num);
     string mx="";
     string mn="";
     int n=s.size();
     char ele=' ';
     for(int i=0;i<n;i++)
      if(s[i]!='9') {
        ele=s[i];
        break;
      }
    
    for(int i=0;i<n;i++){
        if(ele==s[i]) mx+='9';
        else mx+=s[i];
    }
    for(int i=0;i<n;i++){
        if(s[0]==s[i]) mn+='0';
        else mn+=s[i];
    }
    return stoi(mx)-stoi(mn);
    }
};