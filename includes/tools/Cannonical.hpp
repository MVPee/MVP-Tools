#ifndef CANNONICAL_HPP
# define CANNONICAL_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <vector>

class Cannonical {
	private:
		void createHPPFile(const std::string &className);
		void createCPPFile(const std::string &className);

		Cannonical(const Cannonical &src);
		Cannonical &operator=(const Cannonical &rhs);
	public:
		Cannonical();
		~Cannonical();
};

#endif /* ****************************************************** CANNONICAL_H */