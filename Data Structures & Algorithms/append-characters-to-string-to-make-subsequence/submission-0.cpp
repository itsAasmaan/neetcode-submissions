class Solution {
public:
    int appendCharacters(string s, string t) {
        int ti = 0;

        for (int i=0; i<s.length(); i++) {
            if (s[i] == t[ti]) ti++;

            if (ti >= t.length()) return 0;
        }

        if (ti >= t.length()) return 0;
        
        return t.length()-ti;
    }
};