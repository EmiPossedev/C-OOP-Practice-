/*
  Starter C++ program

  Build:
    g++ -std=c++17 -O2 -Wall -Wextra -pedantic -o app main.cpp

  Run:
    ./app [name]
*/

#include <iostream>
#include <string>
#include <cstdlib>

namespace app {

void print_usage(const char* prog) {
    std::cout << "Usage: " << prog << " [name]\n";
}

int run(int argc, char* argv[]) {
    if (argc > 1) {
        std::string arg1 = argv[1];
        if (arg1 == "-h" || arg1 == "--help") {
            print_usage(argv[0]);
            return EXIT_SUCCESS;
        }
    }

    std::string name = (argc > 1) ? argv[1] : "World";
    std::cout << "Hello, " << name << "!" << std::endl;

    // TODO: Add your application logic here.

    return EXIT_SUCCESS;
}

} // namespace app

int main(int argc, char* argv[]) {
    try {
        return app::run(argc, argv);
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
        return EXIT_FAILURE;
    }
}