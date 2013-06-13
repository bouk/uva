#include <cstdio>
#include <deque>
#include <vector>
using namespace std;
#define INF 2000000
deque<int> window;
vector<int> contains;
int T;
int N, M, K;
int no_contained;
int main()
{
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d %d %d", &N, &M, &K);
        contains.assign(K + 1, 0);
        contains[1] = 1;
        contains[2] = 1;
        contains[3] = 1;
        window.clear();
        window.push_back(1);
        window.push_back(2);
        window.push_back(3);
        no_contained = 3;
        printf("Case %d: ", t);
        if(K <= 3)
        {
            printf("%d\n", K);
            continue;
        }
        int x1 = 1;
        int x2 = 2;
        int x3 = 3;
        int best_length = 2000000;
        for(int i = 4; i <= N; i++)
        {
            int newx = (x1 + x2 + x3) % M + 1;
            x1 = x2;
            x2 = x3;
            x3 = newx;
            if(newx <= K)
            {
                contains[newx]++;
                if(contains[newx] == 1)
                {
                    no_contained++;
                }
            }
            window.push_back(newx);
            while(window.front() > K || contains[window.front()] > 1)
            {
                int f = window.front();
                window.pop_front();
                if(f <= K)
                {
                    contains[f]--;
                }
            }
            if(no_contained == K && (int)window.size() < best_length)
            {
                best_length = (int)window.size();
            }
        }
        if(best_length < INF)
        {
            printf("%d\n", best_length);
        }
        else
        {
            printf("sequence nai\n");
        }
    }
}
