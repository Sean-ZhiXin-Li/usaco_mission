#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y, z;

    while (cin >> x >> y >> z)
    {
        long long m = x;
        if (y > m)
            m = y;
        if (z > m)
            m = z;
        cout << m << '\n';
    }
    return 0;
}