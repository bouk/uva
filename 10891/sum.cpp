#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;

int numbers[100];

ii sub(int start, int end, int delta)
{
    int score = 0;
    int pos = start;
    int best = numbers[start];
    int bestpos = start;
    do
    {
        score += numbers[pos];
        if(score > best)
        {
            best = score;
            bestpos = pos;
        }
        pos += delta;
    }
    while((delta == 1 && pos <= end) || (delta == -1 && pos >= end));

    return ii(best, bestpos);
}

iii bestsubsum(int start, int end)
{
    ii bestfront = sub(start, end, 1);
    ii bestback = sub(end, start, -1);
    printf("%d:%d %d:%d\n", bestfront.first, bestfront.second, bestback.first, bestback.second);
    if(bestfront.first > bestback.first)
    {
        return iii(bestfront.first, ii(bestfront.second + 1, end));
    }
    else
    {
        return iii(bestback.first, ii(start, bestback.second - 1));
    }
}

int main()
{
    while(scanf("%d", &n) != EOF && n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &numbers[i]);
        }
        int start = 0;
        int end = n-1;
        int totala = 0;
        int totalb = 0;

        while(start <= end)
        {
            iii a = bestsubsum(start, end);
            start = a.second.first;
            end = a.second.second;
            totala += a.first;

            if(start <= end)
            {
                a = bestsubsum(start, end);
                start = a.second.first;
                end = a.second.second;
                totalb += a.first;
            }
            printf("%d %d\n", totala, totalb);
        }
        printf("%d\n", totala - totalb);
    }
    return 0;
}
