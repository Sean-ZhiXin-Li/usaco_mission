#include <bits/stdc++.h>
using namespace std;

static bool check(long long A, long long B,
                  long long CA, long long CB, long long fA, long long mid)
{
    long long B_total = B + mid;

    long long k = B_total / CB;

    __int128 A_final = (__int128)A + (__int128)k * (__int128)CA;

    return A_final >= fA;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        long long A, B, CA, CB, fA;
        cin >> A >> B >> CA >> CB >> fA;

        if (A >= fA)
        {
            cout << 0 << '\n';
            continue;
        }

        long long lo = 0;
        long long hi = 1;

        while (!check(A, B, CA, CB, fA, hi))
        {
            if (hi > (LLONG_MAX / 2))
            {
                hi = LLONG_MAX;
                break;
            }
            hi *= 2;
        }

        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if (check(A, B, CA, CB, fA, mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << lo << '\n';
    }

    return 0;
}