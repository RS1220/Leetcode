class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        sort(s1.begin() , s1.end());
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;
        for(int i=0;i<=m-n;i++){
           string subString=s2.substr(i,n);
           sort(subString.begin() , subString.end());

           if(s1==subString) return true;
        }

        return false;
        
    }
};