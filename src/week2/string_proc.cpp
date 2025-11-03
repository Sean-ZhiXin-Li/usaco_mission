#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);

    int words = 0;
    bool inWord = false;

    for (char c : line)
    {
        if (!isspace(static_cast<unsigned char>(c)))
        {
            if (!inWord)
            {
                words++;
                inWord = true;
            }
        }
        else
        {
            inWord = false;
        }
    }

    cout << "words = " << words << '\n';
    return 0;
}
