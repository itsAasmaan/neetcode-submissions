class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>lookup;

        for (int num: nums) {
            if (lookup.count(num)) {
                return true;
            }

            lookup.insert(num);
        }

        return false;
    }
};