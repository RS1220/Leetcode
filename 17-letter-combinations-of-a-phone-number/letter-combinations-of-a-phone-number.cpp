class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res;
        string path;

        function<void(int)> dfs = [&](int index) {
            if (index == digits.size()) {
                res.push_back(path);
                return;
            }

            for (char c : phone[digits[index]]) {
                path.push_back(c);
                dfs(index + 1);
                path.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};