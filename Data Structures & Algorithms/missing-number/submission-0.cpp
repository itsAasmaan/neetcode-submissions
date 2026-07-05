class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int prefixSum = 0;

        for (int i=1; i<=nums.size(); i++) {
            prefixSum ^= i;
        }

        for (int num: nums) {
            prefixSum ^= num;
        }

        return prefixSum;
    }
};
