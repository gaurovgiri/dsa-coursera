#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

string largest_number(vector<string> a)
{
    string temp;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i][0] < a[j][0] && a[i].length() == a[j].length())
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else if (atoi((a[i] + a[j]).c_str()) < atoi((a[j] + a[i]).c_str()))
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    std::stringstream ret;
    for (size_t i = 0; i < a.size(); i++)
    {
        ret << a[i];
    }
    string result;
    ret >> result;
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
}