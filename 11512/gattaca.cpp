#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>

using namespace std;

struct trie
{
    trie * children[4];
    int count;
};

int T;
int longest;
string current;
int reps;
string input;
trie * root;

trie * init_trie()
{
    trie * result = (trie*)malloc(sizeof(trie));
    for(int i = 0; i < 4; i++)
    {
        result->children[i] = 0;
        result->count = 0;
    }
    return result;
}

void delete_trie(trie * t)
{
    for(int i = 0; i < 4; i++)
    {
        if(t->children[i])
        {
            delete_trie(t->children[i]);
        }
    }
    free(t);
}

void reset_trie(trie * t)
{
    for(int i = 0; i < 4; i++)
    {
        if(t->children[i])
        {
            delete_trie(t->children[i]);
            t->children[i] = 0;
        }
    }
    t->count = 0;
}

int cti(char c)
{
    switch(c)
    {
        case 'G':
            return 0;
            break;
        case 'A':
            return 1;
            break;
        case 'T':
            return 2;
            break;
        case 'C':
            return 3;
            break;
        default:
            return -1;
            break;
    }
}

void add(string &s, int start, int pos, trie * t)
{
    int index = cti(s[pos]);
    if(!t->children[index])
    {
        t->children[index] = init_trie();
        t->children[index]->count = 1;
    }
    else
    {
        t->children[index]->count++;
        
        string sub = s.substr(start, pos - start + 1);
        if(pos - start + 1 > longest)
        {
            longest = pos - start + 1;
            current = sub;
            reps = 2;
        }
        else if(pos - start + 1 == longest)
        {
            if(sub == current)
            {
                reps++;
            }
            else if(sub < current)
            {
                longest = pos - start + 1;
                current = sub;
                reps = 2;
            }
        }
    }
    
    if(pos + 1 < s.size())
    {
        add(s, start, pos + 1, t->children[index]);
    }
}

int main()
{
    cin >> T;
    root = init_trie();
    while(T--)
    {
        cin >> input;
        longest = 0;
        current = "";
        reps = 0;
        
        for(int i = 0; i < input.size(); i++)
        {
            add(input, i, i, root);
        }
        
        if(longest == 0)
        {
            cout << "No repetitions found!" << endl;
        }
        else
        {
            cout << current  << ' ' << reps << endl;
        }
        reset_trie(root);
    }
    return 0;
}