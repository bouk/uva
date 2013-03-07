#include <cstdio>

using namespace std;

int main()
{
    int N;
    int i = 1;
    while(scanf("%d", &N) != EOF && N)
    {
        int should = 0;
        int has = 0;
        while(N--)
        {
            int c;
            scanf("%d", &c);
            if(c)
            {
                should++;
            }
            else
            {
                has++;
            }
        }
        printf("Case %d: %d\n", i++, should - has);
    }
}
