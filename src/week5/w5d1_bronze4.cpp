#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        long long area = -1;

        for (int j = l + 1; j <= r - 1; j++)
        {
            for (int i = l; i < j; i++)
            {
                if (s[i] == s[j])
                {
                    continue;
                }
                for (int k = j + 1; k <= r; k++)
                {
                    if (s[k] == s[j])
                    {
                        area = max(area, 1LL * (j - i) * (k - j));
                    }
                }
            }
        }

        cout << area << '\n';
    }

    return 0;
};