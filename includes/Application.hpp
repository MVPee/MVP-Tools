#ifndef APPLICATION_HPP
# define APPLICATION_HPP

# define VERSION 0.11

# include <iostream>
# include <string>
# include <signal.h>
# include "./tools/Cannonical.hpp"

class Application {
	private:

		Application(const Application &src);
		Application &operator=(const Application &rhs);
	public:
		Application();
		~Application();

		void run(int ac, char **av);

};

#endif /* ***************************************************** APPLICATION_H */