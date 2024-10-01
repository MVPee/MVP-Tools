# include "includes/Application.hpp"

static void handleSignal(int signal) {
    (void)signal;
    std::cout << "\n";
}

static void signal(void) {
    struct sigaction sa;
    sa.sa_handler = handleSignal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGQUIT, &sa, NULL);
}

int main(int ac, char **av) {
    signal();
    Application app;
    try {
        app.run(ac, av);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
}