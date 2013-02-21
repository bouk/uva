#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define X first
#define Y second

int N;
char buffer[21];
char map[21][21];

ii start;
ii letters[28];
int letter_count;
queue<iii> bfs;
bool visited[21][21];
int waystoreach[21][21];

bool canmove(int cur, int x, int y)
{
    if(x >= N || x <= -1 || y >= N || y <= -1)
    {
        return false;
    }
    if(map[y][x] == '#')
    {
        return false;
    }
    if(map[y][x] >= 'A' && map[y][x] <= 'Z' && map[y][x] - 'A' > cur + 1)
    {
        return false;
    }
    return true;
}

bool isnext(int cur, char pos)
{
    return pos >= 'A' && pos <= 'Z' && pos-'A'-1 == cur;
}

int main()
{
    int c = 1;
    while(scanf("%d\n", &N) != EOF && N)
    {
        printf("Case %d: ", c);
        c++;
        letter_count = 0;
        for(int i = 0; i < N; i++)
        {
            gets(map[i]);
            for(int j = 0; j < N; j++)
            {
                if(map[i][j] >= 'A' && map[i][j] <= 'Z')
                {
                    letters[map[i][j]-'A'].X = j;
                    letters[map[i][j]-'A'].Y = i;
                    letter_count = max(letter_count, map[i][j]-'A'+1);
                }
            }
        }

        int dist = 0;
        int multiplier = 1;
        // Dist from every letter to the next
        for(int i = 0; i < letter_count - 1; i++)
        {
            int x = letters[i].X;
            int y = letters[i].Y;
            int nextx = letters[i+1].X;
            int nexty = letters[i+1].Y;
//            printf("n: %d %d\n", nextx, nexty);
            int bestdist = 200;
            int m = 0;

            memset(visited, false, sizeof(visited));
            memset(waystoreach, 0, sizeof(waystoreach));
            waystoreach[x][y] = 1;

            while(!bfs.empty())
            {
                bfs.pop();
            }
            bfs.push(iii(0, ii(x, y)));

            while(!bfs.empty())
            {
                iii p = bfs.front();
                ii pos = p.second;
  //              printf("%d %d %d\n", pos.X, pos.Y, p.first);
                bfs.pop();

                if(nextx == pos.X && nexty == pos.Y)
                {

    //            printf("!%d %d %d\n", pos.X, pos.Y, p.first);
                    if(p.first <= bestdist)
                    {
                        bestdist = p.first;
                        m+=waystoreach[pos.Y][pos.X];

                    }
                    else
                    {
                        goto nextletter;
                    }
                    continue;
                }
                if(visited[pos.X][pos.Y])
                {
                    continue;
                }
                visited[pos.X][pos.Y] = true;
                if(canmove(i, pos.X, pos.Y-1))
                {
                    waystoreach[pos.X][pos.Y-1]+=waystoreach[pos.X][pos.Y];
                    if(!visited[pos.X][pos.Y-1])
                    {
                        bfs.push(iii(p.first+1, ii(pos.X, pos.Y-1)));
                    }
                }
                if(canmove(i, pos.X, pos.Y + 1))
                {
                    waystoreach[pos.X][pos.Y+1]+=waystoreach[pos.X][pos.Y];
                    if(!visited[pos.X][pos.Y+1])
                    {
                        bfs.push(iii(p.first+1, ii(pos.X, pos.Y+1)));
                    }
                }
                if(canmove(i, pos.X-1, pos.Y))
                {
                    waystoreach[pos.X-1][pos.Y]+=waystoreach[pos.X][pos.Y];
                    if(!visited[pos.X-1][pos.Y])
                    {
                        bfs.push(iii(p.first+1, ii(pos.X-1, pos.Y)));
                    }
                }
                if(canmove(i, pos.X+1, pos.Y))
                {
                    waystoreach[pos.X+1][pos.Y]+=waystoreach[pos.X][pos.Y];
                    if(!visited[pos.X+1][pos.Y])
                    {
                        bfs.push(iii(p.first+1, ii(pos.X+1, pos.Y)));
                    }
                }
            }
            if(m == 0)
            {
                printf("Impossible\n");
                goto nextcase;
            }
nextletter:
            multiplier *= m;
//            printf("%d\n", bestdist);
            dist += bestdist;
            continue;
        }
        printf("%d %d\n", dist, multiplier);
nextcase:
        continue;
    }
    return 0;
}
