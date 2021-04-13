#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "Jak masz na imię?: ";
    std::cin >> name;
    int sum=0;
    for (int i=0; i<name.length(); i++) {
        sum += int(name[i]);
    }
    std::cout << "Suma liter twojego imienia wynosi " << sum <<std::endl;
    return 0;
}
