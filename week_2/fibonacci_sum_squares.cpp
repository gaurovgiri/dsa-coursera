#include <iostream>
#include <vector>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n)
{
    std::vector<int> fib{0, 1};
    for (int i = 2; i <= (n % 60); i++)
    {
        fib.push_back((fib[i-1]+fib[i-2])%10);
    }
    return (fib[n%60] * (fib[n%60] + fib[(n-1)%60]))%10;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n) << std::endl;
}
