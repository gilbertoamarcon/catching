#include <iostream>
#include "sim.hpp"

int main(int argc, char** argv){

	Sim sim = Sim();

	sim.addState("Home");
	sim.addState("School");
	sim.addState("Market");
	sim.addState("Laundry");

	sim.linkStates("Home","School");
	sim.linkStates("School","Home");
	sim.linkStates("School","Market");
	sim.linkStates("Market","School");
	sim.linkStates("Market","Home");
	sim.linkStates("Home","Market");
	sim.linkStates("Market","Laundry");
	sim.linkStates("Laundry","Market");

	sim.setInitialState("Home");

	std::string direction = "";

	while(direction != "exit"){
		std::cout << "=========================================" << std::endl;
		std::cout << "[" << sim.getCurrentState() << "] ";
		std::cout << "Directions:";
		for(const auto & direction : sim.getDirections())
			std::cout << " " << direction;
		std::cout << " ('exit' to leave)" << std::endl;
		std::cin >> direction;
		sim.move(direction);
	}

	return 0;


}
