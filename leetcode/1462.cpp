class Solution {
public:
    vector<unordered_set<int>>
    create_is_pre(int n, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> course_to_pre(n, unordered_set<int>());
        vector<int> in_degrees(n, 0);
        vector<vector<int>> adj_lists(n, vector<int>());
        queue<int> q;
        for (const auto prerequisite : prerequisites) {
            const auto from = prerequisite[0], to = prerequisite[1];
            ++in_degrees[to];
            adj_lists[from].push_back(to);
        }
        for (int i = 0; i < n; ++i) {
            if (in_degrees[i] == 0)
                q.push(i);
        }
        while (q.size()) {
            const auto cur = q.front();
            q.pop();
            for (const auto to : adj_lists[cur]) {
                for (const auto pre : course_to_pre[cur]) {
                    course_to_pre[to].insert(pre);
                }
                course_to_pre[to].insert(cur);
                --in_degrees[to];
                if (in_degrees[to] == 0)
                    q.push(to);
            }
        }
        return course_to_pre;
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<unordered_set<int>> course_to_pre =
            create_is_pre(numCourses, prerequisites);
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            const auto q = queries[i];
            const auto key = q[1], target = q[0];
            if (course_to_pre[key].find(target) != course_to_pre[key].end())
                ans[i] = true;
        }
        return ans;
    }
};
