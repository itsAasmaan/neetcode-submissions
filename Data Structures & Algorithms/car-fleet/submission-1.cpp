class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float, float>>vec;
        for (int i=0; i<position.size(); i++) {
            vec.push_back(make_pair(position[i], speed[i]));
        }

        sort(vec.begin(), vec.end(), [](auto a, auto b) {
            return a.first > b.first;
        });

        stack<float>st;
        for (auto [p, s]: vec) {
            float time = (target - p) / s;
            if (st.empty() || st.top() < time) {
                st.push(time);
            }
        }

        return st.size();
    }
};
