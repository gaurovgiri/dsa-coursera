#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops){
    stops.push_back(dist);
    int lastStop = 0;
    int numberStop = 0;
    int x = 0;

    for (int i = 0; i < stops.size() - 1; i++)
    {

        if (stops[i] - lastStop <= tank)
        {
            x = stops[i];
            if (stops[i + 1] - lastStop > tank)
            {
                numberStop++;
                lastStop = x;
            }
        }
        if (tank < stops[i] - lastStop)
        {
            return -1;
        }

    }
    if (dist > lastStop + tank)
    {
        return -1;
    }

    return numberStop;
}


int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
