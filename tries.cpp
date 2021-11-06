#include <bits/stdc++.h>

using namespace std;

class tries
{
    struct node
    {
        vector<node *> childs;
        bool isEnd;
    };

    node *getNode()
    {
        node *temp = new node;
        temp->isEnd = false;

        for (int i = 0; i < 256; i++)
            (temp->childs).push_back(nullptr);

        return temp;
    }

public:
    node *root;

    tries()
    {
        root = getNode();
    }

    void insert(string s)
    {
        int n = s.size();
        node *temp = root;
        for (int i = 0; i < n; i++)
        {
            if (!temp->childs[s[i]])
                temp->childs[s[i]] = getNode();

            temp = temp->childs[s[i]];
        }

        temp->isEnd = true;
    }

    bool search(string s)
    {
        int n = s.size();
        node *temp = root;
        for (int i = 0; i < n; i++)
        {
            if (!temp->childs[s[i]])
                return false;

            temp = temp->childs[s[i]];
        }

        return temp->isEnd;
    }

    bool isPrefix(string s)
    {
        int n = s.size();
        node *temp = root;
        for (int i = 0; i < n; i++)
        {
            if (!temp->childs[s[i]])
                return false;

            temp = temp->childs[s[i]];
        }

        return true;
    }
};

int main()
{
    tries t;
    t.insert("abc");
    t.insert("abcd");
    string s = "abcd";
    t.search(s) ? cout << s << " found\n" : cout << s << " not found\n";
    s = "abc";
    t.search(s) ? cout << s << " found\n" : cout << s << " not found\n";
    s = "fds";
    t.search(s) ? cout << s << " found\n" : cout << s << " not found\n";

    s = "ab";
    t.isPrefix(s) ? cout << s << " is prefix\n" : cout << s << " not is prefix\n";

    s = "tl";
    t.isPrefix(s) ? cout << s << " is prefix\n" : cout << s << " not is prefix\n";

    return 0;
}