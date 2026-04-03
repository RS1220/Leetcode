class Solution {
public:
    long long maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(m, vector<long long>(3, LLONG_MIN))
        );

        // Base case
        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0]; // take
            dp[0][0][1] = 0;           // skip
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0) continue;

                for (int k = 0; k <= 2; k++) {

                    long long up   = (i > 0) ? dp[i-1][j][k] : LLONG_MIN;
                    long long left = (j > 0) ? dp[i][j-1][k] : LLONG_MIN;

                    long long best = max(up, left);

                    if (best != LLONG_MIN) {
                        // Take current cell
                        dp[i][j][k] = max(dp[i][j][k], best + coins[i][j]);
                    }

                    // Skip negative cell
                    if (coins[i][j] < 0 && k > 0) {
                        long long up2   = (i > 0) ? dp[i-1][j][k-1] : LLONG_MIN;
                        long long left2 = (j > 0) ? dp[i][j-1][k-1] : LLONG_MIN;

                        long long prev = max(up2, left2);

                        if (prev != LLONG_MIN) {
                            dp[i][j][k] = max(dp[i][j][k], prev);
                        }
                    }
                }
            }
        }

        return max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    }
};