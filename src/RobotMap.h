// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap
{
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<Talon> drivetrainTalon1;
	static std::shared_ptr<Talon> drivetrainTalon2;
	static std::shared_ptr<Talon> drivetrainTalon3;
	static std::shared_ptr<Talon> drivetrainTalon4;
	static std::shared_ptr<RobotDrive> drivetrainRobotDrive;
	static std::shared_ptr<Servo> shooterLeverServo1;
	static std::shared_ptr<AnalogInput> shooterEncoder;
	static std::shared_ptr<CANTalon> armAdjust;
	static std::shared_ptr<AnalogInput> armRotationDetect;
	static std::shared_ptr<CANTalon> shooterRotateMotor;
	static std::shared_ptr<AnalogInput> shooterLeverDetect;
	static std::shared_ptr<Servo> shifterServo1;
	static std::shared_ptr<Servo> shifterServo2;
	static std::shared_ptr<CANTalon> leftFlywheel;
	static std::shared_ptr<CANTalon> rightFlywheel;
	static std::shared_ptr<Encoder> drivetrainEncoder;
	static const int leftFlywheelHall = 6;
	static const int rightFlywheelHall = 7;
	static constexpr float flywheelShootSpeed = 40.0f;
	static constexpr float flywheelIntakeSpeed = -20.0f;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static void init();
	//static bool isRobotReversed;
};
#endif
