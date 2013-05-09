#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
typedef vector<int> vi;

struct freckle
{
    double x;
    double y;
};

double sq(double n)
{
    return n * n;
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(sq(x1 - x2) + sq(y1 - y2));
}
vector<freckle> freckles;
vector<int> component;
vector<vector<int> > adjList;

struct road
{
    double length;
    int from;
    int to;

    road(int f, int t)
    {
        this->from = f;
        this->to = t;
        this->length = dist(freckles[from].x, freckles[from].y, freckles[to].x, freckles[to].y);
    }

    bool operator<(const road &b) const
    {
        return length < b.length;
    }
};

int T;
int n;
vector<road> roads;

void color(int from, int c)
{
    component[from] = c;
    for(int i = 0; i < (int)adjList[from].size(); i++)
    {
        if(component[adjList[from][i]] != c)
        {
            color(adjList[from][i], c);
        }
    }
}

void testcase()
{
    scanf("%d", &n);
    freckles.resize(n);
    component.resize(n);
    adjList.assign(n, vi());
    roads.clear();
    for(int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &freckles[i].x, &freckles[i].y);
        component[i] = i;
    }
    for(int from = 0; from < n; from++)
    {
        for(int to = from + 1; to < n; to++)
        {
            roads.push_back(road(from, to));
        }
    }
    sort(roads.begin(), roads.end());
    double size = 0.0;
    for(int i = 0; i < (int)roads.size(); i++)
    {
        if(component[roads[i].from] != component[roads[i].to])
        {
            int from, to;
            from = roads[i].from;
            to = roads[i].to;
            size += roads[i].length;
            color(to, component[from]);
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }
    }
    printf("%.2lf\n", size);
}

int main()
{
    scanf("%d", &T);
    for(int t = 0; t < T; t++)
    {
        if(t > 0)
        {
            printf("\n");
        }
        testcase();
    }
    return 0;
}
