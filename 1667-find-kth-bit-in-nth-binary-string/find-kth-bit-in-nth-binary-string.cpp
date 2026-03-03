class Solution {
public:
    string reverseInvert(string s){
        reverse(s.begin() , s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        if (k==1) return '0';
        string sold="0";
        for(int i=2;i<=n;i++){
            string snew=sold+'1'+reverseInvert(sold);
            if(snew.size()>=k){
                return snew[k-1];
            } 
            sold=snew;
        }

        return '0';
        
    }
};