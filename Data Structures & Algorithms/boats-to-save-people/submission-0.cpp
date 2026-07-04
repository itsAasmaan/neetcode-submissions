class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size() - 1;

        int result = 0;

        while (right >= 0 && people[right] >= limit) {
            result++;
            right--;
        }

        while(left <= right) {
            result++;
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            } else {
                right--;
            }
        }

        return result;
    }
};