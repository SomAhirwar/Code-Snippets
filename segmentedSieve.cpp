#include <bits/stdc++.h>

using namespace std;

time_t Begin;

void init()
{
    Begin = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void timeTaken()
{
#ifndef ONLINE_JUDGE
    double time_taken = double(clock() - Begin) / double(CLOCKS_PER_SEC);
    cout << "Execution Time: " << fixed << setprecision(5) << time_taken << "s\n";
#endif
}


vector<bool> sieve(int n)
{
    vector<bool> is_prime(n+1, true);
    for(int i=2; i*i<=n; i++)
    {
        if(!is_prime[i])
            continue;

        for(int j=2*i; j<=n; j+=i)
            is_prime[j] = false;
    }

    return is_prime;
}

vector<bool> segmentedSieve(int l, int h)
{
    int sq = sqrt(h);
    vector<bool> sievePrime = sieve(sq);

    vector<bool> is_prime_segmented_sieve(h-l+1, true);

    for(int i=2; i<=sq; i++)
    {
        if(!sievePrime[i])
            continue;

        int sm = l/i * i;

        if(sm<l)
            sm += i;

        for(int j=sm; j<=h; j+=i)
            is_prime_segmented_sieve[j-l] = false;

    }
    return is_prime_segmented_sieve;

}

void print(vector<bool> &arr)
{
    int n = arr.size();
    for(int i=2; i<n; i++)
        cout<<i<<" "<<(arr[i]?"Prime":"Non-Prime")<<"\n";
}


int32_t main()
{
    init();
    //--------------------

    //Segmented Sieve

    /*
        Segmented sieve is used to find all of the prime numbers between [l, h]
        where, 2<=l<=h<=1e9, h-l+1<=1e7 
    */
    int l, h;
    cin>>l>>h;

    vector<bool> isPrime = segmentedSieve(l, h);

    for(int i=0; i<isPrime.size(); i++)
        cout<<i+l<<" "<<(isPrime[i]?"Prime":"Non Prime")<<"\n";
    //---------------------------
    timeTaken();
    return 0;
}