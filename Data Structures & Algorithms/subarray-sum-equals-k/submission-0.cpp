class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        unordered_map<int, int>lookup;
        int sum = 0;
        lookup[0] = 1;

        for (int num: nums) {
            sum += num;
            int diff = sum - k;

            if (lookup.count(diff)) {
                result += lookup[diff];
            }

            lookup[sum]++;
        }

        return result;
    }
};