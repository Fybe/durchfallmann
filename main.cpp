#include <iostream>
#include <SFML/Graphics.hpp>

#include "Durchfallmann.hpp"
#include "DurchfallmannConfig.hpp"

int main(int argc, char **argv)
{
	Durchfallmann *game = new Durchfallmann(800u,600u, 0u);

	try {
		game->init();
		game->run();
	}
	catch(ExceptionNoWindow &e) {
		std::cout << e.what() << std::endl;
		return 2;
	}
	catch(std::exception &e) {
		std::cout << "unexpected exception: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
