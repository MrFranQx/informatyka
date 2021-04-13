#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

std::fstream file1, file2;
void writeline();
void writefile(int p);
int readline_mult();
void readfile(int p);

int main()
{
    int pairs;
    std::cout << "Ile par liczb wypisać?: ";
    std::cin >> pairs;
    writefile(pairs);
    readfile(pairs);
    std::cout << "Operacja zakończona sukcesem" << std::endl;
    return 0;
}

void writeline()
{
    file1 << std::rand() % 1000 << '\t' << std::rand() % 1000 << std::endl;
}

void writefile(int p)
{
    file1.open("plik1.txt", std::ios::out);
    std::srand(std::time(NULL));;

    for (int i = 0; i < p; i++) {
        writeline();
    }

    file1.close();
}

int readline_mult()
{
    int num1, num2, res;
    file1 >> num1 >> num2;
    res = num1 * num2;
    return res;
}

void readfile(int p)
{
    file1.open("plik1.txt", std::ios::in);

    if (file1.good() != true) {
        std::cerr << "Błąd otwierania pliku!" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    file2.open("plik2.txt", std::ios::out);

    for (int i = 0; i < p; i++) {
        file2 << readline_mult() << std::endl;
    }

    file1.close();
    file2.close();
}
