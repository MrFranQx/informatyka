#include <iostream>

int main() {
    int wys, punkty_karne=0;
    std::cout << "Na jakiej wysokości lecimy? [m]: ";
    std::cin >> wys;
    
    if (wys<500) {
        std::cout << "\n" << wys << " metrów to za mało!\n";
        punkty_karne++;
    } else if (wys==500) {
        std::cout << "\nPrawie dobrze! Wysokość " << wys << "m\n";
    }
    else {
        std::cout << "\nNa wysokości " << wys << "m jesteś bezpieczny!\n";
        punkty_karne--;
    }
    std::cout << "Masz " << punkty_karne << " punktów karnych.\n";
    if (punkty_karne) std::cout << "Popraw się!\n";
    return 0;
}
