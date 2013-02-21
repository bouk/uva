#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;
class Trie
{
    
public:
    Trie()
    {
        for(int i = 0; i < 4; i++)
        {
            this->children[i] = 0;
        }
        this->m[0] = false;
        this->m[1] = false;
    };
    
    ~Trie()
    {
        for(int i = 0; i < 4; i++)
        {
            if(this->children[i])
            {
                delete this->children[i];
            }
        }
    };
    
    Trie * children[4];
    // mark
    bool m[2];
};

int cti(char c)
{
    switch(c)
    {
        case 'a':
            return 0;
            break;
        case 't':
            return 1;
            break;
        case 'c':
            return 2;
            break;
        case 'g':
            return 3;
            break;
        default:
            return -1;
            break;
    }
}

Trie * root;

int longest;

set<string> substrings;

string a;
string b;
bool first = true;

void add(Trie * t, string &s, int start, int pos, int m)
{
    int i = cti(s[pos]);
    if(!t->children[i])
    {
        t->children[i] = new Trie;
    }
    t->children[i]->m[m] = true;
    
    // Detect common ss
    if(t->children[i]->m[0] && t->children[i]->m[1])
    {
        if(pos - start + 1 > longest)
        {
            substrings.clear();
            longest = pos - start + 1;
        }
        if(pos - start + 1 >= longest)
        {
            substrings.insert(s.substr(start, pos - start + 1));
        }
    }
    
    if(pos + 1 < s.size())
    {
        add(t->children[i], s, start, pos + 1, m);
    }
}


int main()
{
    while(!cin.eof() && cin >> a && cin >> b && a.size() && b.size())
    {
        root = new Trie;
        longest = 0;
        if(!first)
        {
            cout << endl;
        }
        first = false;
        
        for(int i = 0; i < a.size(); i++)
        {
            add(root, a, i, i, 0);
        }
        
        for(int i = 0; i < b.size(); i++)
        {
            add(root, b, i, i, 1);
        }
        vector<string> result(substrings.begin(), substrings.end());
        sort(result.begin(), result.end());
        if(result.size() == 0)
        {
            cout << "No common sequence." << endl;
        }
        else
        {
            for(int i = 0; i < result.size(); i++)
            {
                cout << result[i] << endl;
            }
        }
        delete root;
        substrings.clear();
        result.clear();
    }
    return 0;
}