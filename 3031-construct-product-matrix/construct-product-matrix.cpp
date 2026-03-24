class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 12345;

        vector<vector<int>> p(n, vector<int>(m));
        vector<vector<long long>> prefixPro(n, vector<long long>(m));
        vector<vector<long long>> suffixPro(n, vector<long long>(m));

        // PREFIX
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) {
                    prefixPro[i][j] = 1;
                }
                else if(j == 0) {
                    prefixPro[i][j] = (prefixPro[i-1][m-1] * grid[i-1][m-1]) % MOD;
                }
                else {
                    prefixPro[i][j] = (prefixPro[i][j-1] * grid[i][j-1]) % MOD;
                }
            }
        }

        // SUFFIX (FIXED)
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1) {
                    suffixPro[i][j] = 1;
                }
                else if(j == m-1) {
                    suffixPro[i][j] = (suffixPro[i+1][0] * grid[i+1][0]) % MOD;
                }
                else {
                    suffixPro[i][j] = (suffixPro[i][j+1] * grid[i][j+1]) % MOD;
                }
            }
        }

        // RESULT
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                p[i][j] = (prefixPro[i][j] * suffixPro[i][j]) % MOD;
            }
        }

        return p;
    }
};