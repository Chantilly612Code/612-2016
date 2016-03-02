// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef ARM_H
#define ARM_H
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "CANTalon.h"
#include "AnalogInput.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Arm: public PIDSubsystem
{
private:
	std::shared_ptr<CANTalon> adjust;
	std::shared_ptr<AnalogInput> rotationDetect;

	/*
	 * TODO: Needs hardware testing
	 */

	double MIN_VOLTS = 1.1f; //all the way in
	double MAX_VOLTS = 4.0f; //all the way out

public:
	Arm();
	void InitDefaultCommand();
	float getMin();
	float getMax();
	void setArmPosition(float pos);
	float getArmPosition();
	void SetMode(CANTalon::ControlMode mode);
	void UsePIDOutput(double output);
	double ReturnPIDInput();

	void SetArmPosition(double position);
	void SetArmSpeed(double speed);
};

#endif
