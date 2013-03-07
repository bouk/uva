#include <cmath>
#include <cstdio>

#define EPS 1e-9

inline double eq(double p, double q, double r, double s, double t, double u, double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2) + u;
}

int main()
{
    int p, q, r, s, t, u;
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
    {
        if(eq(p, q, r, s, t, u, 0) * eq(p, q, r, s, t, u, 1) > 0)
        {
            printf("No solution\n");
            continue;
        }
        double low = 0;
        double hi = 1;
        while(fabs(hi - low) > EPS)
        {
            double c = (hi + low) / 2;
            double result = eq(p, q, r, s, t, u, c);
            if(eq(p, q, r, s, t, u, low) * eq(p, q, r, s, t, u, c) <= 0)
            {
                hi = c;
            }
            else
            {
                low = c;
            }
        }
        printf("%.4lf\n", (hi + low) / 2);
    }
}
