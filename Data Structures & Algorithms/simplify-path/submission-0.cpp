class Solution {
public:
    string simplifyPath(string path) {
        vector<string>parts;
        stringstream ss(path);
        string part;

        while(getline(ss, part, '/')) {
            if (part == "" || part == ".") {
                continue;
            }

            if (part == "..") {
                if (parts.empty() == false) {
                    parts.pop_back();
                }
            } else {
                parts.push_back(part);
            }
        }

        string result = "";
        for (const string &part: parts) {
            result += '/' + part;
        }

        if (result == "") return "/";
        
        return result;
    }
};