#include "mat.hpp"
#include <stdexcept>
#include <string>
#include <vector>

string create_c1_line(char c1, char c2, int columns, int k)
{
    string result;
    bool flag = false;

    if (k >= (columns / 2))
    {
        k = (columns / 2);
        flag = true;
    }
    if (k == 0)
    {
        k = 1;
    }

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
    if (!flag)
    {
        result.append(columns - 2 * (k), c1);
    }

    // add alternating right side
    for (int i = k; i > 0; --i)
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

string create_c2_line(char c1, char c2, int columns, int k)
{
    string result;
    bool flag = false;

    if (k >= (columns / 2))
    {
        k = (columns / 2);
        flag = true;
    }
    if (k == 0)
    {
        k = 1;
    }

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
    if (!flag)
    {
        result.append(columns - 2 * (k), c2);
    }

    // add alternating right side
    for (int i = k; i > 0; --i)
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
    if (columns % 2 == 0 || columns < 1)
    {
        throw std::invalid_argument("'columns' must be a positive odd number");
    }

    string result;
    vector<vector<char>> arr(rows);

    for (int i = 0; i < rows; ++i)
    {
        arr[i] = vector<char>(columns);
    }

    // set array to all c1 as default
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            arr[i][j] = c1;
        }
    }

    for (int k = 1; k <= min(columns, rows) / 2; k += 2)
    {
        // upper row
        for (int i = k; i < columns - k; ++i)
        {
            arr[k][i] = c2;
        }

        // lower row
        for (int i = k; i < columns - k; ++i)
        {
            arr[(rows - 1) - k][i] = c2;
        }

        // left column
        for (int i = k; i < rows - k; ++i)
        {
            arr[i][k] = c2;
        }

        // right column
        for (int i = k; i < rows - k; ++i)
        {
            arr[i][(columns - 1) - k] = c2;
        }
    }

    // print array
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            result.push_back(arr[i][j]);
        }
        result.push_back('\n');
    }

    return result;
}