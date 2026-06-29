class Solution {
   public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char ch) {
            return !isalnum(ch); 
        }), s.end());

        transform(s.begin(), s.end(), s.begin(), [](unsigned char ch) {
            return tolower(ch);
        });

        int low = 0;
        int high = s.length() - 1;
        while (low < high) {
            if (s[low] != s[high]) {
                return false;
            }

            low++;
            high--;
        }

        return true;
    }
};
