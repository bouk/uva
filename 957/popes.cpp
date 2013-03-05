#include <cstdio>
#include <queue>

using namespace std;

int Y;
int P;
int start;
int end;
int n;
int main()
{
    while(scanf("%d\n%d", &Y, &P) != EOF)
    {
        queue<int> q;
        size_t best_count = 0;
        while(P--)
        {
            scanf("%d", &n);
            q.push(n);
            while(q.front() + Y - 1 < n)
            {
                q.pop();
            }
            if(q.size() > best_count)
            {
                start = q.front();
                end = n;
                best_count = q.size();
            }
        }
        printf("%lu %d %d\n", best_count, start, end);
    }
}
