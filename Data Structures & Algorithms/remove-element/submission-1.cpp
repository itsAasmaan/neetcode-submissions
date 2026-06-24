class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while (end >= 0 && nums[end] == val) {
            end--;
        }
        while (start < end) {
            if (nums[start] == val) {
                swap(nums[start], nums[end]);
                while (end >= 0 && nums[end] == val) {
                    end--;
                }
            } else {
                start++;
            }
        }

        return min(end, start) + 1;
    }
};