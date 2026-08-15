class Solution {
public:
    bool isVowel(const char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>lookup(n+1, 0);

        for (int i=0; i<n; i++) {
            bool isStartVowel = isVowel(words[i][0]);
            bool isEndVowel = isVowel(words[i][words[i].length()-1]);

            lookup[i+1] = lookup[i];
            if (isStartVowel && isEndVowel) {
                lookup[i+1] = lookup[i] + 1;
            }
        }

        vector<int>result(queries.size());
        for (int i=0; i<queries.size(); i++) {
            int li = queries[i][0];
            int ri = queries[i][1];

            int total = lookup[ri+1] - lookup[li];
            result[i] = total;
        }

        return result;
    }
};