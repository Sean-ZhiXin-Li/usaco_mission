#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));

    bool found = false;
    for (int i = 0; i < n && !found; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'S')
            {
                dist[i][j] = 0;
                q.push({i, j});
                found = true;
                break;
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    if (!found)
    {
        return 0;
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            if (grid[nx][ny] == '#')
            {
                continue;
            }

            if (dist[nx][ny] != -1)
            {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            if (dist[k][l] == -1)
            {
                cerr << "* ";
            }
            else
            {
                cerr << dist[k][l] << " ";
            }
        }
        cerr << '\n';
    }

    int maxd = -1;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            if (dist[a][b] != -1)
            {
                if (dist[a][b] > maxd)
                {
                    maxd = dist[a][b];
                }
            }
        }
    }
    cout << maxd << '\n';
    return 0;
}