#include "../includes/Application.hpp"

/*
** ------------------------------- STATIC -------------------------------------
*/

static void showHelp() {
	std::cout << "Options:" << std::endl;
	std::cout << "\t-h --help\thelp" << std::endl;
	std::cout << "\t-v --version\tversion" << std::endl;
	std::cout << "\tc cannonical\tcreate canonical class" << std::endl;
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Application::Application() {}

Application::Application(const Application &src) { (void)src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Application::~Application(){}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Application &Application::operator=(const Application &rhs) {
	if (this != &rhs) {
		;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Application::run(int ac, char **av) {
    if (ac < 2) {
        throw std::runtime_error("Usage: MVP [-h | cmd]");
	}
	const std::string cmd(av[1]);
	if (cmd == "-h" || cmd == "--help")
		showHelp();
	else if (cmd == "-v" || cmd == "--version")
		std::cout << VERSION << std::endl;
	else if (cmd == "c" || cmd == "cannonical") {
		try {
			Cannonical(ac ,av);
		}
		catch (std::exception &e) {
			throw std::runtime_error(e.what());
		}
	}
	else
		throw std::runtime_error("Unknown command: " + cmd);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */