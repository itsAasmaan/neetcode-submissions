class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(n + 1);
        for (auto& [v, f] : freq) {
            buckets[f].push_back(v);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
