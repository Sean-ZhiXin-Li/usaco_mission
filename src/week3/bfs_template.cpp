#include <bits/stdc++.h>
using namespace std;

// Reusable BFS template (edit State + neighbor generation per problem)

struct State
{
    // TODO: define state fields
    // Examples:
    // int x, y;
    // int node;
    // int x, y, k;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<State> q;

    // =========================
    // TODO: create visited/dist structure
    // Examples:
    // vector<vector<int>> dist(n, vector<int>(m, -1));
    // vector<int> dist(N, -1);
    // vector<vector<vector<int>>> dist(..., -1);
    // =========================

    // =========================
    // TODO: define start state
    // State start{...};
    // mark visited/dist for start
    // push start into q
    // =========================

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        // =========================
        // TODO: generate neighbors of cur
        // for each neighbor nxt:
        //   if invalid -> continue
        //   if visited -> continue
        //   mark visited / set dist
        //   q.push(nxt)
        // =========================
    }

    // =========================
    // TODO: output answer based on dist/visited
    // =========================

    return 0;
}
