#include <iostream>
#include <string>

using namespace std;

bool grid[10][10];
string name;
int minsteps = -1;

bool isdone()
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            if(!grid[x][y])
            {
                return false;
            }
        }
    }
    return true;
}

void flick(int x, int y)
{
    grid[x][y] = !grid[x][y];
    if(x + 1 < 10)
    {
        grid[x + 1][y] = !grid[x + 1][y];
    }
    if(y + 1 < 10)
    {
        grid[x][y + 1] = !grid[x][y + 1];
    }
    if(x - 1 >= 0)
    {
        grid[x - 1][y] = !grid[x - 1][y];
    }
    if(y - 1 >= 0)
    {
        grid[x][y - 1] = !grid[x][y - 1];
    }
}

bool notfilled(int x, int y)
{
    if(!grid[x][y])
    {
        return true;
    }
    if(x + 1 < 10)
    {
        if(!grid[x + 1][y])
        {
            return true;
        }
    }
    if(y + 1 < 10)
    {
        if(!grid[x][y + 1])
        {
            return true;
        }
    }
    if(x - 1 >= 0)
    {
        if(!grid[x - 1][y])
        {
            return true;
        }
    }
    if(y - 1 >= 0)
    {
        if(!grid[x][y - 1])
        {
            return true;
        }
    }
    return false;
}

void go(int indexx, int indexy, int steps)
{
    cout << steps << endl;
    if(isdone())
    {
        if(minsteps == -1 || steps < minsteps)
        {
            minsteps = steps;
        }
        return;
    }
    if(steps >= 100 || minsteps != -1 && steps >= minsteps)
    {
        return;
    }
    for(int y = indexy; y < 10; y++)
    {
        for(int x = indexx; x < 10; x++)
        {
            if(notfilled(x, y))
            {
                flick(x, y);
                go(x, y, steps + 1);
                flick(x, y);
            }
        }
    }
}

int main()
{
    while(!cin.eof())
    {
        cin >> name;
        cout << name << ' ';
        minsteps = -1;
        if(cin.eof())
        {
            break;
        }
        char c;
        for(int y = 0; y < 10; y++)
        {
            for(int x = 0; x < 10; x++)
            {
                cin >> c;
                grid[x][y] = (c == '#');
            }
        }
        go(0, 0, 0);
        if(minsteps != -1)
        {
            cout << minsteps << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        cout << endl;
    }
}
