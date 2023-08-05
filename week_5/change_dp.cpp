#include <iostream>
#include <vector>

using std::vector;

int get_change(int m)
{
  int coin[3] = {1, 3, 4};
  vector<int> min_num_coins = {0};
  int numcoins;
  for (int i = 1; i <= m; i++)
  {
    min_num_coins.push_back(m);
    for (int j = 0; j < 3; j++)
    {
      if (i >= coin[j])
      {
        numcoins = min_num_coins[i - coin[j]] + 1;
        if (numcoins < min_num_coins[i])
        {
          min_num_coins[i] = numcoins;
        }
      }
    }
  }
  return min_num_coins[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
