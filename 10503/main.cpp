#include <iostream>

using namespace std;

struct piece
{
    int l;
    int r;
    bool flipped;
    bool used;
};
int n;
int m;
piece pieces[14];
piece first;
piece last;

int getright(int i)
{
    if(pieces[i].flipped)
    {
        return pieces[i].l;
    }
    else
    {
        return pieces[i].r;
    }
}

bool go(int pos, int previous)
{
    if(pos == n - 1)
    {
        for(int i = 0; i < m; i++)
        {
            if(pieces[i].used)
            {
                continue;
            }
            if((getright(previous) == pieces[i].l && last.l == pieces[i].r) 
               || (getright(previous) == pieces[i].r && last.l == pieces[i].l))
            {
                cout << "YES" << endl;
                return true;
            }
        }
        return false;
    }
    for(int i = 0; i < m; i++)
    {
        if(pieces[i].used)
        {
            continue;
        }
        if(getright(previous) == pieces[i].l)
        {
            pieces[i].used = true;
            if(go(pos + 1, i))
            {
                return true;
            }
            pieces[i].used = false;
        }
        else if(getright(previous) == pieces[i].r)
        {
            pieces[i].used = true;
            pieces[i].flipped = true;
            if(go(pos + 1, i))
            {
                return true;
            }
            pieces[i].flipped = false;
            pieces[i].used = false;
        }
    }
    return false;
}

int main()
{
    while(!cin.eof())
    {
        cin >> n;
        if(!n)
        {
            return 0;
        }
        cin >> m;
        cin >> first.l;
        cin >> first.r;
        first.flipped = false;
        
        cin >> last.l;
        cin >> last.r;
        last.flipped = false;
        
        for(int i = 0; i < m; i++)
        {
            cin >> pieces[i].l;
            cin >> pieces[i].r;
            pieces[i].flipped = false;
            pieces[i].used = false;
        }
        bool success = false;
        for(int i = 0; i < m; i++)
        {
            if(pieces[i].l == first.r)
            {
                pieces[i].used = true;
                if(go(1, i))
                {
                    success = true;
                    goto endloop;
                }
                pieces[i].used = false;
            }
            else if(pieces[i].r == first.r)
            {
                pieces[i].flipped = true;
                pieces[i].used = true;
                if(go(1, i))
                {
                    success = true;
                    goto endloop;
                }
                pieces[i].used = false;
                pieces[i].flipped = false;
            }
        }
        if(!success)
        {
            cout << "NO" << endl;
        }
        endloop:
            continue;
    }
}
