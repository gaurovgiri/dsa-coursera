#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


uint64_t get_fibonacci_huge_fast(uint64_t a, uint64_t b)
{
    std::vector<uint64_t> arr;
    arr.push_back(0);
    arr.push_back(1);
    int pisano_period = 0;
    for (int i = 2; i <= b * b; i++)
    {
        arr.push_back((arr[i - 1] + arr[i - 2])%b);
        if (arr[i] == 1 && arr[i -1] == 0)
        {
            pisano_period++;
            break;
        }
        else{
            pisano_period++;
        }
    }
    return arr[a%pisano_period];
} 

int main()
{
    uint64_t n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << std::endl;
}
