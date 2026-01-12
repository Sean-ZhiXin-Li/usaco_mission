#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, K;
    cin >> T >> K;
    while (T--)
    {
        int N;
        string S;
        cin >> N >> S;

        int l = 3 * N;
        if (N % 2 == 1)
        {
            cout << -1 << '\n';
            continue;
        }

        bool ss = true;
        if (l % 2 == 1)
        {
            ss = false;
        }
        else
        {
            for (int i = 0; i < l / 2; i++)
            {
                if (S[i] != S[i + l / 2])
                {
                    ss = false;
                    break;
                }
            }
        }

        if (ss)
        {
            cout << 1 << '\n';
            for (int i = 0; i < l; i++)
            {
                cout << 1 << (i + 1 == l ? '\n' : ' ');
            }
            continue;
        }

        cout << 3 << '\n';
        for (int i = 0; i < l; i++)
        {
            int x;
            if (S[i] == 'C')
            {
                x = 1;
            }
            else if (S[i] == 'O')
            {
                x = 2;
            }
            else
            {
                x = 3;
            }
            cout << x << (i + 1 == l ? '\n' : ' ');
        }
    }
}