#include <iostream>
#include <fstream>

using namespace std;

int N;
int B;
int H;
int W;

int main()
{
    /*ifstream fin;
    fin.open("input.txt");
    */
    
    int first = true;
    while(!cin.eof())
    {
        cin >> N;
        if(!N)
        break;
        cin >> B;
        cin >> H;
        cin >> W;
        
        int beds;
        int hotel_cost;
        int min_cost = -1;
        
        for(int i = 0; i < H; i++)
        {
            cin >> hotel_cost;
            int can_stay = false;
            for(int j = 0; j < W; j++)
            {
                cin >> beds;
                if(beds >= N)
                {
                    can_stay = true;
                }
            }
            if(can_stay && N*hotel_cost <= B)
            {
                if(min_cost == -1)
                {
                    min_cost = N*hotel_cost;
                }
                else
                {
                    min_cost = min(min_cost, N*hotel_cost);
                }
            }
        }
        if(!first)
        {
            cout << endl;
        }
        first = false;
        if(min_cost != -1)
        {
            cout << min_cost;
        }
        else
        {
            cout << "stay home";
        }
    }
    return 0;
}
