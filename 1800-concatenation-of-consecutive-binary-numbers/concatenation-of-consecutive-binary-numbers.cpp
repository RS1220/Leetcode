class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod = 1000000007;
        long long result = 0;

        for(int i = 1; i <= n; i++) {

            int digit = floor(log2(i)) + 1;   // fix precision

            result = ((result << digit) % mod + i) % mod;
        }

        return (int)result;
    }
};