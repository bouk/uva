#include <cstdio>
#include <utility>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int m, n, q;
int price[1000];
vii adjList[1000];
// mincost to reach first with second in the tank
int cost[1000][101];
// iii: (cost, (position, fueltank))
priority_queue<iii, viii, greater<iii> > pq;

void query(int c, int s, int e)
{
    while(!pq.empty())
    {
        pq.pop();
    }
    pq.push(iii(0, ii(s, 0)));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= c; j++)
        {
            cost[i][j] = 1000000;
        }
    }
    cost[s][0] = 0;
    while(!pq.empty())
    {
        iii f = pq.top(); pq.pop();
        int totalprice = f.first;
        int pos = f.second.first;
        int fuel = f.second.second;
        if(pos == e)
        {
            printf("%d\n", totalprice);
            return;
        }
        if(cost[pos][fuel] == totalprice)
        {
            if(fuel > 0)
            {
                for(int v = 0; v < (int)adjList[pos].size(); v++)
                {
                    ii u = adjList[pos][v];
                    if(fuel-u.second >= 0 && totalprice < cost[u.first][fuel-u.second])
                    {
                        cost[u.first][fuel-u.second] = totalprice;
                        pq.push(iii(totalprice, ii(u.first, fuel-u.second)));
                    }
                }
            }
            if(fuel < c)
            {
                if(totalprice + price[pos] < cost[pos][fuel+1])
                {
                    cost[pos][fuel+1] = totalprice + price[pos];
                    pq.push(iii(totalprice + price[pos], ii(pos, fuel+1)));
                }
            }
        }
    }
    printf("impossible\n");
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &price[i]);
    }
    for(int i = 0; i < m; i++)
    {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        adjList[u].push_back(ii(v, d));
        adjList[v].push_back(ii(u, d));
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int c, s, e;
        scanf("%d %d %d", &c, &s, &e);
        query(c, s, e);
    }
    return 0;
}
