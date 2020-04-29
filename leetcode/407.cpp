class Solution {
public:
    void enqueue_border(priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> &pq, vector<vector<int>> &heightMap, vector<vector<bool>> &visited) {
        int m = heightMap.size(), n = heightMap[0].size();

        for(int i = 0; i < m; ++i) {
            if(i == 0 || i == m-1) {
                for(int j = 0; j < n; ++j) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
            else {
                int j = 0;
                pq.push({heightMap[i][j], i, j});
                visited[i][j] = true;
                j = n-1;
                pq.push({heightMap[i][j], i, j});
                visited[i][j] = true;
            }
        }
        return ;
    }

    void enqueue_if_valid(priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> &pq, vector<vector<int>> &heightMap, int i, int j, vector<vector<bool>> &visited) {
        const int &m = heightMap.size(), &n = heightMap[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
            return ;
        }
        pq.push({heightMap[i][j], i, j});
        visited[i][j] = true;
        return ;
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() < 3 || heightMap[0].size() < 3) {
            return 0;
        }
        const int &m = heightMap.size(), &n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // h, i, j

        enqueue_border(pq, heightMap, visited);

        int ans = 0, cur_min = pq.top()[0];
        while(pq.size()) {
            vector<int> cur = pq.top();
            int &cur_h = cur[0], &i = cur[1], &j = cur[2];
            pq.pop();

            // update cur_min
            if(cur_h < cur_min) {
                ans += cur_min - cur_h;
            }
            else {
                cur_min = cur_h;
            }

            // span children
            enqueue_if_valid(pq, heightMap, i-1, j, visited);
            enqueue_if_valid(pq, heightMap, i, j-1, visited);
            enqueue_if_valid(pq, heightMap, i+1, j, visited);
            enqueue_if_valid(pq, heightMap, i, j+1, visited);
        }
        return ans;
    }

};






