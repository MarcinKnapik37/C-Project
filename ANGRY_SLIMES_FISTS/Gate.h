#pragma once

class Gate{
private:
	int demand;
	int active;
public:
	Gate();
	~Gate();
	void setDemand(int x );
	int getDemand();
	bool isActive();
	void setUnactive();
};