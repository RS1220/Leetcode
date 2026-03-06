class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        bool flag =false;
        int idx=0; 
       for(int i=1;i<s.size();i++){
        if(s[i]=='0'){
           flag=true;
           idx=i;
           break;
        } 
       }
       if(idx==n-1 || idx==0) return true;
       for(int i=idx+1;i<n;i++){
        if(s[i]=='1') return false;
       }
       return true;
    }
};