#include <cstdio>

using namespace std;

int a[10005];
int N;
int main()
{
    while(scanf("%d", &N) != EOF && N)
    {
        int best_total = 0;
        int current_total = 0;
        while(N --> 0)
        {
            int b;
            scanf("%d", &b);

            current_total += b;
            if(current_total < 0)
            {
                current_total = 0;
            }
            else if(current_total > best_total)
            {
                best_total = current_total;
            }
        }

        if(best_total > 0)
        {
            printf("The maximum winning streak is %d.\n", best_total);
        }
        else
        {
            printf("Losing streak.\n");
        }
    }
}
