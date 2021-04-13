#include <iostream>
#include <cmath> // aby działała funkcja pow() używana przy potęgach o wykładniku niecałkowitym i pierwiastkach

int menu(); // wyświetlenie menu głównego
void input(double* arr, int quant);    // wczytywanie liczb do tablicy
double calc(double* arr, int quant, int type);    // obliczanie podstawowych działanń
int zerocheck(double* arr, int quant);    // wyszukiwanie zer w tablicy - potrzebne przy dzieleniu
double power(double base, int exp);    // potęga o wykładniku całkowitym - dla wykładnika niecałkowitego konieczna funkcja pow()

int main()
{
    while (true) {
        int selection = menu();
        double* array; // wskaźnik użyty w celu dynamicznej alokacji pamięci
        int quantity;
        double result;

        if (selection == 8) break; // opcja 8 to wyjście - wyłamanie z pętli głównej kończy program

        std::cout << "-----------------------------------" << std::endl;

        switch (selection) {
        case 1:
            std::cout << "Ile liczb chcesz dodać?: ";
            std::cin >> quantity;
            array = new double [quantity]; // alokacja odpowiedniej ilości komórek
            input(array, quantity);
            std::cout << "-----------------------------------" << std::endl;
            result = calc(array, quantity, selection);
            break;

        case 2:
            std::cout << "Ile liczb chcesz odjąć?: ";
            std::cin >> quantity;
            array = new double [quantity]; // alokacja odpowiedniej ilości komórek
            input(array, quantity);
            std::cout << "-----------------------------------" << std::endl;
            result = calc(array, quantity, selection);
            break;

        case 3:
            std::cout << "Ile liczb chcesz pomnożyć?: ";
            std::cin >> quantity;
            array = new double [quantity]; // alokacja odpowiedniej ilości komórek
            input(array, quantity);
            std::cout << "-----------------------------------" << std::endl;
            result = calc(array, quantity, selection);
            break;

        case 4:
            std::cout << "Ile liczb chcesz podzielić?: ";
            std::cin >> quantity;
            array = new double [quantity]; // alokacja odpowiedniej ilości komórek
            std::cout << "-----------------------------------" << std::endl;
            input(array, quantity);
            std::cout << "-----------------------------------" << std::endl;

            if (zerocheck(array, quantity) == 1) {
                std::cout << "Nie dzielimy przez 0!" << std::endl;
                continue;

            } else result = calc(array, quantity, selection);

            break;

        case 5: // operacja modulo
            array = new double [2]; // alokacja dwóch komórek - przeprowadzanie modulo na większej ilości liczb nie ma sensu
            input(array, 2);
            std::cout << "-----------------------------------" << std::endl;

            if (array[1] == 0) {
                std::cout << "Nie dzielimy przez 0!" << std::endl;
                continue;

            } else result = calc(array, 2, selection);

            break;

        case 6: // potęgowanie
            array = new double [2]; // alokacja dwóch komórek - potrzebne są jedynie podstawa i wykładnik
            input(array, -1);   // -1 odpowiada za wiadomości dotyczące potęgowania (aby nie tworzyć osobnej funkcji)
            std::cout << "-----------------------------------" << std::endl;

            if (floor(* (array + 1)) == * (array + 1)) {     // sprawdzenie, czy wykładnik jest całkowity
                result = power(*array, (int) * (array + 1));    // power() to moja, prosta funkcja, obsługująca tylko liczby całkowite

            } else {
                result = pow(*array, * (array + 1)); // pow() to funkcja z biblioteki cmath, obsługująca pozostałe liczby
            }

            break;

        case 7:
            array = new double [2]; // alokacja dwóch komórek - potrzebne są jedynie liczba podpierwiastkowa i stopień
            input(array, -2);   // -2 odpowiada za wiadomości dotyczące pierwiastkowania (aby nie tworzyć osobnej funkcji)
            std::cout << "-----------------------------------" << std::endl;
            result = pow(*array, 1 / (* (array + 1)));
            break;

        default:
            std::cout << "Nie ma takiej opcji w menu!" << std::endl;
            std::cout << "-----------------------------------\n\n\n\n\n" << std::endl;
            continue;
        }

        std::cout << "Wynik to: " << result << std::endl;
        std::cout << "-----------------------------------\n\n\n\n\n" << std::endl;
        delete [] array; // zwolnienie zaalokowanych wcześniej komórek
    }

    return 0;
}

