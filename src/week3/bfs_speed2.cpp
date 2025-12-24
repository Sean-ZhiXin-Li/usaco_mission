#include <bits/stdc++.h>
using namespace std;

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, 1, 0, -1};
static const char dirc[4] = {'U', 'R', 'D', 'L'};

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

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));

    deque<tuple<int, int, int>> dq;

    dist[0][0] = 0;
    dq.push_front({dist[0][0], 0, 0});

    while (!dq.empty())
    {
        auto [d, r, c] = dq.front();
        dq.pop_front();

        if (d != dist[r][c])
        {
            continue;
        }

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            {
                continue;
            }

            int w = (g[r][c] == dirc[k]) ? 0 : 1;

            int nd = d + w;
            if (nd < dist[nr][nc])
            {
                dist[nr][nc] = nd;
                if (w == 0)
                {
                    dq.push_front({nd, nr, nc});
                }
                else
                {
                    dq.push_back({nd, nr, nc});
                }
            }
        }
    }
    cout << dist[n - 1][m - 1] << '\n';
    return 0;
}