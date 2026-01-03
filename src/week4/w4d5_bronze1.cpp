// USACO 2025 US Open Contest, Bronze
// Problem 1. Hoof Paper Scissors Minus One

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> res(N + 1, vector<char>(N + 1, 'D'));
    for (int i = 1; i <= N; i++)
    {
        string row;
        cin >> row;
        for (int j = 1; j <= i; j++)
        {
            char c = row[j - 1];
            res[i][j] = c;

            if (c == 'W')
            {
                res[j][i] = 'L';
            }
            else if (c == 'L')
            {
                res[j][i] = 'W';
            }
            else
            { // 'D'
                res[j][i] = 'D';
            }
        }
    }

    vector<vector<int>> beaters(N + 1);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (res[i][j] == 'W')
            {
                beaters[j].push_back(i);
            }
        }
    }

    while (M--)
    {
        int s1, s2;
        cin >> s1 >> s2;

        long long A = beaters[s1].size();
        long long B = beaters[s2].size();

        vector<int> mark(N + 1, 0);
        for (int x : beaters[s1])
            mark[x] = 1;

        long long K = 0;
        for (int x : beaters[s2])
        {
            if (mark[x])
                K++;
        }

        long long total = 1LL * N * N;
        long long fail = 1LL * (N - K) * (N - K);
        long long ans = total - fail;
        cout << ans << '\n';
    }

    return 0;
}