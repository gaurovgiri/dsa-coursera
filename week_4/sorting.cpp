#include <iostream>
#include <vector>
#include <cstdlib>

using std::swap;
using std::vector;

vector<int> partition3(vector<int> &a, int l, int r)
{
    int x = a[l];
    int j = 0;
    int mid = 0;
    int k = r;

    while (mid <= k)
    {
        if (a[mid] < x)
        {
            swap(a[mid], a[j]);
            j++;
            mid++;
        }
        else if (a[mid] > x)
        {
            swap(a[mid], a[k]);
            k--;
        }
        else
        { 
            mid++;
        }
    }
    vector<int> indexes = {j, k};
    return indexes;
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> index = partition3(a, l, r);
    randomized_quick_sort(a, l, index[0] - 1);
    randomized_quick_sort(a, index[1] + 1, r);
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << ' ';
    }
}