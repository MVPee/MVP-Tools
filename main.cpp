# include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: MVP [-h | cmd]" << std::endl;
        return (1);
    }
    return 0;
}