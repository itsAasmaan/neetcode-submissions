class Solution {
   public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];

        int i = low - 1;
        int j = high + 1;
        while (true) {
            do {
                i++;
            } while (nums[i] < pivot);

            do {
                j--;
            } while (nums[j] > pivot);

            if (i >= j) return j;

            swap(nums[i], nums[j]);
        }

        return j;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int p = partition(nums, low, high);

            quickSort(nums, low, p);
            quickSort(nums, p + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }
};