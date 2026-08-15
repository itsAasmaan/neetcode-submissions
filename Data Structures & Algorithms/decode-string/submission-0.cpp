class Solution {
public:
    string recursiveHelper(int &index, string &s) {
        string result = "";
        int times = 0;

        while (index < s.length()) {
            char ch = s[index];
            if (isdigit(ch)) {
                times = times * 10 + (ch - '0');
            } else if (ch == '[') {
                index++;

                string res = recursiveHelper(index, s);
                while(times--) {
                    result += res;
                }
                times = 0;
            } else if (ch == ']') {
                return result;
            } else {
                result += ch;
            }

            index++;
        }

        return result;
    }

    string decodeString(string s) {
        int i=0;

        return recursiveHelper(i, s);
    }
};