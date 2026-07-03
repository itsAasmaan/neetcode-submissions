class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;

        while (low < high) {
            if (target - numbers[low] == numbers[high]) {
                return {low + 1, high + 1};
            } else if (target - numbers[low] > numbers[high]) {
                low++;
            } else {
                high--;
            }
        }

        return {-1, -1};
    }
};
