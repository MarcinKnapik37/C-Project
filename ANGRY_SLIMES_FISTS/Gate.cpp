#include"Gate.h"

Gate::Gate(){
	active = 1;
}
Gate::~Gate(){}

void Gate::setDemand( int x ){
	demand = x;
}

int Gate::getDemand(){
	return demand;
}

bool Gate::isActive(){
	return active;
}

void Gate::setUnactive(){
	active = 0;
}
