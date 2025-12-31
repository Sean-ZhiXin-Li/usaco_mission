#include <bits/stdc++.h>
using namespace std;

struct State
{
    int a, b;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int X, Y, K, M;
    cin >> X >> Y >> K >> M;

    vector<vector<int>> dist(X + 1, vector<int>(Y + 1, -1));
    queue<State> q;

    dist[0][0] = 0;
    q.push({0, 0});

    int best = abs(M - 0);

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();
        int d = dist[cur.a][cur.b];

        best = min(best, abs(M - (cur.a + cur.b)));

        if (d == K)
        {
            continue;
        }

        int a = cur.a, b = cur.b;

        {
            int na = X, nb = b;
            if (dist[na][nb] == -1)
            {
                dist[na][nb] = d + 1;
                q.push({na, nb});
            }
        }

        {
            int na = a, nb = Y;
            if (dist[na][nb] == -1)
            {
                dist[na][nb] = d + 1;
                q.push({na, nb});
            }
        }

        {
            int na = 0, nb = b;
            if (dist[na][nb] == -1)
            {
                dist[na][nb] = d + 1;
                q.push({na, nb});
            }
        }

        {
            int na = a, nb = 0;
            if (dist[na][nb] == -1)
            {
                dist[na][nb] = d + 1;
                q.push({na, nb});
            }
        }

        {
            int pour = min(a, Y - b);
            int na = a - pour;
            int nb = b + pour;
            if (dist[na][nb] == -1)
            {
                dist[na][nb] = d + 1;
                q.push({na, nb});
            }
        }

        {
            int pour = min(b, X - a);
            int na = a + pour;
            int nb = b - pour;
            if (dist[na][nb] == -1)
            {
                dist[na][nb] = d + 1;
                q.push({na, nb});
            }
        }
    }

    cout << best << '\n';
    return 0;
}