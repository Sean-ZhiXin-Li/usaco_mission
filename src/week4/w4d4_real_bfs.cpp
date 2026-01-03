// USACO 2014 December Contest, Silver
// Problem 1. Piggyback
#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;
// BFS on an unweighted graph, returns shortest edge-count distances.
// CHECKPOINT: dist meaning?
// Answer: dist[u] is the minimum number of edges from start to u.
vector<int> bfs_dist(int start, const vector<vector<int>> &adj)
{
    int n = (int)adj.size() - 1;
    vector<int> dist(n + 1, INF);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // CHECKPOINT: transition rule?
        // Answer: from u, we can move to any adjacent v in one step.

        for (int v : adj[u])
        {
            if (dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);

    long long B, E, P;
    int N, M;
    cin >> B >> E >> P >> N >> M;

    vector<vector<int>>
        adj(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // CHECKPOINT: does State contain all information needed for future moves?
    // Answer: Yes. State is just the current field (node id).

    vector<int> d1 = bfs_dist(1, adj);
    vector<int> d2 = bfs_dist(2, adj);
    vector<int> dN = bfs_dist(N, adj);

    // CHECKPOINT: why BFS is correct here?
    // Answer: the graph is unweighted, so BFS gives shortest edge counts.

    long long ans = LLONG_MAX;
    for (int x = 1; x <= N; x++)
    {
        if (d1[x] == INF || d2[x] == INF || dN[x] == INF)
        {
            continue;
        }

        long long cost = B * 1LL * d1[x] + E * 1LL * d2[x] + P * 1LL * dN[x];

        ans = min(ans, cost);
    }

    // CHECKPOINT: when should the search stop?
    // Answer: after evaluating all meeting points x in [1..N].

    cout << ans << '\n';

    return 0;
}