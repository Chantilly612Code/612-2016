#ifndef ShooterTest_H
#define ShooterTest_H

#include "WPILib.h"

class ShooterTest: public Command
{
public:
	ShooterTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif