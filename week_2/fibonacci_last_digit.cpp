#include <iostream>

int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n)
{
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
    }
    return arr[n] % 10;
}

int main()
{
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    int d = get_fibonacci_last_digit_fast(n);
    // std::cout << c << '\n';
    std::cout << d << std::endl;
}
