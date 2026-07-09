class Solution {
public:
    void bfs(queue<pair<int,int>> &q, vector<vector<int>> &vis, vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (!vis[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        queue<pair<int,int>> pacQ;
        queue<pair<int,int>> atlQ;

        for (int i = 0; i < n; i++) {
            pacific[i][0] = 1;
            pacQ.push({i, 0});

            atlantic[i][m - 1] = 1;
            atlQ.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            pacific[0][j] = 1;
            pacQ.push({0, j});

            atlantic[n - 1][j] = 1;
            atlQ.push({n - 1, j});
        }

        bfs(pacQ, pacific, heights);
        bfs(atlQ, atlantic, heights);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};