int menu()
{
    int selection;
    std::cout << "KALKULATOR" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "[1] Dodawanie" << std::endl;
    std::cout << "[2] Odejmowanie" << std::endl;
    std::cout << "[3] Mnożenie" << std::endl;
    std::cout << "[4] Dzielenie" << std::endl;
    std::cout << "[5] Reszta z dzielenia (modulo)" << std::endl;
    std::cout << "[6] Potęgowanie" << std::endl;
    std::cout << "[7] Pierwiastkowanie" << std::endl;
    std::cout << "[8] Wyjście" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Wybierz opcję: ";
    std::cin >> selection;
    return selection;
}

void input(double* arr, int quant)
{
    if (quant == 1) {
        std::cout << "Podaj liczbę: ";
        std::cin >> *arr;

    } else if (quant == -1) { // -1 odpowiada za wiadomości dotyczące potęgowania (aby nie tworzyć osobnej funkcji)
        std::cout << "Podaj podstawę potęgi: ";
        std::cin >> *arr;
        std::cout << "Podaj wykładnik potęgi: ";
        std::cin >> * (arr + 1);

    } else if (quant == -2) { // -2 odpowiada za wiadomości dotyczące pierwiastkowania (aby nie tworzyć osobnej funkcji)
        std::cout << "Podaj liczbę podpierwiastkową: ";
        std::cin >> *arr;
        std::cout << "Podaj stopień pierwiastka: ";
        std::cin >> * (arr + 1);

    } else {
        for (int i = 1; i <= quant; i++) {
            std::cout << "Podaj " << i << ". liczbę: ";
            std::cin >> *arr;
            arr++; // wskaźnik również musi być inkrementowany
        }

        arr -= quant; // reset wskaźnika do pozycji początkowej
    }
}
double calc(double* arr, int quant, int type)
{
    double res;

    switch (type) {
    case 1:
        res = 0;

        for (int i = 0; i < quant; i++) {
            res += *arr;
            arr++; // wskaźnik również musi być inkrementowany
        }

        break;

    case 2:
        res = *arr;
        arr++; // wstępna inkrementacja - działanie bazuje na pierwszej wartości

        for (int i = 1; i < quant; i++) {
            res -= *arr;
            arr++; // wskaźnik również musi być inkrementowany
        }

        break;

    case 3:
        res = 1;

        for (int i = 0; i < quant; i++) {
            res *= *arr;
            arr++; // wskaźnik również musi być inkrementowany
        }

        break;

    case 4:
        res = *arr;
        arr++; // wstępna inkrementacja - działanie bazuje na pierwszej wartości

        for (int i = 1; i < quant; i++) {
            res /= *arr;
            arr++; // wskaźnik również musi być inkrementowany
        }

        break;

    case 5:
        res = (int) * arr % (int) * (arr + 1);
        arr += 2; // aby reset zaszedł w sposób bezpieczny, konieczne zwiększenie wskaźnika o 2
        break;
    }

    arr -= quant; // reset wskaźnika do pozycji początkowej
    return res;
}

int zerocheck(double* arr, int quant)
{
    arr++; // wstępna inkrementacja - działanie bazuje na pierwszej wartości

    for (int i = 1; i < quant; i++) {
        if (*arr == 0) return 1;

        arr++; // wskaźnik również musi być inkrementowany
    }

    arr -= quant; // reset wskaźnika do pozycji początkowej
    return 0;
}

double power(double base, int exp)
{
    double res = 1;

    if (res == 0) return res; // dla wykładnika równego 0 potęga zawsze ma wartość 1

    else if (res > 0) {   // jeśli wykładnik większy od 0, mnożenie zadaną ilość razy
        for (int i = 0; i < exp; i++) {
            res *= base;
        }

    } else if (res < 0) {   // jeśli wykładnik mniejszy od 0, dzielenie zadaną ilość razy
        for (int i = 0; i > exp; i--) {
            res /= base;
        }
    }

    return res;
}
