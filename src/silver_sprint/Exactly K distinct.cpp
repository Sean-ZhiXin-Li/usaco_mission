#include <bits/stdc++.h>
using namespace std;

long long atMostKDistinct(const vector<int> &a, int K)
{
    if (K < 0)
    {
        return 0;
    }

    unordered_map<int, int> freq;
    int n = (int)a.size();
    int left = 0;
    long long ans = 0;
    int distinct = 0;

    for (int right = 0; right < n; right++)
    {
        if (freq[a[right]] == 0)
        {
            distinct++;
        }
        freq[a[right]]++;

        while (distinct > K)
        {
            freq[a[left]]--;
            if (freq[a[left]] == 0)
            {
                distinct--;
            }
            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}

long long exactlyKDistinct(const vector<int> &a, int K)
{
    long long ans = atMostKDistinct(a, K) - atMostKDistinct(a, K - 1);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << exactlyKDistinct(a, K) << '\n';

    return 0;
}
