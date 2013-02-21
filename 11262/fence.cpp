#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>

using namespace std;

#define MAX_N 100

typedef pair<int, int> ii;
typedef pair<short, short> ss;

int N;
int P;
int k;

ii poles[MAX_N];
bool color[MAX_N];
char buffer[10];

int best

int main()
{
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d %d", &P, &k);
        for(int i = 0; i < P; i++)
        {
            scanf("%d %d %s", &poles[i].first, &poles[i].second, buffer);
            color[i] = buffer[0] == 'r';
        }
        if(k > P/2)
        {
            printf("Impossible\n");
            continue;
        }
        printf("DERP\n");
    }
    return 0;
}
