#include <bits/stdc++.h>
using namespace std;

string encrypt(string str, int key)
{
    char rail[key][(str.length())];
    string result;

    // filling the rail matrix to distinguish filled spaces from blank ones
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            rail[i][j] = '\n';
        }
    }

    // find direction
    bool direction_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (row == 0 || row == key - 1)
        { // changing direction upward and downward
            direction_down = !direction_down;
        }

        // filling the characters
        rail[row][col++] = str[i];

        // finding next row using direction flag
        direction_down ? row++ : row--;
    }

    // construct cyper string using rail matrix
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (rail[i][j] != '\n')
            {
                result.push_back(rail[i][j]);
            }
        }
    }

    return result;
}

string decrypt(string str, int key)
{
    char rail[key][(str.length())];
    string result;

    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            rail[i][j] = '\n';
        }
    }

    bool direction_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (row == 0 || row == key - 1)
        {
            direction_down = !direction_down;
        }

        // Placing the marker
        rail[row][col++] = '*';

        // finding next row using direction fallthrough
        direction_down ? row++ : row--;
    }

    // now construsting and filling the rail matrix
    int index = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (rail[i][j] == '*' && index < str.length())
            {
                rail[i][j] = str[index++];
            }
        }
    }

    // Now reading the rail matrix in zing zag order to construct he resultant matrix

    direction_down = false;

    row = col = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (row == 0 || row == key - 1)
        {
            direction_down = !direction_down;
        }

        if (rail[row][col] != '*')
        {
            result.push_back(rail[row][col++]);
        }

        // finding new row using direction_down flag
        direction_down ? row++ : row--;
    }

    return result;
}

int main()
{
    int key;
    string str;

    cout << "Enter String : ";
    getline(cin, str);

    cout << "Enter key : ";
    cin >> key;

    cout << endl
         << "Encrypted String : " << encrypt(str, key);

    cout << endl
         << "Decrypted String : " << decrypt(encrypt(str, key), key);
    return 0;
}