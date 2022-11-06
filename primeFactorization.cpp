//Smallest prime factor
#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactorization(int x)
{
    vector<int> primeFactors;

    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            primeFactors.push_back(i);
            x /= i;
        }
    }

    if (x > 1)
        primeFactors.push_back(x);

    return primeFactors;
}

int main()
{
    int n;
    cin >> n;
    vector<int> primeFactors = primeFactorization(n);

    for (int i : primeFactors)
        cout << i << " ";
    cout << "\n";
}
