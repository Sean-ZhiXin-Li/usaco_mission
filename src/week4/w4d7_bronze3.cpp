// USACO 2025 US Open Contest, Bronze
// Problem 2. More Cow Photos

// Key idea:
// 1) rearrange allowed -> use frequency
// 2) palindrome -> symmetric pairs
// 3) peak -> choose max as center

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        int mx = 0;
        vector<int> freq(N + 1, 0);
        for (int i = 0; i < N; i++)
        {
            int h;
            cin >> h;
            freq[h]++;
            mx = max(mx, h);
        }

        int pn = 0;
        for (int x = 1; x < mx; x++)
        {
            if (freq[x] >= 2)
            {
                pn++;
            }
        }

        int ans = 1 + 2 * (pn);

        cout << ans << '\n';
    }

    return 0;
}
