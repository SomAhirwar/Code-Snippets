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


vector<bool> seive(int n)
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

    //Sieve of Eratosthenes
    int n;
    cin>>n;
    vector<bool> isPrime = seive(n);
    print(isPrime);
    //---------------------------
    timeTaken();
    return 0;
}