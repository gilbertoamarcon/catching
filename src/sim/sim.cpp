#include <iostream>
#include "sim.hpp"


Sim::Sim() {
	this->initialState = "";
	this->currentState = "";
};

const unsigned int Sim::getNumStates() const{
	return (unsigned int) transitionTable.size();
};

const bool Sim::isState(const std::string & name) const{
	return transitionTable.find(name) != transitionTable.end();
};

const bool Sim::areLinkedStates(const std::string & origin, const std::string & destination) const{
	if(isState(origin) && isState(destination)){
		std::unordered_set<std::string> destinations = getDestinationStates(origin);
		return destinations.find(destination) != destinations.end();
	}else
		return false;
};

const std::unordered_set<std::string> Sim::getDestinationStates(const std::string & name) const {
	if(isState(name))
		return transitionTable.at(name);
	else
		return std::unordered_set<std::string>{};
};

const std::unordered_set<std::string> Sim::getDirections() const {
	return getDestinationStates(currentState);
};

void Sim::addState(const std::string & name){
	transitionTable[name] = std::unordered_set<std::string>{};
};

void Sim::setInitialState(const std::string & name){
	if(isState(name)){
		initialState = name;
		currentState = name;
	}
};

void Sim::linkStates(const std::string & origin, const std::string & destination){
	if(isState(origin) && isState(destination))
		transitionTable[origin].insert(destination);
};

void Sim::move(const std::string & name){
	if(areLinkedStates(currentState,name))
		currentState = name;
};

