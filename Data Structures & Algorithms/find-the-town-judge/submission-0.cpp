class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>graph(n+1);

        for (int i=0; i<trust.size(); i++) {
            graph[trust[i][1]].push_back(trust[i][0]);
        }

        int judge = -1;
        for (int i=0; i<=n; i++) {
            if (graph[i].size() == n-1) {
                judge = i;
                break;
            }
        }

        for (int i=1; i<=n; i++) {
            if (i == judge) continue;
            for (auto person: graph[i]) {
                if (person == judge) {
                    judge = -1;
                    break;
                }
            }

            if (judge == -1) {
                break;
            }
        }

        return judge;
    }
};