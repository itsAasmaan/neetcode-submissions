class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>freq;

        for (const string &email: emails) {
            string result = "";

            bool plusseen = false;
            for (int i=0; i<email.length(); i++) {
                if (email[i] == '@') {
                    result += email.substr(i);
                    break;
                } else if (email[i] == '+') {
                    plusseen = true;
                } else if (email[i] != '.' && plusseen == false) {
                    result += email[i];
                }
            }

            freq.insert(result);
        }

        return freq.size();
    }
};