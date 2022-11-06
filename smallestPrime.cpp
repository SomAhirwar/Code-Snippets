//Smallest prime factor
#include <bits/stdc++.h>
using namespace std;

vector<int> smallestPrime(int n)
{
    vector<int> sieve(n + 1, -1);

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] != -1)
            continue;
        for (int j = i; j <= n; j += i)
            if (sieve[j] == -1)
                sieve[j] = i;
    }

    return sieve;
}

int main()
{
    int n;
    cin >> n;
    vector<int> sieve = smallestPrime(n);

    for (int i = 2; i <= n; i++)
        cout << i << "\t" << sieve[i] << endl;
}
