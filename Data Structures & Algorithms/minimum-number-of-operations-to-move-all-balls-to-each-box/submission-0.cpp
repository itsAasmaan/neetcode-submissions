class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();

        vector<int>lookup;
        for (int i=0; i<n; i++) {
            if (boxes[i] == '1') {
                lookup.push_back(i);
            }
        }

        vector<int>result(n);
        for (int i=0; i<n; i++) {
            int roundTrips = 0;
            for (int idx: lookup) {
                if (idx != i) {
                    roundTrips += abs(i - idx);
                }
            }

            result[i] = roundTrips;
        } 

        return result;
    }
};