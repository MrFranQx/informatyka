#include <iostream>
#include <cmath>

int main() {
    while (true) {
        int wybor;
        double x, y, wynik;
        std::cout << "KALKULATOR" << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "(1) Dodawanie" << std::endl;
        std::cout << "(2) Odejmowanie" << std::endl;
        std::cout << "(3) Mnożenie" << std::endl;
        std::cout << "(4) Dzielenie" << std::endl;
        std::cout << "(5) Reszta z dzielenia (modulo)" << std::endl;
        std::cout << "(6) Potęgowanie" << std::endl;
        std::cout << "(7) Pierwiastkowanie" << std::endl;
        std::cout << "(8) Silnia" << std::endl;
        std::cout << "(9) Wyjście" << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "Wybierz opcję: ";
        std::cin >> wybor;
        if (wybor==9) break;
        std::cout << "--------------------" << std::endl;
        if (wybor==8) {
            std::cout << "Podaj liczbę: ";
            std::cin >> x;
        } else {
            std::cout << "Podaj dwie liczby rozdzielone spacją: ";
            std::cin >> x >> y;
        }
        std::cout << "--------------------" << std::endl;
        switch (wybor) {
            case 1:
                wynik = x + y;
                break;
            case 2:
                wynik = x - y;
                break;
            case 3:
                wynik = x * y;
            case 4:
                if (y==0) {
                    std::cout << "Nie dzielimy przez 0!" << std::endl;
                    continue;
                } else wynik = x / y;
                break;
            case 5:
                if (y==0) {
                    std::cout << "Nie dzielimy przez 0!" << std::endl;
                    continue;
                } else wynik = (int) x % (int) y;
                break;
            case 6:
                wynik = pow(x,y);
                break;
            case 7:
                wynik = pow(x,1/y);
                break;
            case 8:
                wynik = 1;
                for (int i=1; i <= x; i++) wynik = wynik * i;
                break;
            default:
                std::cout << "Nie ma takiej opcji w menu!" << std::endl;
                std::cout << "--------------------" << std::endl;
                continue;
        }
        std::cout << "Wynik to: " << wynik << std::endl;
        std::cout << "--------------------" << std::endl;
    }
    return 0;
}
