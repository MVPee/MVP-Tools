#include "../../includes/tools/Cannonical.hpp"

/*
** ------------------------------- STATIC -------------------------------------
*/

static std::vector<std::string> getClassNames(void) {
    std::string line;
    std::cout << "Enter(s) classname(s): ";
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::vector<std::string> classNames;
    std::string className;

    while (iss >> className) {
		className[0] = toupper(className[0]);
        classNames.push_back(className);
	}
    return classNames;
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cannonical::Cannonical() {}

Cannonical::Cannonical(int ac, char **av) {
	std::vector<std::string> classNames;
	if (ac > 2) {
		std::string className;
		for (size_t i = 2; av[i]; i++) {
			className = av[i];
			className[0] = toupper(className[0]);
			classNames.push_back(className);
		}
	}
	else
    	classNames = getClassNames();
    try {
        for (const auto &className : classNames) {
            createHPPFile(className);
            createCPPFile(className);
        }
    }
    catch (const std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

Cannonical::Cannonical(const Cannonical &src) { (void)src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cannonical::~Cannonical() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cannonical &Cannonical::operator=(const Cannonical &rhs) {
	if (this != &rhs) {
		;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cannonical::createHPPFile(const std::string &className) {
	std::ofstream HPPfile(className + ".hpp");
	if (!HPPfile.is_open() || !HPPfile.good())
		throw std::runtime_error("Error: Could not create the file " + className + ".hpp");
	HPPfile << "#pragma once\n\n# include <iostream>\n# include <string>\n\n" \
			<< "class " << className << " {\n" \
			<< "\tprivate:\n\tpublic:\n" \
			<< "\t\t" << className << "();\n" \
			<< "\t\t" << className << "(const " << className << " &ref);\n" \
			<< "\t\t~" << className << "();\n" \
			<< "\t\t" << className << " &operator=(const " << className << " &ref);\n" \
			<< "};\n\n" << "std::ostream &operator<<(std::ostream &o, const " << className << " &i);";
	HPPfile.close();
}

void Cannonical::createCPPFile(const std::string &className) {
	std::ofstream CPPFile(className + ".cpp");
	if (!CPPFile.is_open() || !CPPFile.good())
		throw std::runtime_error("Error: Could not create the file " + className + ".cpp");
	CPPFile << "# include \"" << className << ".hpp\"\n\n" \
			<< "/*\n** ------------------------------- STATIC -------------------------------------\n*/\n\n" \
			<< "/*\n** ------------------------------- CONSTRUCTOR --------------------------------\n*/\n\n" \
			<< className << "::" << className << "() {}\n\n" \
			<< className << "::" << className << "(const "<< className << " &ref) { (void)ref; }\n\n" \
			<< "/*\n** ------------------------------- DESTRUCTOR ---------------------------------\n*/\n\n" \
			<< className << "::~" << className << "() {}\n\n" \
			<< "/*\n** ------------------------------- OVERLOAD -----------------------------------\n*/\n\n" \
			<< className << " &" << className << "::operator=(const " << className << " &ref) {\n" \
			<< "\tif(this != &ref) {\n\t\t;\n\t}\n\treturn *this;\n}\n\n" \
			<< "std::ostream &operator<<(std::ostream &o, const "<< className <<" &i) {\n\t(void)i;\n\treturn o;\n}\n\n"
			<< "/*\n** ------------------------------- METHODS -----------------------------------\n*/\n\n" \
			<< "/*\n** ------------------------------- ACCESSOR ----------------------------------\n*/\n\n" \
			<< "/* ************************************************************************** */";
	CPPFile.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */