class Solution {
public:
    int helper(string s) {
        if (s.size() == 0) return 0;

        return ((s[0] - 'A' + 1) * pow(26, s.size() - 1))
               + helper(s.substr(1));
    }

    int titleToNumber(string columnTitle) {
        return helper(columnTitle);
    }
};