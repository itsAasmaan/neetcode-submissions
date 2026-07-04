class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char>st;

        int l=0;
        int r=0;
        int result = 0;
        while(r < n) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            result = max(result, r-l+1);
            r++;
        }

        return result;
    }
};
