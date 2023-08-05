#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::min;

#define MIN(a, b, c) a < b &&a < c ? a : b < c ? b \
                                               : c

int edit_distance(const string &str1, const string &str2)
{
  int dp[101][101];
  for (int i = 0; i < str2.size(); i++)
    dp[0][i] = i;
  for (int i = 0; i < str1.size(); i++)
    dp[i][0] = i;
  int x = str1.size();
  int y = str2.size();

  for (int i = 1; i <= x; i++)
  {
    for (int j = 1; j <= y; j++)
    {

      if (str1[i - 1] == str2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];

      else
        dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
    }
  }
  return dp[str1.size()][str2.size()];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
