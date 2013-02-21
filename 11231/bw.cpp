#include <cstdio>

using namespace std;

int n, m, c;

int main()
{
    while(scanf("%d %d %d", &n, &m, &c) != EOF && n & m)
    {
        int total = 0;
        if(c == 1)
        {
            total += ((n-6)/2)*((m-6)/2);

            if(n % 2)
            {
                total += (m-6)/2;
            }
            if(m % 2)
            {
                total += (n-6)/2;
            }
            if(m % 2 && n % 2)
            {
                total--;
            }
        }
        else
        {

        }
        printf("%d\n", total);
    }
}