#include <vector>
#include <queue>
#include <cstdio>
#include <utility>
using namespace std;
#define INF 1e6
typedef pair<int, int> ii;
typedef vector<ii> vii;
int N;
int n, m, S, T;
vector<vii> adjList;
vector<int> dist;
priority_queue<ii, vector<ii>, greater<ii> > q;
int main()
{
    scanf("%d", &N);
    for(int t = 1; t <= N; t++)
    {
        printf("Case #%d: ", t);
        scanf("%d %d %d %d", &n, &m, &S, &T);
        adjList.assign(n, vii());
        dist.assign(n, INF);

        while(!q.empty()) q.pop();
        for(int i = 0; i < m; i++)
        {
            int from, to, w;
            scanf("%d %d %d", &from, &to, &w);
            adjList[from].push_back(ii(w, to));
            adjList[to].push_back(ii(w, from));
        }
        q.push(ii(0, S));
        dist[S] = 0;
        while(!q.empty())
        {
            ii u = q.top();
            q.pop();
            if(u.first == dist[u.second])
            {
                if(u.second == T)
                {
                    break;
                }
                for(size_t i = 0; i < adjList[u.second].size(); i++)
                {
                    ii v = adjList[u.second][i];
                    if(u.first + v.first < dist[v.second])
                    {
                        dist[v.second] = u.first + v.first;
                        q.push(ii(dist[v.second], v.second));
                    }
                }
            }
        }
        if(dist[T] != INF)
        {
            printf("%d\n", dist[T]);
        }
        else
        {
            printf("unreachable\n");
        }
    }
}
