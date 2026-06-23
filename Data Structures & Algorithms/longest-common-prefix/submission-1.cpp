class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string base = strs[0];
        for (int j = 0; j < base.size(); j++) {
            char ch = base[j];
            for (int i = 1; i < strs.size(); i++) {
                if (j >= strs[i].size() || strs[i][j] != ch) {
                    return base.substr(0, j);
                }
            }
        }

        return base;
    }
};