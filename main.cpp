# include "includes/Application.hpp"

int main(int ac, char **av) {
    Application app;
    try {
        app.run(ac, av);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
}