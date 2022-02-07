//TODO: Write a program to Implement Caesar Cypher Cryptography Implement.
//* Encryption Formula :- En(x) = (x+n) % 26 ; where n is shift number
//* Decryption Formula :- En(x) = (x-n) % 26 ; where n is shift number

#include <iostream>
#include <string.h>
using namespace std;

string encypt(string str, int shift)
{
    string result = "";

    // traverse through string
    for (int i = 0; i < str.length(); i++)
    {
        // Applying transformation to each character
        if (isupper(str[i])) // check for uppercase
        {
            result += char(int(str[i] + shift - 65) % 26 + 65);
        }
        else
        {
            result += char(int(str[i] + shift - 97) % 26 + 97);
        }
    }
    return result;
}

string decrypt(string str, int shift)
{
    string result = "";

    // traverse through string
    for (int i = 0; i < str.length(); i++)
    {
        // Applying transformation to each character
        if (isupper(str[i]))
        {
            result += char(int(str[i] - shift - 65) % 26 + 65);
        }
        else
        {
            result += char(int(str[i] - shift - 97) % 26 + 97);
        }
    }

    return result;
}

int main()
{
    string str;
    int shift;

    cout << "Enter a string to Encrypt : ";
    cin >> str;

    cout << "Enter Shift Number : ";
    cin >> shift;

    cout << "Encrypted String : " << encypt(str, shift) << endl;
    cout << "Decrypted String : " << decrypt(encypt(str, shift), shift);

    return 0;
}