//============================================================================
// Name        : StatePattern.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : state-pattern in C++
//============================================================================

#include <iostream>

class StateHandler
{
public:
	virtual StateHandler *getNextState() = 0;
	virtual std::string getDescription( std::string &name ) = 0;
	virtual ~StateHandler() {};
};

class Purchased: public StateHandler
{
	StateHandler *nextState = nullptr;
public:
	Purchased( StateHandler *nextState ): nextState(nextState) {};
	virtual ~Purchased() {};
	StateHandler *getNextState() override {
		return nextState;
	}
	std::string getDescription( std::string &name ) override {
		std::string description = name + " will be shipping soon\n";

		return description;
	}
};

class InTransit: public StateHandler
{
	StateHandler *nextState = nullptr;
public:
	InTransit( StateHandler *nextState ): nextState(nextState) {};
	virtual ~InTransit() {};
	StateHandler *getNextState() override {
		return nextState;
	}
	std::string getDescription( std::string &name ) override {
		std::string description = name +  " is on the way\n";

		return description;
	}

};

class Delivered: public StateHandler
{
	StateHandler *nextState = nullptr;
public:
	Delivered( StateHandler *nextState ): nextState(nextState) {};
	virtual ~Delivered() {};
	StateHandler *getNextState() override {
		return nextState;
	}
	std::string getDescription( std::string &name ) override {
		std::string description = name + " has arrived\n";

		return description;
	}
};
class Purchase {
    std::string productName;
    StateHandler *currentState = nullptr;
public:
    Purchase(const std::string & productName, StateHandler *currentState )
        : productName(productName), currentState(currentState) {};

    void goNextState() {
    	if( currentState->getNextState() )
    	{
    		currentState = currentState->getNextState();
    	}
    	else
    	{
    		std::cout << "There is no nextState !" << std::endl;
    	}
    }
    std::string getDescription() {
    	if( currentState )
    		return currentState->getDescription( productName );
    	else
    		return "ERROR, There is no State\n";
    }
};

int main(int argc, const char * argv[]) {
	Delivered *deliveredState = new Delivered(nullptr);
    InTransit *inTransitState = new InTransit(deliveredState);
    Purchased *purchasedState = new Purchased(inTransitState);

    Purchase *purchase = new Purchase("Shoes", purchasedState);
    Purchase *purchase2 = new Purchase("Computer", inTransitState);

    std::cout << purchase->getDescription();

    purchase->goNextState();
    std::cout << purchase->getDescription();

    purchase->goNextState();
    std::cout << purchase->getDescription();

    std::cout << std::endl;

    std::cout << purchase2->getDescription();

    purchase2->goNextState();
    std::cout << purchase2->getDescription();

    purchase2->goNextState();
    std::cout << purchase2->getDescription();



    delete deliveredState;
    delete inTransitState;
    delete purchasedState;
    delete purchase;
    delete purchase2;

    return 0;
}


