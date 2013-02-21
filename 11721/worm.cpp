#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>

using namespace std;
#define INF 1e9
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int T;
int n;
int m;

vector<vii> adjList;
vector<vi> fromList;
vi dist;
bitset<1001> hasNegative;
set<int> startpoints;
bitset<1001> visited;

void allReachable(int v)
{
    visited[v] = true;
    queue<int> q;
    q.push(v);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)fromList[u].size(); i++)
        {
            int z = fromList[u][i];
            if(!visited[z])
            {
                startpoints.insert(z);
                visited[z] = true;
                q.push(z);
            }
        }
    }
}

int main()
{
    scanf("%d", &T);

    for(int cas = 1; cas <= T; cas++)
    {
        printf("Case %d:", cas);
        scanf("%d %d", &n, &m);

        adjList.assign(n, vii());
        hasNegative.reset();
        visited.reset();
        startpoints.clear();
        fromList.assign(n, vi());

        int x;
        int y;
        int t;
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &x, &y, &t);
            adjList[x].push_back(ii(y, t));
            if(t < 0)
            {
                hasNegative[x] = true;
            }
            fromList[y].push_back(x);
        }

        bool found = false;

        for(int s = 0; s < n; s++)
        {
            if(!hasNegative[s] && !visited[s])
            {
                continue;
            }
            dist.assign(n, INF);
            dist[0] = 0;
            for(int i = 0; i < n-1; i++)
            {
                for(int u = 0; u < n; u++)
                {
                    for(int j = 0; j < (int)adjList[u].size(); j++)
                    {
                        ii v = adjList[u][j];
                        if(dist[u] + v.second < dist[v.first])
                        {
                            dist[v.first] = dist[u] + v.second;
                        }
                    }
                }
            }

            for(int u = 0; u < n; u++)
            {
                for(int j = 0; j < (int)adjList[u].size(); j++)
                {
                    ii v = adjList[u][j];
                    if(dist[u] + v.second < dist[v.first])
                    {
                        startpoints.insert(s);
                        allReachable(s);
                        found = true;
                        goto nextsource;
                    }
                }
            }
            nextsource:
            continue;
        }

        vi starters(startpoints.begin(), startpoints.end());
        sort(starters.begin(), starters.end());
        for(int i = 0; i < (int)starters.size(); i++)
        {
            printf(" %d", starters[i]);
        }

        if(!found)
        {
            printf(" impossible");
        }
        printf("\n");

    }
    return 0;
}