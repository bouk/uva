#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;
typedef vector<int> vi;
int N;
vi ft;
vi vals;
inline int ls_bit(int i)
{
    return i & (-i);
}

void adjust(int i, int n)
{
    for(; i < (int)ft.size(); i += ls_bit(i))
    {
        ft[i] += n;
    }
}

int measure(int n)
{
    int sum = 0;
    for(; n; n -= ls_bit(n))
    {
        sum += ft[n];
    }
    return sum;
}

int main()
{
    int T = 0;
    while(scanf("%d\n", &N) != EOF && N)
    {
        if(T)
        {
            printf("\n");
        }
        T++;
        printf("Case %d:\n", T);
        ft.assign(N + 1, 0);
        vals.assign(N + 1, 0);
        for(int i = 1; i <= N; i++)
        {
            int v;
            scanf("%d\n", &v);
            adjust(i, v);
            vals[i] = v;
        }
        char c;
        for(;;)
        {
            scanf("%c", &c);
            if(c == 'E')
            {
                scanf("ND\n");
                break;
            }
            int a, b;
            scanf("%d %d\n", &a, &b);
            if(c == 'M')
            {
                printf("%d\n", measure(b) - measure(a - 1));
            }
            else if(c == 'S')
            {
                adjust(a, b - vals[a]);
                vals[a] = b;
            }
            else
            {
                assert(0);
            }
        }
    }
}
