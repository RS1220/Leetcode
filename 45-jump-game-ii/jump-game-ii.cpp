class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1e9);

        // last index needs 0 jumps
        dp[n - 1] = 0;

        // move from back to front
        for(int i = n - 2; i >= 0; i--) {

            for(int j = 1; j <= nums[i]; j++) {

                if(i + j < n) {
                    dp[i] = min(dp[i], 1 + dp[i + j]);
                }
            }
        }

        return dp[0];
    }
};