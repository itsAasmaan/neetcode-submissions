class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>hmap;

        for (const string &str: strs) {
            vector<int>count(26, 0);
            for (const char &ch: str) {
                count[ch - 'a']++;
            }

            string k = "";
            for (int i=0; i<26; i++) {
                if (count[i]) {
                    k += 'a' + i;
                    k += to_string(count[i]);
                }
            }

            hmap[k].emplace_back(str);
        }

        vector<vector<string>>result;
        for (auto [key, vec]: hmap) {
            result.push_back(vec);
        }

        return result;
    }
};
