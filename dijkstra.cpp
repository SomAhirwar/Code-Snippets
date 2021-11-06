#include <bits/stdc++.h>

vector<int> dijkstra(vector<vector<pii>> &adjList, int src, int n)
{
    vector<int> dist(n, 1e15);
    dist[0] = 0;

    vector<bool> visited(n, false);
    int leftVertex = n;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pii temp = pq.top();
        pq.pop();
        if (visited[temp.second])
            continue;

        visited[temp.second] = true;
        leftVertex--;
        if (leftVertex == 0)
            break;

        for (pii i : adjList[temp.second])
        {
            if (dist[temp.second] + i.second < dist[i.first])
            {
                dist[i.first] = dist[temp.second] + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }

    return dist;
}