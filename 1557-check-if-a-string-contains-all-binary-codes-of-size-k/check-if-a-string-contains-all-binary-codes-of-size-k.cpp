class Solution {
public:
    bool hasAllCodes(string s, int k) {
       if(s.size()<=1) return false;
       if(k>=s.size()) return false;
        unordered_set<string>st;
        for(int i=0;i<=s.size()-k;i++){
          int j=i+k-1;
          string ans="";
            for(int k=i;k<=j;k++){
            ans+=s[k];
            }
            st.insert(ans);
        }

       if(st.size()==(pow(2,k))) return true;
       return false;
        
    }
};