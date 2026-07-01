class Solution {
public:
    bool isPalindrome(string &s, int low, int high, bool missed) {
        if (low >= high) {
            return true;
        }

        if (s[low] != s[high]) {
            if (missed) {
                return false;
            }

            return isPalindrome(s, low, high-1, true) || isPalindrome(s, low+1, high, true);
        }

        return isPalindrome(s, low+1, high-1, missed);
    }

    bool validPalindrome(string s) {
        return isPalindrome(s, 0, s.length()-1, false);
    }
};