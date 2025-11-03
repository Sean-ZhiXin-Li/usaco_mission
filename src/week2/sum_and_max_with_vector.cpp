#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n) || n <= 0)
        return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long sum = 0;
    for (long long x : a)
        sum += x;

    long long m = a[0];
    for (long long x : a)
        if (x > m)
            m = x;
    cout << "sum = " << sum << '\n';
    cout << "max = " << m << '\n';
    return 0;
}
