class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        
        for (int i=0; i<numRows; i++) {
            vector<int>curr;
            for (int j=0; j<=i; j++) {
                if (j == 0 || j == i) {
                    curr.push_back(1);
                } else {
                    int digit = result.back()[j-1] + result.back()[j];
                    curr.push_back(digit);
                }
            }

            result.emplace_back(curr);
        }

        return result;
    }
};