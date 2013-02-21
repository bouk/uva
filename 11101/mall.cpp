#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int blue_p;
int red_p;

char grid[2001][2001];

queue<ii> * blue_q = new queue<ii>;
queue<ii> * temp_q = new queue<ii>;
queue<ii> * red_q = new queue<ii>;
int result;
int blueiter = 0;
int rediter = 0;
#define WHITE 0
#define BLUE 1
#define RED 2

bool check(int x, int y)
{
    if(grid[x][y] == WHITE)
    {
        grid[x][y] = BLUE;
        ii p;
        p.first = x;
        p.second = y;
        temp_q->push(p);
    }
    else if(grid[x][y] == RED)
    {
        result = rediter + blueiter;
        return true;
    }
    return false;
}

int main()
{
    while(cin >> blue_p && blue_p)
    {
        memset(grid, WHITE, sizeof(grid)*sizeof(char));
        while(!blue_q->empty())
        {
            blue_q->pop();
        }
        while(!temp_q->empty())
        {
            temp_q->pop();
        }
        while(!red_q->empty())
        {
            red_q->pop();
        }
        while(blue_p--)
        {
            ii p;
            cin >> p.first;
            cin >> p.second;
            grid[p.first][p.second] = BLUE;
            blue_q->push(p);
        }
        cin >> red_p;
        while(red_p--)
        {
            ii p;
            cin >> p.first;
            cin >> p.second;
            grid[p.first][p.second] = RED;
            red_q->push(p);
        }
        rediter = 0;
        blueiter = 0;
        result = -1;

        while(!blue_q->empty())
        {
            blueiter++;
            while(!blue_q->empty())
            {
                ii p = blue_q->front();
                blue_q->pop();
                if(p.first > 0)
                {
                    if(check(p.first - 1, p.second))
                    {
                        goto ending;
                    }
                }
                if(p.first < 2000)
                {
                    if(check(p.first + 1, p.second))
                    {
                        goto ending;
                    }
                }
                if(p.second > 0)
                {
                    if(check(p.first, p.second - 1))
                    {
                        goto ending;
                    }
                }
                if(p.second < 2000)
                {
                    if(check(p.first, p.second + 1))
                    {
                        goto ending;
                    }
                }
            }
            queue<ii> * a = blue_q;
            blue_q = temp_q;
            temp_q = a;
        }
ending:
        cout << result << endl;
    }
    return 0;
}
