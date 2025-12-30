#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int N;
    cin >> N;

    vector<long long> x(N), y(N), p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> p[i];
    }

    vector<vector<int>> adj(N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                continue;
            }
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            long long dist2 = dx * dx + dy * dy;
            if (dist2 <= p[i] * p[i])
            {
                adj[i].push_back(j);
            }
        }
    }

    int ans = 1;

    for (int s = 0; s < N; s++)
    {
        vector<int> visited(N, 0);
        queue<int> q;

        visited[s] = 1;
        q.push(s);

        int cnt = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            cnt++;

            for (int nxt : adj[cur])
            {
                if (!visited[nxt])
                {
                    visited[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}