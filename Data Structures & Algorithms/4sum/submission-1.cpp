class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int low = j + 1;
                int high = n - 1;

                long long sum = nums[i] + nums[j];
                while (low < high) {
                    long long currSum = nums[low] + nums[high];
                    if (sum + currSum == target) {
                        result.push_back({nums[i], nums[j], nums[low], nums[high]});
                        do {
                            low++;
                        } while (low < n && nums[low] == nums[low - 1]);
                        do {
                            high--;
                        } while (high > 0 && nums[high] == nums[high + 1]);
                    } else if (sum + currSum < target) {
                        low++;
                    } else {
                        high--;
                    }
                }
            }
        }

        return result;
    }
};