class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses, 0);
        vector<vector<int>> edges(numCourses);

        for(auto &prerequisite : prerequisites) {
            int &a = prerequisite[0], &b = prerequisite[1];
            edges[b].push_back(a);
            ++inDegrees[a];
        }

        queue<int> q;
        int seen = 0;
        for(int i = 0; i < numCourses; ++i) {
            if(inDegrees[i] == 0) {
                ++seen;
                q.push(i);
            }
        }
        while(q.size()) {
            int cur = q.front();
            q.pop();
            for(auto &n : edges[cur]) {
                --inDegrees[n];
                if(inDegrees[n] == 0) {
                    ++seen;
                    q.push(n);
                }
            }
        }
        return seen == numCourses;
    }
};