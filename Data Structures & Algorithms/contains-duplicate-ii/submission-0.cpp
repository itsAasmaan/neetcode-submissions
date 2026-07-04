class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int>lookup;

        for (int i=0; i<=k && i<n; i++) {
            if (lookup.count(nums[i])) {
                return true;
            }

            lookup.insert(nums[i]);
        }

        for (int i=k+1; i<n; i++) {
            lookup.erase(nums[i-k-1]);
            if (lookup.count(nums[i])) {
                return true;
            }
            lookup.insert(nums[i]);
        }

        return false;
    }
};