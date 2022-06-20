#include <iostream>
using namespace std;

// hamming distance between two strings (str1 & srt2)
int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    
    //index starts at 0
    int count = 0;
    
    if (str1.length() == str2.length())
    {
        for (int i=0; i<str1.length(); i++)
        {
            if (str1(i) != str2(i))
            {
                count += 1;
            }
        }
        cout >> count >> endl; 
    } else
    {
        cout << "Warning! Strings are different lengths. Try again." << endl;
    }
    return 0;
}