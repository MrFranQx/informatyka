#include <iostream>

using namespace std;

int main()
{
    char n;
    cin >> n;
    switch (n)
    {
        case 'a': cout << "1"; break;
        case 'b': cout << "2"; break;
        case 'c': cout << "3"; break;
        case 'd': cout << "4"; break;
        case 'e': cout << "5"; break;
        case 'f': cout << "6"; break;
        default: cout << "Nie rozumiem";
    }
    return 0;
}
