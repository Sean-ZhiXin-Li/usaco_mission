#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int Q;
    cin >> Q;

    vector<vector<int>> g(N + 1, vector<int>(N + 1, 0));

    int vp = N - K + 1;
    vector<vector<int>> ap(vp + 1, vector<int>(vp + 1, 0));

    int ans = 0;
    while (Q--)
    {
        int r, c;
        long long v;
        cin >> r >> c >> v;
        long long diff = v - g[r][c];
        g[r][c] = v;

        int a1 = max(1, r - K + 1);
        int a2 = min(vp, r);
        int b1 = max(1, c - K + 1);
        int b2 = min(vp, c);

        for (int i = a1; i <= a2; i++)
        {
            for (int j = b1; j <= b2; j++)
            {
                ap[i][j] += diff;
                if (ap[i][j] > ans)
                {
                    ans = ap[i][j];
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}