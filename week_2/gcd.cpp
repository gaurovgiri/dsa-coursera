#include <iostream>

int gcd_naive(int a, int b)
{
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++)
    {
        if (a % d == 0 && b % d == 0)
        {
            if (d > current_gcd)
            {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

uint64_t gcd_fast(uint64_t a, uint64_t b)
{
    if (b == 0)
        return a;
    return (uint64_t)gcd_fast(b, a%b);
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    // std::cout << gcd_naive(a, b) << std::endl;
    std::cout << gcd_fast(a, b) << std::endl;
    return 0;
}
