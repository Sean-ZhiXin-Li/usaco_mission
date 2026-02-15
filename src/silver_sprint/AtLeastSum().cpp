#include <bits/stdc++.h>
using namespace std;

long long countAtLeastSum(const vector<int> &a, long long S)
{
    int n = (int)a.size();
    long long ans = 0;
    long long sum = 0;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        sum += a[r];

        while (l <= r && sum >= S)
        {
            ans += n - r;

            sum -= a[l];
            l++;
        }
    }
    return ans;
}