
class disjointSet
{
    vector<int> arr;
    int n;

public:
    disjointSet(int n1)
    {
        n = n1;
        arr = vector<int>(n, -1);
    }

    int find(int a)
    {
        if (arr[a] < 0)
            return a;

        return arr[a] = find(arr[a]);
    }

    bool inSameSet(int a, int b)
    {
        int s1 = find(a), s2 = find(b);
        if (s1 == s2)
            return true;

        return false;
    }

    void uninon(int a, int b)
    {
        int s1 = find(a), s2 = find(b);
        if (arr[s1] > arr[s2]) //size of set s1 is small
        {
            arr[s2] += arr[s1];
            arr[s1] = s2;
        }
        else
        {
            arr[s1] += arr[s2];
            arr[s2] = s1;
        }
    }

    void printSet()
    {
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
};