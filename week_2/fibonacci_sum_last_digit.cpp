#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(int64_t n)
{
    std::vector<u_int64_t> fib{0,1};

    for (int i = 2; i <= ((n+5) % 60); i++)
    {
        fib.push_back((uint64_t)(fib[i-1]%10 + fib[i-2]%10));
    }
    return (fib[(n+2)%60] - 1)%10;
}

int main()
{
    int64_t n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_fast(n) << std::endl;
}
