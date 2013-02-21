#include <cstdio>
#include <vector>

using namespace std;
// input for current testcase
vector<int> input;

// LNIS for position
vector<int> best;

void test()
{
    best.assign(input.size(), 1);
    int top = 0;
    for(int i = 0; i < (int)input.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(input[j] >= input[i])
            {
                best[i] = max(best[i], best[j] + 1);
            }
        }
        top = max(top, best[i]);
        // printf("%d ", best[i]);
    }
    // printf ("\n");
    printf("%d\n", top);
}

int main()
{
    int in;
    int tc = 1;
    while((scanf("%d", &in)) && in != -1)
    {
        if(tc != 1)
        {
            printf("\n");
        }
        input.clear();
        input.push_back(in);
        while(scanf("%d", &in) && in != -1)
        {
            input.push_back(in);
        }
        printf("Test #%d:\n", tc++);
        printf("  maximum possible interceptions: ");
        test();
    }
    return 0;
}
