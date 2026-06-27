class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup(nums.begin(), nums.end());

        int result = 0;
        for (int num : lookup) {
            if (lookup.find(num - 1) == lookup.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (lookup.find(currentNum + 1) != lookup.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                result = max(result, currentStreak);
            }
        }

        return result;
    }
};
