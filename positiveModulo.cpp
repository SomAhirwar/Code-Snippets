#include <bits/stdc++.h>
using namespace std;

int positiveMod(int x, int m)
{
    int res = x % m;
    if (res < 0)
        res += m;

    return res;
}