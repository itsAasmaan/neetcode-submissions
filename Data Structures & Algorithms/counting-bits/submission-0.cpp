class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>bits(n+1);
        int lpot = 0;
        for (int i=1; i<=n; i++) {
            if (i & (i-1)) {
                bits[i] = 1 + bits[i - lpot];
            } else {
                bits[i] = 1;
                lpot = i;
            }
        }

        return bits;
    }
};