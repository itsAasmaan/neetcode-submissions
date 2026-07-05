class Solution {
   public:
    string addBinary(string a, string b) {
        string result = "";

        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0) {
            char ch1 = i >= 0 ? a[i] : '0';
            char ch2 = j >= 0 ? b[j] : '0';

            char digit;
            if (ch1 == '1' && ch2 == '1') {
                digit = carry ? '1' : '0';
                carry = 1;
            } else if (ch1 == '1' || ch2 == '1') {
                digit = carry ? '0' : '1';
                carry = carry ? 1 : 0;
            } else {
                digit = carry ? '1' : '0';
                carry = 0;
            }

            result = digit + result;
            i--;
            j--;
        }

        if (carry) {
            result = '1' + result;
        }

        return result;
    }
};