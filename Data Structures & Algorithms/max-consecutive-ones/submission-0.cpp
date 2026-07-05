class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int current = 0;

        for (int num: nums) {
            if (num == 1) {
                current++;
            } else {
                result = max(result, current);
                current = 0;
            }
        }
        result = max(result, current);
        
        return result;
    }
};