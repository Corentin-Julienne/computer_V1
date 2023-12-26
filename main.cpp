#include "./main.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error: Wrong Number of Arguments" << std::endl;
	}

	Parser	parser(argv[1]);
	

	
	return 0;
}
