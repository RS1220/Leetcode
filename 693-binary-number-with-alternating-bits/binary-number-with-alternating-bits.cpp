class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long result=n^(n>>1);

        if((result & (result+1))==0 ) return true;
        return false;
        
    }
};