#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef unsigned short us;

#define COMBINATIONS 1 << 10

int h;
int w;

char map[51][51];

char c;
// 0 = pirate, rest is treasure
int dist[15][15];
bool been[51][51];

int optimal[15][COMBINATIONS];

vector<ii> treasures;

queue<ii> * bfs = new queue<ii>;
queue<ii> * next = new queue<ii>;

ii b;

int best(int pos, us visited)
{
    // printf("%d %d %d %d\n", pos, visited, (1 << treasures.size()) - 1, 1 << pos);
    // Visited all except end
    if(visited == (1 << treasures.size()) - 1)
    {
        return dist[pos][0];
    }

    if(optimal[pos][visited] != -1)
    {
        return optimal[pos][visited];
    }

    optimal[pos][visited] = 1e9;


    for(int i = 0; i < (int)treasures.size(); i++)
    {
        if(!(visited & (1 << i)))
        {
            optimal[pos][visited] = min(optimal[pos][visited], dist[pos][i + 1]
                + best(i + 1, visited | (1 << i)));
        }
    }

    return optimal[pos][visited];
}

int main()
{
    while(scanf("%d %d\n", &h, &w) != EOF && w && h)
    {
        treasures.clear();
        for(int y = 0; y < h; y++)
        {
            gets(map[y]);
        }
        for(int y = 0; y < h; y++)
        {
            for(int x = 0; x < w; x++)
            {
                switch(map[y][x])
                {
                    case '@':
                    b = ii(x, y);
                    break;
                    case '~':
                    case '#':
                    map[y][x] = 'X';
                    break;
                    case '*':
                    for(int i = y-1; i <= y+1; i++)
                    {
                        for(int j = x-1; j <= x+1; j++)
                        {
                            if(i < 0 || j < 0 || i >= h || j >= w)
                            {
                                continue;
                            }
                            if(map[i][j] == '@' || map[i][j] == '!')
                            {
                                printf("-1\n");
                                goto next;
                            }
                            if(map[i][j] != '*')
                            {
                                map[i][j] = 'X';
                            }
                        }
                    }
                    break;
                    case '!':
                    map[y][x] = 'A' + treasures.size();
                    treasures.push_back(ii(x, y));
                    break;
                }
            }
        }
        for(int i = 0; i < (int)treasures.size() + 1; i++)
        {
            ii from;
            dist[i][i] = 0;
            memset(been, false, sizeof(been));
            if(i == 0)
            {
                from = b;
            }
            else
            {
                from = treasures[i-1];
            }
            while(!bfs->empty())
            {
                bfs->pop();
            }
            while(!next->empty())
            {
                next->pop();
            }
            bfs->push(from);
            been[from.second][from.first] = true;
            int iterations = 0;
            int treasures_found = 0;
            while(!bfs->empty())
            {
                iterations++;
                while(!bfs->empty())
                {
                    ii a = bfs->front();
                    bfs->pop();
                    if(a.first - 1 >= 0 && !been[a.second][a.first - 1])
                    {
                        c = map[a.second][a.first - 1];
                        if(c == '@')
                        {
                            dist[i][0] = iterations;
                        }
                        else if(c >= 'A' && c < 'X')
                        {
                            treasures_found++;
                            dist[i][c - 'A' + 1] = iterations;
                        }
                        if(c != 'X' && !been[a.second][a.first - 1])
                        {
                            next->push(ii(a.first - 1, a.second));
                            been[a.second][a.first - 1] = true;
                        }
                    }
                    if(a.first + 1 < w && !been[a.second][a.first + 1])
                    {
                        c = map[a.second][a.first + 1];
                        if(c == '@')
                        {
                            dist[i][0] = iterations;
                        }
                        else if(c >= 'A' && c < 'X')
                        {
                            treasures_found++;
                            dist[i][c - 'A' + 1] = iterations;
                        }
                        if(c != 'X' && !been[a.second][a.first + 1])
                        {
                            next->push(ii(a.first + 1, a.second));
                            been[a.second][a.first + 1] = true;
                        }
                    }
                    if(a.second - 1 >= 0 && !been[a.second - 1][a.first])
                    {
                        c = map[a.second - 1][a.first];
                        if(c == '@')
                        {
                            dist[i][0] = iterations;
                        }
                        else if(c >= 'A' && c < 'X')
                        {
                            treasures_found++;
                            dist[i][c - 'A' + 1] = iterations;
                        }
                        if(c != 'X' && !been[a.second - 1][a.first])
                        {
                            next->push(ii(a.first, a.second - 1));
                            been[a.second - 1][a.first] = true;
                        }
                    }
                    if(a.second + 1 < h && !been[a.second + 1][a.first])
                    {
                        c = map[a.second + 1][a.first];
                        if(c == '@')
                        {
                            dist[i][0] = iterations;
                        }
                        else if(c >= 'A' && c < 'X')
                        {
                            treasures_found++;
                            dist[i][c - 'A' + 1] = iterations;
                        }
                        if(c != 'X' && !been[a.second + 1][a.first])
                        {
                            next->push(ii(a.first, a.second + 1));
                            been[a.second + 1][a.first] = true;
                        }
                    }
                }
                queue<ii> * temp = bfs;
                bfs = next;
                next = temp;
            }
            if(i == 0 && treasures_found < treasures.size())
            {
                printf("-1\n");
                goto next;
            }
        }
        memset(optimal, -1, sizeof(optimal));
        printf("%d\n", best(0, 0));
        // printf("   ");
        // for(int y = 0; y <= treasures.size(); y++)
        // {
        //     printf("%02d ", y);
        // }
        // printf("\n");

        // for(int x = 0; x <= treasures.size(); x++)
        // {
        //     printf("%02d", x);
        //     for(int y = 0; y <= treasures.size(); y++)
        //     {
        //         printf(" %02d", dist[y][x]);
        //     }
        //     printf("\n");
        // }
        // printf("%d %d\n", dist[0][5], dist[0][4]);
        next:
        continue;
    }
}