#include <bits/stdc++.h>
using namespace std;

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, 1, 0, -1};

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
    vector<string> g(n);
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    State e = {-1, -1};

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<State> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'S')
            {
                dist[i][j] = 0;
                q.push({i, j});
            }

            if (g[i][j] == 'E')
            {
                e = {i, j};
            }
        }
    }

    if (e.r == -1)
    {
        cout << -1 << '\n';
        return 0;
    }

    while (!q.empty())
    {
        State cur = q.front();
        int r = cur.r;
        int c = cur.c;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            {
                continue;
            }
            if (g[nr][nc] == '#')
            {
                continue;
            }
            if (dist[nr][nc] != -1)
            {
                continue;
            }
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    cout << dist[e.r][e.c] << '\n';
}