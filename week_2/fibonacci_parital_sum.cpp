#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to)
{

    std::vector<int> fib = {0, 1};
    int len = (from%60) > (to%60) ? (from%60) : (to%60);
    for (int i = 2; i <= (len+2); i++)
    {
        fib.push_back(((fib[i - 1]) + (fib[i - 2])) % 10);
    }

    int ans = ((fib[(to + 2) % 60] - 1) - (fib[(from + 1) % 60] - 1)) % 10;
    return ans<0?(ans%10+10)%10:ans;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
