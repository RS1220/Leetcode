class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) 
    {
        int n = rows;
        int m = encodedText.size() / n;

        vector<vector<char>> grid(n, vector<char>(m, ' '));

        int k = 0, i = 0, j = 0;

        // fill grid
        while (k < encodedText.size()) {
            if (j == m) {
                j = 0;
                i++;
            }
            grid[i][j] = encodedText[k];
            k++;
            j++;
        }

        string ans = "";

        // diagonal traversal
        for (int c = 0; c < m; c++) {
            int i = 0, j = c;
            while (i < n && j < m) {
                ans += grid[i][j];
                i++;
                j++;
            }
        }

        // remove trailing spaces
        while (!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};