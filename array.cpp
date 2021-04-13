#include <iostream>

int input(double arr[]);
void sort(double arr[], int quant);
int menu();
int count_even(double arr[], int quant);
void exchange(double arr[]);

int main()
{
    double array[1000];
    int selection;
    int quantity;

    while (true) {
        selection = menu();

        switch (selection) {
        case 1:
            quantity = input(array);
            sort(array, quantity);
            std::cout << "Posortowana tablica to: ";

            for (int i = 0; i < quantity; i++) {
                std::cout << array[i] << " ";
            }

            std::cout << std::endl;
            break;

        case 2:
            quantity = input(array);
            std::cout << "Liczb parzystych w tablicy: " << count_even(array, quantity) << std::endl;
            break;

        case 3:
            exchange(array);
            std::cout << "Kwota w euro to " << array[0] << "€\n";
            std::cout << "Kwota w dolarach to " << array[1] << "$\n";
            std::cout << "Kwota w funtach to £" << array[2] << "\n";
            break;

        case 4:
            break;

        default:
            std::cout << "Nie ma takiej opcji w menu!" << std::endl;
        }

        if (selection == 4) break;
    }

    return 0;
}

void sort(double arr[], int quant)
{
    for (int i = 0; i < quant; i++) {
        for (int j = 0; j < quant; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int input(double arr[])
{
    int quant;
    std::cout << "Ile liczb w tablicy?: ";
    std::cin >> quant;

    for (int i = 1; i <= quant; i++) {
        std::cout << "Podaj " << i << ". liczbę: ";
        std::cin >> *arr;
        arr++; // wskaźnik również musi być inkrementowany
    }

    arr -= quant; // reset wskaźnika do pozycji początkowej
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Tablica to: ";

    for (int i = 0; i < quant; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n-----------------------------------" << std::endl;
    return quant;
}

int menu()
{
    int sel;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "OPERACJE NA TABLICY:" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "[1] Sortowanie" << std::endl;
    std::cout << "[2] Ile liczb parzystych" << std::endl;
    std::cout << "[3] Przelicznik walut" << std::endl;
    std::cout << "[4] Wyjście" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Wybierz opcję: ";
    std::cin >> sel;
    std::cout << "-----------------------------------" << std::endl;
    return sel;
}

int count_even(double arr[], int quant)
{
    int counter = 0;

    for (int i = 0; i < quant; i++) {
        if (((int)arr[i] % 2) == 0) {
            counter++;
        }
    }

    return counter;
}

void exchange(double arr[])
{
    float euro = 4.59;
    float dollar = 3.86;
    float pound = 5.35;
    float zloty;
    std::cout << "Podaj kwotę w złotych: ";
    std::cin >> zloty;
    arr[0] = zloty / euro;
    arr[1] = zloty / dollar;
    arr[2] = zloty / pound;
}
