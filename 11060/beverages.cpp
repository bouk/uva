#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef map<string, int> msi;
typedef vector<int> vi;

int N;
int M;
msi bev;
vector<vi> adjList;
vector<bool> visited;
vector<string> names;
vector<int> degree;
vi order;
void dfs(int i)
{
    visited[i] = true;
    for(size_t j = 0; j < adjList[i].size(); j++)
    {
        if(!visited[adjList[i][j]])
        {
            dfs(adjList[i][j]);
        }
    }
    order.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    while(cin >> N)
    {
        bev.clear();
        order.clear();
        visited.assign(N, false);
        names.resize(N);
        degree.assign(N, 0);
        adjList.assign(N, vi());

        for(int i = 0; i < N; i++)
        {
            cin >> names[i];
            bev[names[i]] = i;
        }

        cin >> M;
        for(int i = 0; i < M; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            adjList[bev[s1]].push_back(bev[s2]);
            degree[bev[s2]]++;
        }

        cout << "Case #" << t  << ": Dilbert should drink beverages in this order:";
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(degree[j] == 0)
                {
                    cout << " " << names[j];
                    degree[j]--;
                    for(size_t s = 0; s < adjList[j].size(); s++)
                    {
                        degree[adjList[j][s]]--;
                    }
                    goto next;
                }
            }
next:
            continue;
        }
        cout << "." << endl << endl;
        t++;
    }
}
