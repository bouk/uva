#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

#define MAX_N 8
#define COMBINATIONS 1 << 2*MAX_N + 1
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;

typedef unsigned short us;

int N;
int current_case = 0;
ii students[2*MAX_N];

// Minimum combination
double mc[COMBINATIONS];

char buffer[21];

// Dist between two students
double dist(int a, int b)
{
    return sqrt((double)((students[a].first - students[b].first)*(students[a].first - students[b].first) + (students[a].second - students[b].second)*(students[a].second - students[b].second)));
}

// Calculate optimal combination with given students
double optimal(us s)
{
    if(s == 0)
    {
        return 0;
    }
    if(!(mc[s] > 1e9))
    {
        return mc[s];
    }
    for(int i = 0; i < 2*N; i++)
    {
        if(s & (1 << i))
        {
            for(int j = i + 1; j < 2*N; j++)
            {
                if(s & (1 << j))
                {
                    us test = s & ~(1 << i) & ~(1 << j);
                    mc[s] = min(mc[s], dist(i, j) + optimal(test));
                }
            }
        }
    }
    return mc[s];
}

int main()
{
    mc[0] = 0;
    while(scanf("%d", &N) != EOF && N)
    {
        current_case++;
        for(int i = 0; i < 2*N; i++)
        {
            scanf("%s %d %d", &buffer, &students[i].first, &students[i].second);
        }
        for(int i = 1; i < (1 << 2*N + 1); i++)
        {
            // Set best distance to infinity
            mc[i] = 1e10;
        }
        us start = 0;
        for(int i = 0; i < 2*N; i++)
        {
            start |= (1 << i);
        }

        double result = optimal(start);
        printf("Case %d: %0.2f\n", current_case, result);
    }
    return 0;
}