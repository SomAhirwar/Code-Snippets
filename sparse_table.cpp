#include <bits/stdc++.h>
using namespace std;
class sparseTable
{
    vector<vector<int>> sparse_table;
    vector<int> log_table;
    int p, n;

public:
    sparseTable(int n, vector<int> &in)
    {
        this->n = n;
        p = log2(n);
        sparse_table = vector<vector<int>>(p + 1, vector<int>(n));
        log_table = vector<int>(n + 5, 0);
        log_table[1] = 0;
        for (int i = 2; i < n + 5; i++)
            log_table[i] = log_table[i / 2] + 1;

        for (int i = 0; i < n; i++)
            sparse_table[0][i] = in[i];

        for (int i = 1; i <= p; i++)
        {
            for (int j = 0; j < n - ((1 << i) - 1); j++)
            {
                sparse_table[i][j] = min(sparse_table[i - 1][j], sparse_table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    /*
    void printTable()
    {
        cout << sparse_table.size() << " " << sparse_table[0].size() << endl;
        for (int i = 0; i <= p; i++)
        {
            cout << i << " " << n - (1 << i) << endl;
            for (int j = 0; j < n - ((1 << i) - 1); j++)
                cout << sparse_table[i][j] << " ";
            cout << endl;
        }
    }
    */

    int minQuery(int l, int r) //Return minimum of range [l, r]
    {
        int k = log_table[r - l + 1];
        return min(sparse_table[k][l], sparse_table[k][r - (1 << k) + 1]);
    }
};

int main()
{
    vector<int> in = {4, 2, 3, 7, 1, 5, 3, 3, 9, 6, 7, -1, 4};
    sparseTable s(13, in);
}