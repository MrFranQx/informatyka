#include <iostream>
#include <fstream>

struct Vector {
    double x, y, z;
};

void line();
int menu();
double q_input(std::string quant, std::string unit);
double velocity(double dist, double tim);
double momentum(double veloc, double m);
Vector vector_sum(Vector v1, Vector v2);
Vector vector_mult(Vector v1, Vector v2);
double kinetic_energy(double veloc, double m);

int main()
{
    int selection;
    double distance;
    double time;
    double vel;
    double mass;
    double mom;
    double en;
    char sel;
    Vector vec1, vec2, vecres;

    std::ofstream log("log.txt", std::ios::app);
    log << "Początek programu" << std::endl;
    log << "------------------------" << std::endl;

    while (true) {
        sel = '?';
        selection = menu();

        if (selection == 6) break;

        log << "Wybrana opcja: " << selection << std::endl;

        switch (selection) {
        case 1:
            distance = q_input("drogę", "metrach");
            time = q_input("czas", "sekundach");
            vel = velocity(distance, time);
            log << "Pobrana droga: " << distance << " m" << std::endl;
            log << "Pobrany czas: " << time << " s" << std::endl;
            line();
            std::cout << "Prędkość wynosi " << vel << " m/s" << std::endl;
            log << "Prędkość wynosi: " << vel << " m/s" << std::endl;
            break;

        case 2:
            while (sel != 't' && sel != 'n') {
                std::cout << "Czy znana jest prędkość [t/n]?: ";
                std::cin >> sel;
                line();

                if (sel == 't') {
                    vel = q_input("prędkość", "m/s");
                    log << "Pobrana prędkość: " << distance << " m/s" << std::endl;

                } else if (sel == 'n') {
                    distance = q_input("drogę", "metrach");
                    time = q_input("czas", "sekundach");
                    log << "Pobrana droga: " << distance << " m" << std::endl;
                    log << "Pobrany czas: " << time << " s" << std::endl;
                    vel = velocity(distance, time);
                    log << "Prędkość wynosi: " << vel << " m/s" << std::endl;

                } else {
                    std::cout << "Wpisz 't' lub 'n'." << std::endl;
                    line();
                }
            }

            mass = q_input("masę", "kilogramach");
            log << "Pobrana masa: " << mass << " kg" << std::endl;
            mom = momentum(vel, mass);
            line();
            std::cout << "Pęd wynosi " << mom << " Ns" << std::endl;
            log << "Pęd wynosi: " << mom << " Ns" << std::endl;
            break;

        case 3:
            std::cout << "Podaj współrzędne 1. wektora rozdzielone spacją [X Y Z]: ";
            std::cin >> vec1.x >> vec1.y >> vec1.z;
            log << "Pobrane współrzędne 1. wektora: [" << vec1.x << ", " << vec1.y << ", " << vec1.z << "]" << std::endl;
            std::cout << "Podaj współrzędne 2. wektora rozdzielone spacją [X Y Z]: ";
            std::cin >> vec2.x >> vec2.y >> vec2.z;
            log << "Pobrane współrzędne 2. wektora: [" << vec2.x << ", " << vec2.y << ", " << vec2.z << "]" << std::endl;
            vecres = vector_sum(vec1, vec2);
            line();
            std::cout << "Suma wektorów to [" << vecres.x << ", " << vecres.y << ", " << vecres.z << "]" << std::endl;
            log << "Suma wektorów to: [" << vecres.x << ", " << vecres.y << ", " << vecres.z << "]" << std::endl;
            break;

        case 4:
            std::cout << "Podaj współrzędne 1. wektora rozdzielone spacją [X Y Z]: ";
            std::cin >> vec1.x >> vec1.y >> vec1.z;
            log << "Pobrane współrzędne 1. wektora: [" << vec1.x << ", " << vec1.y << ", " << vec1.z << "]" << std::endl;
            std::cout << "Podaj współrzędne 2. wektora rozdzielone spacją [X Y Z]: ";
            std::cin >> vec2.x >> vec2.y >> vec2.z;
            log << "Pobrane współrzędne 2. wektora: [" << vec2.x << ", " << vec2.y << ", " << vec2.z << "]" << std::endl;
            vecres = vector_mult(vec1, vec2);
            line();
            std::cout << "Iloczyn wektorowy to [" << vecres.x << ", " << vecres.y << ", " << vecres.z << "]" << std::endl;
            log << "Iloczyn wektorowy to: [" << vecres.x << ", " << vecres.y << ", " << vecres.z << "]" << std::endl;
            break;

        case 5:
            while (sel != 't' && sel != 'n') {
                std::cout << "Czy znana jest prędkość [t/n]?: ";
                std::cin >> sel;
                line();

                if (sel == 't') {
                    vel = q_input("prędkość", "m/s");
                    log << "Pobrana prędkość: " << distance << " m/s" << std::endl;

                } else if (sel == 'n') {
                    distance = q_input("drogę", "metrach");
                    time = q_input("czas", "sekundach");
                    log << "Pobrana droga: " << distance << " m" << std::endl;
                    log << "Pobrany czas: " << time << " s" << std::endl;
                    vel = velocity(distance, time);
                    log << "Prędkość wynosi: " << vel << " m/s" << std::endl;

                } else {
                    std::cout << "Wpisz 't' lub 'n'." << std::endl;
                    line();
                }
            }

            mass = q_input("masę", "kilogramach");
            log << "Pobrana masa: " << mass << " kg" << std::endl;
            en = kinetic_energy(vel, mass);
            line();
            std::cout << "Energia kinetyczna wynosi " << en << " J" << std::endl;
            log << "Energia kinetyczna wynosi: " << en << " J" << std::endl;
            break;

        default:
            std::cout << "Nie ma takiej opcji w menu!" << std::endl;
        }

        log << "------------------------\n" << std::endl;
    }

    log << "Koniec programu" << std::endl;
    log << "------------------------\n" << std::endl;

    log.close();
    return 0;
}

void line()
{
    std::cout << "------------------------" << std::endl;
}

int menu()
{
    int sel;
    line();
    std::cout << "Science_CALC" << std::endl;
    line();
    std::cout << "[1] Prędkość" << std::endl;
    std::cout << "[2] Pęd" << std::endl;
    std::cout << "[3] Dodawanie wektorów" << std::endl;
    std::cout << "[4] Mnożenie wektorów" << std::endl;
    std::cout << "[5] Energia kinetyczna" << std::endl;
    std::cout << "[6] Wyjście" << std::endl;
    line();
    std::cout << "Wybierz opcję: ";
    std::cin >> sel;
    line();
    return sel;
}

double q_input(std::string quant, std::string unit)
{
    double input;
    std::cout << "Podaj " << quant << " w " << unit << ": ";
    std::cin >> input;
    return input;
}

double velocity(double dist, double tim)
{
    return dist / tim;
}

double momentum(double veloc, double m)
{
    return veloc * m;
}

Vector vector_sum(Vector v1, Vector v2)
{
    Vector vres;
    vres.x = v1.x + v2.x;
    vres.y = v1.y + v2.y;
    vres.z = v1.z + v2.z;
    return vres;
}

Vector vector_mult(Vector v1, Vector v2)
{
    Vector vres;
    vres.x = v1.y * v2.z - v1.z * v2.y;
    vres.y = v1.z * v2.x - v1.x * v2.z;
    vres.z = v1.x * v2.y - v1.y * v2.x;
    return vres;
}

double kinetic_energy(double veloc, double m)
{
    return m * veloc * veloc / 2;
}
