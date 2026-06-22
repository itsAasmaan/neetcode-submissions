class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26, 0);

        for (const char &ch: s) {
            freq[ch-'a']++;
        }

        for (const char &ch: t) {
            freq[ch-'a']--;
        }

        for (int i=0; i<26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
