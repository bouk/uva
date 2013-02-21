#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <cstring>

using namespace std;

int longest;
int n;
set<string> substrings;
vector<string> dnas;

struct Trie
{
    Trie * children[26];
    // bitset<101> m;
    bool m[101];
    int count; 
};

void init_trie(Trie * t)
{
    memset(t->children, 0, sizeof(t->children));
    memset(t->m, 0, sizeof(t->m));
    
    t->count = 0;
}

int cti(char c)
{
    return c - 'a';
}

void add(string &s, Trie * t, int start, int pos, int m)
{
    int index = cti(s[pos]);
    if(!t->children[index])
    {
        t->children[index] = (Trie*)malloc(sizeof(Trie));
        init_trie(t->children[index]);
    }
    if(!t->children[index]->m[m])
    {
        t->children[index]->m[m] = true;
        t->children[index]->count++;
    }
    
    if(pos - start + 1 >= longest && t->children[index]->count > n/2)
    {
        if(pos - start + 1 > longest)
        {
            substrings.clear();
            longest = pos - start + 1;
        }
        substrings.insert(s.substr(start, pos - start + 1));
    }
    
    if(pos + 1 < s.size())
    {
        add(s, t->children[index], start, pos + 1, m);
    }
}

Trie * root;

int main()
{
    bool first = true;
    string input;
    while(!cin.eof() && cin >> n && n)
    {
        root = (Trie*)malloc(sizeof(Trie));
        init_trie(root);
        longest = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> input;
            dnas.push_back(input);
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < dnas[i].size(); j++)
            {
                add(dnas[i], root, j, j, i);
            }
        }
        
        vector<string> result(substrings.begin(), substrings.end());
        sort(result.begin(), result.end());
        if(!first)
        {
            cout << endl;
        }
        first = false;
        if(!result.size())
        {
            cout << "?" << endl;
        }
        else
        {
            for(int i = 0; i < result.size(); i++)
            {
                cout << result[i] << endl;
            }
        }
        substrings.clear();
        dnas.clear();
        delete root;
    }
    return 0;
}