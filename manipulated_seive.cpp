#include <bits/stdc++.h>
using namespace std;
// function generate all prime number less then N in O(n)
const int MAX_SIZE = 10000100;

vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);

void manipulated_seive(int N)
{
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false;

    for (long long i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }

        for (long long j = 0;
             j < (int)prime.size() &&
             i * prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i * prime[j]] = false;

            // put smallest prime factor of i*prime[j]
            SPF[i * prime[j]] = prime[j];
        }
    }
}