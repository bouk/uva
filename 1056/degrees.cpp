#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <map>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef map<string, int> msi;
typedef pair<int, int> ii;

int P;
int R;

vector<vi> adjList;
msi names;

int stoi(string &s)
{
    msi::iterator i = names.find(s);
    if(i == names.end())
    {
        int n = names.size();
        return names[s] = n;
    }
    else
    {
        return i->second;
    }
}


string from;
string to;
int main()
{
    int iteration = 1;
    while(true)
    {
        cin >> P >> R;
        if(!P && !R)
        {
            return 0;
        }
        if(iteration != 1)
        {
        }
        cout << "Network " << (iteration++) << ": ";
        adjList.assign(P, vi());
        names.clear();
        while(R--)
        {
            cin >> from >> to;
            int f = stoi(from);
            int t = stoi(to);
            // cerr << from << " " << f << " " << to << " " << t << endl;
            adjList[f].push_back(t);
            adjList[t].push_back(f);
        }
        int biggest_degree = 0;
        vector<int> dist;
        for(int i = 0; i < P; i++)
        {
            queue<ii> q;
            q.push(ii(i, 0));
            int found = 0;
            dist.assign(P, -1);
            dist[i] = 0;
            while(!q.empty())
            {
                found++;
                int pos = q.front().first;
                int d = q.front().second;
                biggest_degree = max(biggest_degree, d);
                q.pop();

                for(int j = 0; j < (int)adjList[pos].size(); j++)
                {
                    int p2 = adjList[pos][j];
                    if(dist[p2] == -1)
                    {
                        dist[p2] = d + 1;
                        q.push(ii(p2, d + 1));
                    }
                }
            }
            if(found != P)
            {
                cout << "DISCONNECTED" << endl;
                goto next;
            }
        }
        cout << biggest_degree << endl;
next:
            cout << endl;
        continue;
    }
}
