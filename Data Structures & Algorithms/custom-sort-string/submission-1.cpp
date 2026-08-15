class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>lookup(26, 26);

        for (int i=0; i<order.length(); i++) {
            const char ch = order[i];
            lookup[ch - 'a'] = i;
        }

        sort(s.begin(), s.end(), [lookup](char a, char b){
            return lookup[a - 'a'] < lookup[b - 'a'];
        });

        return s;
    }
};