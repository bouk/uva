#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

struct junction
{
    list<uint> connections;
    uint component;
};

struct road
{
    uint from;
    uint to;
    uint size;
};

junction junctions[200000];
road roads[200000];
uint m;
uint n;
uint saved;

int sort_roads(const void * a, const void * b)
{
    return ((road*)a)->size - ((road*)b)->size;
}

void paint(uint j, uint color)
{
    junctions[j].component = color;
    for(list<uint>::iterator iter = junctions[j].connections.begin(); iter != junctions[j].connections.end(); iter++)
    {
        if(junctions[*iter].component != color)
        {
            paint(*iter, color);
        }
    }
}

int main()
{
    while(cin >> m && cin >> n && m && n)
    {
        saved = 0;
        for(uint i = 0; i < m; i++)
        {
            junctions[i].connections.clear();
            junctions[i].component = i;
        }
        for(uint i = 0; i < n; i++)
        {
            cin >> roads[i].from;
            cin >> roads[i].to;
            cin >> roads[i].size;
        }

        qsort(roads, n, sizeof(road), sort_roads);
        for(uint i = 0; i < n; i++)
        {
            if(junctions[roads[i].from].component != junctions[roads[i].to].component)
            {
                paint(roads[i].to, junctions[roads[i].from].component);
                junctions[roads[i].to].connections.push_back(roads[i].from);
                junctions[roads[i].from].connections.push_back(roads[i].to);
            }
            else
            {
                saved += roads[i].size;
            }
        }
        cout << saved << endl;
    }
}
