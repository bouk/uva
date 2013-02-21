#include <cstdio>

using namespace std;

int N;
int number;
bool first;

int main()
{
    while(scanf("%d", &N) != EOF && N)
    {
        first = true;
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &number);
            if(number)
            {
                if(!first)
                {
                    printf(" ");
                }
                first = false;
                printf("%d", number);
            }
        }
        if(first)
        {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
