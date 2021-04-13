#include <iostream>
/* Przelicznik cali na centymetry v0.1
 */
int main ()
{
     double inch, cm;                                       // deklaracja wymaganych zmiennych
     const float conv = 2.54;                               // deklaracja przelicznika
     std::cout << "Podaj długość w calach: ";               // zapytanie
     std::cin >> inch;                                      // zapisanie odpowiedzi do zmiennej
     cm = inch * conv;                                      // obliczenie wyniku
     // wyświetlenie wyniku
     std::cout << "Długość w centymetrach to " << cm << "cm" << std::endl;
     return 0;
}
