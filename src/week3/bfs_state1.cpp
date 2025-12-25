#include <bits/stdc++.h>
using namespace std;

struct State
{
    int r, c, used;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, K;
    cin >> n >> m >> K;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    int sr = -1, sc = -1, er = -1, ec = -1;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if (g[r][c] == 'S')
            {
                sr = r;
                sc = c;
            }
            if (g[r][c] == 'E')
            {
                er = r;
                ec = c;
            }
        }
    }
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(K + 1, -1)));

    queue<State> q;

    dist[sr][sc][0] = 0;
    q.push({sr, sc, 0});
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    if (sr == -1 || er == -1)
    {
        cout << -1 << '\n';
        return 0;
    }

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            {
                continue;
            }

            int nused = cur.used;

            if (g[nr][nc] == '#')
            {
                if (cur.used >= K)
                {
                    continue;
                }
                nused = cur.used + 1;
            }

            if (dist[nr][nc][nused] != -1)
            {
                continue;
            }

            dist[nr][nc][nused] = dist[cur.r][cur.c][cur.used] + 1;
            q.push({nr, nc, nused});
        }
    }

    int ans = INT_MAX;
    for (int used = 0; used <= K; used++)
    {
        int d = dist[er][ec][used];
        if (d != -1)
        {
            ans = min(ans, d);
        }
    }

    if (ans == INT_MAX)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }

    return 0;
}