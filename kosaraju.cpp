#include <bits/stdc++.h>

using namespace std;

void dfs1(vector<vector<int>> &adjList, int src, vector<bool> &visited, stack<int> &s)
{
    visited[src] = true;

    for (int i : adjList[src])
    {
        if (!visited[i])
            dfs1(adjList, i, visited, s);
    }

    s.push(src);
}

void dfs2(vector<vector<int>> &adjList, int src, vector<bool> &visited, vector<int> &who, int respresentative)
{
    visited[src] = true;
    who[src] = respresentative;
    for (int i : adjList[src])
        if (!visited[i])
            dfs2(adjList, i, visited, who, respresentative);
}

vector<int> kosaraju(vector<vector<int>> &adjList, int n)
{
    vector<bool> visited(n, false);
    stack<int> functionCallFinishStack;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(adjList, i, visited, functionCallFinishStack);

    vector<vector<int>> transposeAdjList(n);
    for (int i = 0; i < n; i++)
        for (int j : adjList[i])
            transposeAdjList[j].push_back(i);

    visited = vector<bool>(n, false);
    vector<int> who(n);
    while (!functionCallFinishStack.empty())
    {
        int src = functionCallFinishStack.top();
        functionCallFinishStack.pop();
        if (visited[src])
            continue;

        dfs2(transposeAdjList, src, visited, who, src);
    }

    return who;
}