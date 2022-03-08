#include "mat.hpp"
#include <stdexcept>
#include <string>

string create_c1_line(char c1, char c2, int columns, int k)
{
    string result;

    // add alternating left side
    for (int i = 0; i < k; ++i)
    {
        if (i % 2 == 0)
        {
            result.append(1, c1);
        }
        else
        {
            result.append(1, c2);
        }
    }

    // add center
    result.append(columns - 2 * (k), c1);

    // add alternating right side
    for (int i = 0; i < k; ++i)
    {
        if (i % 2 == 0)
        {
            result.append(1, c1);
        }
        else
        {
            result.append(1, c2);
        }
    }

    result.append(1, '\n');
    return result;
}

string create_c2_line(char c1, char c2, int columns, int k)
{
    string result;

    // add alternating left side
    for (int i = 0; i < k; ++i)
    {
        if (i % 2 == 0)
        {
            result.append(1, c1);
        }
        else
        {
            result.append(1, c2);
        }
    }

    // add center
    result.append(columns - 2 * (k), c2);

    // add alternating right side
    for (int i = 0; i < k; ++i)
    {
        if (i % 2 == 0)
        {
            result.append(1, c2);
        }
        else
        {
            result.append(1, c1);
        }
    }
    result.append(1, '\n');
    return result;
}

string ariel::mat(int columns, int rows, char c1 = '@', char c2 = '-')
{
    if (rows % 2 == 0 || rows < 1)
    {
        throw std::invalid_argument("'rows' must be a positive odd number");
    }
    if (columns % 2 == 0)
    {
        throw std::invalid_argument("'columns' must be a positive odd number");
    }

    string result;
    int mid = (rows / 2) + 1;

    for (int i = 0; i < mid; ++i)
    {
        if (i % 2 == 0)
        {
            result += create_c1_line(c1, c2, columns, i + 1);
        }
        else
        {
            result += create_c2_line(c1, c2, columns, i + 1);
        }
    }

    for (int i = mid - 2; i >= 0; --i)
    {
        if (i % 2 == 0)
        {
            result += create_c1_line(c1, c2, columns, i + 1);
        }
        else
        {
            result += create_c2_line(c1, c2, columns, i + 1);
        }
    }

    return result;
}