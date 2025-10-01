#pragma once
#include <string>
#include <vector>
#include <memory>

#ifndef AIBASE
#define AIBASE

namespace gtk {

	class State {

	public:

		virtual std::string Encode() = 0;
	};


	class Action {

	public:

		std::string name;

		Action() = delete;
		Action(std::string name) : name(name) {}

		virtual std::shared_ptr<State> Execute(std::shared_ptr<State> state) = 0;
		virtual bool CanExecute(std::shared_ptr<State> state) = 0;

	};

	class Decision {
		
	protected:
		std::vector<std::shared_ptr<Action>> actions;
		std::shared_ptr<State> goalState;

	public:

		Decision() = delete;
		Decision(std::shared_ptr<State> goal) : goalState(goal) {}

		virtual void DecisionFunction(std::shared_ptr<State> currentState) = 0;
		
	};
}

#endif // !AIBASE
