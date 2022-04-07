// TODO: Write a program to implement Playfair Cipher Cryptography Algorithm
#include <bits/stdc++.h>
using namespace std;

// * toLowerCase() =>
void toLowerCase(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// * removeWhiteSpace () =>
int removeWhiteSpace(string &plain, int ps)
{
    int i, count = 0;
    for (i = 0; i < ps; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    plain[count] = '\0';
    return count;
}

// * generateKeyTable ()=>
void generateKeyTable(string key, char KeysTable[5][5])
{
    int i, j, k;
    int key_length = key.length();

    // map to store all characters of key
    map<char, int> dict;
    // count the occurances of characters in key
    for (i = 0; i < key_length; i++)
    {
        if (key[i] != 'j')
            dict[key[i] - 97] = 2;
    }

    dict['j' - 97] = 1;

    i = j = 0;

    for (k = 0; k < key_length; k++)
    {
        if (dict[key[k] - 97] == 2)
        {
            dict[key[k] - 97] -= 1;
            KeysTable[i][j] = key[k];
            j++;
            if (j == 5)
            {
                j = 0;
                i++;
            }
        }
    }

    for (k = 0; k < 26; k++)
    {
        if (dict[k] == 0)
        {
            KeysTable[i][j] = (char)(k + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
}

// TODO: Search for characters of digraph in keys table and return their position
void search(char keyT[5][5], char a, char b, int arr[])
{
    int i, j;

    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';

    for (i = 0; i < 5; i++)
    {

        for (j = 0; j < 5; j++)
        {

            if (keyT[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

// TODO FInd mod with 5
int mod5(int a) { return (a % 5); }

// TODO divide plain text into 2 2 even groups
int prepare(string &str, int ptrs)
{
    if (ptrs % 2 != 0)
    {
        str[ptrs++] = 'z';
        str[ptrs] = '\0';
    }
    return ptrs;
}

// TODO: Perform encryption
void encrypt(string &str, char keyT[5][5], int ps)
{
    int i, a[4];

    for (i = 0; i < ps; i += 2)
    {

        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

int main()
{
    string str, key;
    char KeysTable[5][5];

    cout << "Enter String : ";
    cin >> str;
    cout << "Enter Key : ";
    cin >> key;

    toLowerCase(str);
    toLowerCase(key);

    int lenStr = str.length();
    int lenKey = key.length();

    lenStr = removeWhiteSpace(str, lenStr);
    lenKey = removeWhiteSpace(key, lenKey);

    lenStr = prepare(str, lenStr);

    generateKeyTable(key, KeysTable);

    cout << "Key Table is : \n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << KeysTable[i][j] << " ";
        }
        cout << endl;
    }

    encrypt(str, KeysTable, lenStr);

    cout << "After  Encryption : " << str;
    return 0;
}