#include <bits/stdc++.h>
using namespace std;

struct State
{
    int r, c;
};

// CHECKPOINT: start must be a fully-defined state before using it.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool found = false;
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
    }

    queue<State> q;
    vector<vector<int>> dist(R, vector<int>(C, -1));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == 'S')
            {
                dist[i][j] = 0;
                q.push({i, j});
                found = true;
            }
        }
    }

    if (!found)
    {
        return 0;
    }

    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, -1, 0, 1};

    // Example of the transition
    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nr = cur.r + dr[k];
            int nc = cur.c + dc[k];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            {
                continue;
            }

            if (grid[nr][nc] == '#')
            {
                continue;
            }

            if (dist[nr][nc] != -1)
            {
                continue;
            }

            dist[nr][nc] = dist[cur.r][cur.c] + 1;
            q.push({nr, nc});
        }
    }

    // TODO: define what the answer is based on the problem
    // CHECKPOINT: answer meaning depends on problem statement
    // CHECKPOINT: BFS engine is complete; problem defines target/output
}