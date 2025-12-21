#include <bits/stdc++.h>
using namespace std;

// A simple stack implemented using vector
struct MyStack
{

    vector<int> data;

    // push x onto the stack
    void push(int x)
    {
        data.push_back(x);
    }

    // remove the top element
    void pop()
    {
        if (!data.empty())
        {
            data.pop_back();
        }
    }

    // return the top element
    int top()
    {
        assert(!data.empty());
        return data.back();
    }

    bool empty()
    {
        return data.empty();
    }

    int size()
    {
        return (int)data.size();
    }
};

// A simple queue implemented using deque
struct MyQueue
{
    deque<int> dq;

    // push x to the back of the queue
    void push(int x)
    {
        dq.push_back(x);
    }

    // remove the front element
    void pop()
    {
        assert(!dq.empty());
        dq.pop_front();
    }

    int front()
    {
        assert(!dq.empty());
        return dq.front();
    }

    bool empty()
    {
        return dq.empty();
    }

    int size()
    {
        return (int)dq.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "MyStack quick test\n";
    MyStack st;
    st.push(12);
    st.push(22);
    st.push(66);
    cout << "top = " << st.top() << " size = " << st.size() << "\n"; // top=66 size=3
    st.pop();
    cout << "top = " << st.top() << " size = " << st.size() << "\n"; // top=22 size=2

    cout << "\nMyQueue quick test\n";
    MyQueue q;
    q.push(6);
    q.push(12);
    q.push(22);
    cout << "front = " << q.front() << " size = " << q.size() << "\n"; // front=6 size=3
    q.pop();
    cout << "front = " << q.front() << " size = " << q.size() << "\n"; // front=12 size=2

    return 0;
}