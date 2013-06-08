#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

int N, K;

inline int ls_bit(int i)
{
    return i & (-i);
}

vector<int> neg;
vector<int> zero;
vector<int> stored;

void adjust(vi &a, int pos, int val)
{
    for(; pos < (int)a.size(); pos += ls_bit(pos))
    {
        a[pos] += val;
    }
}

int sum(vi &a, int from, int to)
{
    int upper = 0;
    int lower = 0;

    for(from--; from; from -= ls_bit(from))
    {
        lower += a[from];
    }

    for(; to; to -= ls_bit(to))
    {
        upper += a[to];
    }
    return upper - lower;
}

int main()
{
    while(scanf("%d %d\n", &N, &K) != EOF)
    {
        neg.assign(N + 1, 0);
        zero.assign(N + 1, 0);
        stored.assign(N + 1, 0);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &stored[i]);
            if(stored[i] < 0)
            {
                adjust(neg, i, 1);
            }
            else if(stored[i] == 0)
            {
                adjust(zero, i, 1);
            }
        }
        scanf("\n");
        for(int i = 0; i < K; i++)
        {
            char c;
            int a, b;
            scanf("%c %d %d\n", &c, &a, &b);
            if(c == 'C')
            {
                if(stored[a] < 0)
                {
                    adjust(neg, a, -1);
                }
                else if(stored[a] == 0)
                {
                    adjust(zero, a, -1);
                }
                stored[a] = b;
                if(b < 0)
                {
                    adjust(neg, a, 1);
                }
                else if(b == 0)
                {
                    adjust(zero, a, 1);
                }
            }
            else if(c == 'P')
            {
                if(sum(zero, a, b) > 0)
                {
                    printf("0");
                }
                else if(sum(neg, a, b) % 2 == 1)
                {
                    printf("-");
                }
                else
                {
                    printf("+");
                }
            }
            else
            {
                printf("nope\n");
            }
        }
        printf("\n");
    }
}
