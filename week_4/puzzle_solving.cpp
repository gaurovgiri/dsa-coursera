#include <iostream>

using namespace std;

int main()
{
    char compare;

    int upper, lower;
    int mid;
    upper = 2097151;
    lower = 1;

    while (lower <= upper)
    {
        mid = lower + (upper - lower) / 2;

        cout << "Number is : " << mid << endl;

        cin >> compare;
        if (compare == 's')
        {
            upper = mid - 1;
        }

        else if (compare == 'l')
        {
            lower = mid + 1;
        }

    }
}