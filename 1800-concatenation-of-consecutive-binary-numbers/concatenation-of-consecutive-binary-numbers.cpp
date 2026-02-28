class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod = 1000000007;
        long long result = 0;
        int digit=0;

        for(int i = 1; i <= n; i++) {

             
            if((i & i-1)==0) digit++;
            result = ((result << digit) % mod + i) % mod;
        }

        return (int)result;
    }
};