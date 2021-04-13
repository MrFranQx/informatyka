#include <iostream>

int main() {
    int wys;
    std::cout << "Jak wysoka ma być choinka?: "; std::cin >> wys;
    if (wys > 10) std::cout << "Choinka nie zmieści się w pokoju!";
    else {
        int i = 1;
        while (i <= wys) {
            for (int j=1; j<=i; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
            i++;
        }
    }
}













/*
int main() {
    int ile;
    std::cout << "Ile gwiazdek narysować?: ";
    std::cin >> ile;
    std::cout << "No to rysujemy " << ile << " gwiazdek!\n";
    while (ile) {
        std::cout << "*";
        ile--;
    }
    std::cout << "\nTeraz zmienna ma wartość " << ile << std::endl;
    return 0;
}
*/
