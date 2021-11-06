#include <bits/stdc++.h>

vector<vector<int>> floydWarshall(vector<vector<pii>> &adjList, int n)
{
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for (int u = 0; u < n; u++)
    {
        for (pii v : adjList[u])
        {
            dist[u][v.first] = min(dist[u][v.first], v.second);
        }
        dist[u][u] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min({dist[i][j], dist[i][k] + dist[k][j], dist[j][k] + dist[k][i]});
            }
        }
    }

    return dist;
}
