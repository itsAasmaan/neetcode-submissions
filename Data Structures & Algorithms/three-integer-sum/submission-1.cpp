class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int low = i + 1;
            int high = n - 1;

            int sum = nums[i];
            while (low < high) {
                int currSum = nums[low] + nums[high];
                if (sum + currSum == 0) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    do {
                        low++;
                    } while(low < n && nums[low] == nums[low-1]);
                    do {
                        high--;
                    } while(high > 0 && nums[high] == nums[high+1]);
                } else if (sum + currSum < 0)  {
                    low++;
                } else {
                    high--;
                }
            }
        }

        return result;
    }
};
