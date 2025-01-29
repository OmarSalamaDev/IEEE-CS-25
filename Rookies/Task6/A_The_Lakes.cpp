#include <iostream>
#include <vector>
#include <stack>

using namespace std;


vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


int dfs(
    vector<vector<int>> &grid,
    vector<vector<bool>> &visited,
    int i,
    int j
) {

    int n = grid.size(),
        m = grid[0].size();

    stack<pair<int, int>> st;
    st.push({i, j});
    visited[i][j] = true;

    int volume = 0;

    while (!st.empty()) {
        auto xy = st.top();
        int x = xy.first, 
            y = xy.second;
        st.pop();
        volume += grid[x][y];

        for (const auto& dir : directions) {
            int newX = x + dir.first,
                newY = y + dir.second;

            if(
                newX >= 0 &&
                newY >= 0 &&
                newX < n &&
                newY < m &&
                !visited[newX][newY] &&
                grid[newX][newY] > 0
            ) {
                visited[newX][newY] = true;
                st.push({newX, newY});
            }
        }
    }
    return volume;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> ans;

    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        
        int maxVol = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0 && !visited[i][j]) {
                    maxVol = max(maxVol, dfs(grid, visited, i, j));
                }
            }
        }

        ans.push_back(maxVol);
    }

    for(int i : ans) cout << i << "\n";
    cout << endl;

}