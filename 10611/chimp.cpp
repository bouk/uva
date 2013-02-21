#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;
typedef pair<uint, uint> uu;

int N;
vector<uint> chimps;
int Q;
uint curq;

void query()
{
    int low = 0;
    int high = N-1;

    if(N == 1)
    {
        if(curq == chimps[0])
        {
            printf("X X\n");
        }
        else if(curq < chimps[0])
        {
            printf("X %d\n", chimps[0]);
        }
        else
        {
            printf("%d X\n", chimps[0]);
        }
        return;
    }

    while(low < high || curq == chimps[high])
    {
        int test = (low + high) / 2;
        if(curq == chimps[test])
        {
            if(test == 0)
            {
                printf("X %d\n", chimps[test+1]);
            }
            else if(test == N-1)
            {
                printf("%d X\n", chimps[test-1]);
            }
            else
            {
                printf("%d %d\n", chimps[test-1], chimps[test+1]);
            }
            return;
        }
        else if(curq < chimps[test])
        {
            high = test - 1;
        }
        else
        {
            low = test + 1;
        }
    }
    if(curq < chimps[high])
    {
        high--;
    }

    // printf(":%d %d %d\n", curq, low, high);
    if(high == -1)
    {
        printf("X %d\n", chimps[high + 1]);
    }
    else if(high == 0)
    {
        if(curq > chimps[high])
        {
            printf("%d %d\n", chimps[high], chimps[high + 1]);
        }
        else
        {
            printf("X %d\n", chimps[high]);
        }
    }
    else if(high == N-1)
    {
        printf("%d X\n", chimps[high]);
    }
    else
    {
        printf("%d %d\n", chimps[high], chimps[high+1]);
    }
}

int main()
{
    scanf("%d", &N);
    uint in;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &in);
        chimps.push_back(in);
    }
    N = unique(chimps.begin(), chimps.end()) - chimps.begin();
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++)
    {
        scanf("%d", &curq);
        query();
    }

    return 0;
}
