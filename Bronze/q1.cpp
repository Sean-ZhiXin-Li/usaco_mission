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
        long long A, B, CA, CB, FA;
        cin >> A >> B >> CA >> CB >> FA;

        if (A >= FA)
        {
            cout << 0 << '\n';
            continue;
        }

        long long l = 0, h = (long long)1e18;
        while (l < h)
        {
            long long m = l + (h - l) / 2;

            long long k0 = B / CB;
            long long kx = (B + m) / CB;

            __int128 worst = (__int128)LLONG_MAX;

            long long ce[4] = {k0, k0 + 1, kx - 1, kx};
            for (int idx = 0; idx < 4; idx++)
            {
                long long k = ce[idx];
                if (k < 0)
                    continue;

                __int128 L = (__int128)k * (__int128)CB - (__int128)B;
                __int128 R = (__int128)(k + 1) * (__int128)CB - (__int128)B - 1;

                if (R < 0)
                {
                    continue;
                }
                if (L > m)
                {
                    continue;
                }

                long long bl = (long long)max<__int128>(0, L);
                long long br = (long long)min<__int128>((__int128)m, R);
                if (bl > br)
                {
                    continue;
                }

                long long b = br;

                long long ad = m - b;
                long long A2 = A + ad;
                long long B2 = B + b;

                long long kn = B2 / CB;

                __int128 nu = (__int128)A2 + (__int128)CA * (__int128)kn;
                if (nu < worst)
                {
                    worst = nu;
                }
            }

            bool ok = (worst >= (__int128)FA);

            if (ok)
            {
                h = m;
            }
            else
            {
                l = m + 1;
            }
        }

        cout << l << '\n';
    }
    return 0;
}
