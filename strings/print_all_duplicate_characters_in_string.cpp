#include <bits/stdc++.h>
using namespace std;

void printDuplicates(string s)
{
    map<char, int> mp;

    for (auto c : s)
        mp[c]++;

    for (auto x : mp)
    {
        if (x.second > 1) cout<<x.first<<" -> "<<x.second<<endl;
    }

    return;
}

int main()
{
    printDuplicates("geeksforgeeks");
    printDuplicates("thisisastring");

    return 0;
}