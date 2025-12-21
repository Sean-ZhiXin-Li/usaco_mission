#include <bits/stdc++.h>
using namespace std;

bool is_open(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

bool match(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool is_balanced(const string &s)
{
    stack<char> st;
    for (char c : s)
    {
        if (is_open(c))
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;

            if (!match(st.top(), c))
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << (is_balanced(s) ? "YES\n" : "NO\n");
    return 0;
}