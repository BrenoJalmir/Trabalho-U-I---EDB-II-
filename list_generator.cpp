#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

int main() {
    srand(time(NULL));
    std::ofstream list;
    int opt = 0;

    std::cout << "Size of the list:\n[1] 1.000\n[2] 10.000\n[3] 100.000" << std::endl;
    std::cin >> opt;

    if (opt == 1) {
        list.open("list_1000.txt", std::ios::out);
        if (list.is_open()) {
            for (int i = 0; i < 1000; i++) {
                list << rand() % 1001;
                if (i < 999)
                    list << std::endl;
            }
        }
    }

    else if (opt == 2) {
        list.open("list_10000.txt", std::ios::out);
        if (list.is_open()) {
            for (int i = 0; i < 10000; i++) {
                list << rand() % 1001;
                if (i < 9999)
                    list << std::endl;
            }
        }
    }

    else if (opt == 3) {
        list.open("list_100000.txt", std::ios::out);
        if (list.is_open()) {
            for (int i = 0; i < 100000; i++) {
                list << rand() % 1001;
                if (i < 99999)
                    list << std::endl;
            }
        }
    }

    else {
        std::cout << "Invalid option." << std::endl;
    }

    list.close();

    return 0;
}