#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define FUEL 0
#define LEAK 1
#define GAS 2
#define MECH 3
#define GOAL 4

vector<iii> moves;

bool canreach(double size)
{
    int consumption = 0;
    double fuel = size;
    int leaks = 0;
    int pos = 0;
    for(int i = 0; i < (int)moves.size(); i++)
    {
        int newpos = moves[i].second.first;
        double fueluse = ((double)(newpos - pos) / 100.0d) * (double)consumption;
        fuel -= fueluse;
        fuel -= leaks * (newpos - pos);
        if(fuel < 0)
        {
            return false;
        }
        pos = newpos;
        switch(moves[i].first)
        {
            case FUEL:
                consumption = moves[i].second.second;
                break;
            case LEAK:
                leaks++;
                break;
            case GAS:
                fuel = size;
                break;
            case MECH:
                leaks = 0;
                break;
            case GOAL:
                return true;
                break;
        }
    }
    return false;
}


int main()
{
    char buffer[200];
    int pos;
    int extra;
    int consumption;

    while(true)
    {
        moves.clear();
        while(true)
        {
            scanf("%d %s", &pos, buffer);
            if(buffer[0] == 'F')
            {
               scanf("%s %d", buffer, &consumption);
               moves.push_back(iii(FUEL, ii(pos, consumption)));
               if(consumption == 0)
               {
                   goto end;
               }
            }
            else if(buffer[0] == 'G' && buffer[1] == 'a')
            {
                scanf("%s", buffer);
                moves.push_back(iii(GAS, ii(pos, 0)));
            }
            else if(buffer[0] == 'L')
            {
                moves.push_back(iii(LEAK, ii(pos, 0)));
            }
            else if(buffer[0] == 'M')
            {
                moves.push_back(iii(MECH, ii(pos, 0)));
            }
            else if(buffer[0] == 'G' && buffer[1] == 'o')
            {
                moves.push_back(iii(GOAL, ii(pos, 0)));
                break;
            }
        }
        double low = 0;
        double high = 20000;
        int iteration = 1000;
        while(iteration--)
        {
            double test = (low + high) / 2;
            if(canreach(test))
            {
                high = test;
            }
            else
            {
                low = test;
            }
        }
        printf("%0.3f\n", low);
    }
end:
    return 0;
}
