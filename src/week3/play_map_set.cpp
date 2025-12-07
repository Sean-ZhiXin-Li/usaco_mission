#include <bits/stdc++.h>
using namespace std;

// Demo 1 : basic usage of vector
void demo_vector()
{
    // vector is a dynamic array: we can change its size easily
    int n;
    cout << "[vector] Enter how many numbers: ";
    if (!(cin >> n))
    {
        cout << "Input error.\n";
        return;
    }

    vector<int> nums;
    nums.reserve(n);

    cout << "[vector] Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "[vector] Original order: ";
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << "\n";

    // sort the dynamic array
    sort(nums.begin(), nums.end());

    cout << "[vector] Sorted order: ";
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << "\n";

    cout << "[vector] Even numbers: ";
    for (int x : nums)
    {
        if (x % 2 == 0)
        {
            cout << x << " ";
        }
    }
    cout << "\n\n";
}

// Demo 2: basic usage of map for frequency counting
void demo_map_freq()
{
    // sample words for demonstration
    vector<string> words = {
        "apple", "banana", "apple", "dog", "apple", "cat", "banana"};

    map<string, int> freq;

    // count frequency of each word
    for (const string &w : words)
    {
        freq[w]++; // default value is 0, then increase
    }

    cout << "[map] word frequencies: \n";
    for (auto &p : freq)
    {
        // map is ordered by key (alphabetically)
        cout << " " << p.first << " ->" << p.second << "\n";
    }
    cout << "\n";

    // access  counts
    cout << "[map] count(\"apple\") = " << freq["apple"] << "\n";
    cout << "[map] count(\"orange\") = " << freq["orange"] << "(auto-created key)\n\n";
}

// Demo 3: basic usage of set for unique elements
void demo_set_unique()
{
    // sample list with duplicates
    vector<int> numbers = {5, 1, 2, 2, 5, 3, 1, 4};

    // construct a set (automatically removes duplicates and sorts)
    set<int> s(numbers.begin(), numbers.end());

    cout << "[set] unique numbers in sorted order: \n ";
    for (int x : s)
    {
        cout << x << " ";
    }
    cout << "\n";

    // membership check
    int target = 3;
    if (s.count(target))
    {
        cout << "[set] " << target << " is in the set.\n";
    }
    else
    {
        cout << "[set] " << target << " is NOT in the set.\n ";
    }

    target = 6;
    if (s.count(target))
    {
        cout << "[set] " << target << " is in the set.\n";
    }
    else
    {
        cout << "[set] " << target << " is NOT the set.\n";
    }

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << " WEEK3 Day1: vector / map / set playground\n\n";

    demo_vector();
    demo_map_freq();
    demo_set_unique();

    cout << "End of Day1 demo\n";
    return 0;
}
