#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <string>

using namespace std;

struct trie
{
    trie * c[26];
    bool w;
};

trie * root;

char board[4][4];
string buffer;
string curword;
set<string> found;
int buflen;
int N;
int M;

trie * init_trie()
{
    trie * t = new trie;
    memset(t->c, 0, sizeof(t->c));
    t->w = 0;
    return t;
}

void remove_trie(trie * t)
{
    for(int i = 0; i < 26; i++)
    {
        if(t->c[i])
        {
            remove_trie(t->c[i]);
        }
    }
    delete t;
}

int cti(char c)
{
    return c - 'A';
}

void add(int pos, trie * t, string &s)
{
    if(pos == ((int)s.size()))
    {
        t->w = true;
        return;
        // cout << endl << s << endl;
    }
    int i = cti(s[pos]);
    // cout << i << ' ';
    if(!t->c[i])
    {
        t->c[i] = init_trie();
    }

    add(pos+1, t->c[i], s);
}

void findword(int x, int y, trie * t)
{
    if(t->w)
    {
        found.insert(curword);
        // cout << curword << endl;
    }
    // for(int i = 0; i < 4; i++)
    // {
    //     for(int j = 0; j < 4; j++)
    //     {
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }

            if(x+i < 0 || y+j<0 || x+i > 3 || y+j > 3)
            {
                continue;
            }
            char c = board[y+j][x+i];
            // if(y+j == 1 && x+i == 1)
            // {
            //     cout << c << endl;
            // }
            int index = cti(c);

            if(c != 'x' && t->c[index])
            {
                board[y+j][x+i] = 'x';
                curword.push_back(c);
                findword(x+i, y+j, t->c[index]);
                curword.resize(curword.size()-1);
                board[y+j][x+i] = c;
            }
        }
    }
}

int main()
{
    cin >> N;
    getline(cin, buffer);
    for(int cas = 1; cas <= N; cas++)
    {
        root = init_trie();
        found.clear();
        printf("Score for Boggle game #%d: ", cas);
        getline(cin, buffer);

        for(int i = 0; i < 4; i++)
        {
            getline(cin, buffer);
            for(int j = 0; j < 4; j++)
            {
                board[i][j] = buffer[j];
            }
        }
        cin >> M;
        getline(cin, buffer);
        for(int i = 0; i < M; i++)
        {
            getline(cin, buffer);
            add(0, root, buffer);
        }
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                char c = board[y][x];
                int i = cti(c);
                if(root->c[i])
                {
                    board[y][x] = 'x';

                    curword.resize(1);
                    curword[0] = c;
                    findword(x, y, root->c[i]);
                    board[y][x] = c;
                }
            }
        }

        int score = 0;
        for(set<string>::iterator iter = found.begin(); iter != found.end(); iter++)
        {
            string s = *iter;
            if(s.size() > 7)
            {
                score += 11;
            }
            else if(s.size() == 7)
            {
                score += 5;
            }
            else if(s.size() == 6)
            {
                score += 3;
            }
            else if(s.size() == 5)
            {
                score += 2;
            }
            else if(s.size() == 4 || s.size() == 3)
            {
                score += 1;
            }
        }
        printf("%d\n", score);
        remove_trie(root);
    }
}