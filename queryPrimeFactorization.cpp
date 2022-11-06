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
    int n, q;
    cin >> n >> q;
    vector<int> smallestPrimeFactor = smallestPrime(n); //O(NloglongN)

    for (int qq = 0; qq < q; qq++) //O(QlogX)
    {
        int x;
        cin >> x;
        while (x > 1) // O(logX)
        {
            cout << smallestPrimeFactor[x] << " ";
            x /= smallestPrimeFactor[x];
        }
        cout << "\n";
    }
}
