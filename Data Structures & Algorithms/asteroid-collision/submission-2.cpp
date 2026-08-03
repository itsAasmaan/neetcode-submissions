class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>result;

        for (int &asteroid: asteroids) {
            while (!result.empty() && asteroid < 0 && result.back() > 0) {
                int diff = asteroid + result.back();
                if (diff > 0) {
                    asteroid = 0;
                } else if (diff < 0) {
                    result.pop_back();
                } else {
                    asteroid = 0;
                    result.pop_back();
                }
            }

            if (asteroid) {
                result.push_back(asteroid);
            }
        }

        return result;
    }
};