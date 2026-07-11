class Solution {
public:
    bool compareStrings(const string &a, const string &b, vector<int>&lookup) {
        int n = min (a.length(), b.length());

        for (int i=0; i<n; i++) {
            if (a[i] != b[i]) {
                return lookup[a[i] - 'a'] < lookup[b[i] - 'a'];
            } 
        }

        return a.length() <= b.length();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>lookup(26, 0);

        for (int i=0; i<order.length(); i++) {
            lookup[order[i] - 'a'] = i;
        }

        for (int i=1; i<words.size(); i++) {
            if (!compareStrings(words[i-1], words[i], lookup)) {
                return false;
            }
        }

        return true;
    }
};