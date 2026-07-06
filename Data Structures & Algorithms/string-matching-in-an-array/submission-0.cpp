class Solution {
   public:
    bool isSubstring(const string& sub, const string& str) {
        int subLen = sub.length();
        int strLen = str.length();
        if (subLen > strLen) return false;

        for (int i = 0; i <= strLen - subLen; i++) {
            int j;
            for (j = 0; j < subLen; j++) {
                if (str[i + j] != sub[j]) {
                    break;
                }
            }
            if (j == subLen) {
                return true;
            }
        }
        
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;

        sort(words.begin(), words.end(),
             [](const string& a, const string& b) { return a.length() < b.length(); });

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSubstring(words[i], words[j])) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }

        return result;
    }
};