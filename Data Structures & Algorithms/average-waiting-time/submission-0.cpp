class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        double time = 0;
        int startTime = 0;
        for (auto row: customers) {
            if (startTime < row[0]) {
                startTime = row[0];
            }

            time += ((row[1] + startTime) - row[0]);
            startTime = row[1] + startTime;
        }

        double result = time / n;

        return result;
    }
};