#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::greater;
using std::sort;
using std::vector;

int64_t MaxPairProd(vector<int64_t> &num)
{
    sort(num.begin(), num.end(), greater<int>());
    int64_t prod = num[0] * num[1];
    return prod;
}

int main()
{
    int n;
    cin >> n;
    vector<int64_t> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int64_t prod = MaxPairProd(numbers);
    cout << prod << endl;
    return 0;
}
