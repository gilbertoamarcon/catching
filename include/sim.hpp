#ifndef __SIM_HPP__
#define __SIM_HPP__

#include <string>
#include <unordered_set>
#include <unordered_map>

class Sim {
private:
	std::string initialState;
	std::string currentState;
	std::unordered_map<std::string,std::unordered_set<std::string>> transitionTable;
	const std::unordered_set<std::string> getDestinationStates(const std::string & name) const;
public:
	Sim();
	const std::string getInitialState() const {return initialState;};
	const std::string getCurrentState() const {return currentState;};
	const unsigned int getNumStates() const;
	const bool isState(const std::string & name) const;
	const bool areLinkedStates(const std::string & origin, const std::string & destination) const;
	const std::unordered_set<std::string> getDirections() const;
	void addState(const std::string & name);
	void setInitialState(const std::string & name);
	void linkStates(const std::string & origin, const std::string & destination);
	void move(const std::string & name);
};


#endif
