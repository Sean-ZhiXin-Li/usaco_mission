#include <bits/stdc++.h>
using namespace std;

struct State
{
    int r, c;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    queue<State> q;

    vector<vector<int>> dist(n, vector<int>(m, -1));

    State start{-1, -1};
    State target{-1, -1};

    // find start / target

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'S')
                start = {i, j};
            if (grid[i][j] == 'E')
                target = {i, j};
        }
    }
#ifdef DEBUG
    cerr << "S=" << start.r << "," << start.c << "  "
         << "E=" << target.r << "," << target.c << "\n";
#endif

    if (start.r == -1 || target.r == -1)
    {
        cout << -1 << '\n';
        return 0;
    }

    dist[start.r][start.c] = 0;
    q.push(start);

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];

            // invalid position
            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            // wall
            if (grid[nr][nc] == '#')
                continue;

            // already visited
            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[cur.r][cur.c] + 1;
            q.push({nr, nc});
        }
    }

    cout << dist[target.r][target.c] << '\n';

    return 0;
}
