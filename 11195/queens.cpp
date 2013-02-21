#include <iostream>
#include <bitset>

using namespace std;

int n;

bitset<15> placeable[15];
// y position for each x
int place[15];

// wether there is a piece in this row
bitset<15> rowtaken;
bitset<29> diagtaken;
bitset<29> diag2taken;

int possibilities;

bool canplace(int x, int y)
{
    return !rowtaken[y] && !diagtaken[x + y] && !diag2taken[n-1-x+y] && placeable[x][y];
}

void dumpboard()
{
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            if(place[y] == x)
            {
                cout << "Q";
            }
            else
            {
                cout << (placeable[y][x] ? '.' : '*');
            }
        }
        cout << endl;
    }
    cout << endl;
}

void go(int indexx)
{
    if(indexx == n)
    {
        possibilities++;
        return;
    }

    for(int y = 0; y < n; y++)
    {
        if(canplace(indexx, y))
        {
            place[indexx] = y;
            rowtaken[y] = diagtaken[indexx + y] = diag2taken[n-1-indexx+y] = true;
            go(indexx + 1);
            diag2taken[n-1-indexx+y] = diagtaken[indexx + y] = rowtaken[y] = false;
            place[indexx] = -1;
        }
    }
}

int main()
{
    int testcase = 1;
    while(!cin.eof())
    {
        possibilities = 0;
        cin >> n;
        if(!n)
        {
            break;
        }
        char c;
        for(int y = 0; y < n; y++)
        {
            for(int x = 0; x < n; x++)
            {
                cin >> c;
                placeable[y][x] = (c == '.');
            }
            place[y] = -1;
        }
        rowtaken.reset();
        diag2taken.reset();
        diagtaken.reset();
        for(int y = 0; y < n; y++)
        {
            if(canplace(0, y))
            {
                place[0] = y;
                rowtaken[y] = diagtaken[y] = diag2taken[n-1+y] = true;
                go(1);
                diag2taken[n-1+y] = diagtaken[y] = rowtaken[y] = false;
                place[0] = -1;
            }
        }

        cout << "Case " << testcase << ": " << possibilities << endl;
        testcase++;
    }

    return 0;
}
