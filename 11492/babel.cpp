#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 1e6

struct edge
{
    int to;
    int length;
    int c;

    bool operator<(const edge &other) const
    {
        return length > other.length;
    }
};

int M;
string O;
string D;

map<string, int> mi;
vector<edge> adjList[4002];

int id(string &s)
{
    if(mi.find(s) != mi.end())
    {
        return mi[s];
    }
    int i = mi.size();
    mi[s] = i;
    adjList[i].clear();
    return i;
}

int cti(char c)
{
    return c - 'a';
}
edge t;

int main()
{
    while(cin >> M && M)
    {
        mi.clear();
        cin >> O >> D;
        for(int i = 0; i < M; i++)
        {
            string from;
            string to;
            string word;
            cin >> from >> to >> word;
            int u = id(to);
            int v = id(from);
            t.to = u;
            t.length = word.size();
            t.c = cti(word[0]);
            adjList[v].push_back(t);
            t.to = v;
            adjList[u].push_back(t);
        }

        if(mi.find(O) == mi.end() || mi.find(D) == mi.end())
        {
            cout << "impossivel" << endl;
            continue;
        }
        int dist[4002][27];
        for(size_t i = 0; i < mi.size(); i++)
        {
            for(int j = 0; j < 26; j++)
            {
                dist[i][j] = INF;
            }
        }
        int s = id(O);
        int end = id(D);
        for(int i = 0; i <= 26; i++)
        {
            dist[s][i] = 0;
        }
        priority_queue<edge> pq;
        t.to = s;
        t.length = 0;
        t.c = 26;
        pq.push(t);
        while(!pq.empty())
        {
            edge e = pq.top();
            pq.pop();
            if(dist[e.to][e.c] == e.length)
            {
                for(size_t i = 0; i < adjList[e.to].size(); i++)
                {
                    edge &lul = adjList[e.to][i];
                    if(lul.c != e.c && lul.length + e.length < dist[lul.to][lul.c])
                    {
                        dist[lul.to][lul.c] = t.length = lul.length + e.length;
                        t.to = lul.to;
                        t.c = lul.c;
                        pq.push(t);
                    }
                }
            }
        }
end:
        int best = dist[end][0];
        for(int i = 1; i < 26; i++)
        {
            best = min(best, dist[end][i]);
        }
        if(best == INF)
        {
            cout << "impossivel" << endl;
        }
        else
        {
            cout << best << endl;
        }
    }
}
