// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::drivetrainCANTalon1;
std::shared_ptr<CANTalon> RobotMap::drivetrainCANTalon2;
std::shared_ptr<CANTalon> RobotMap::drivetrainCANTalon3;
std::shared_ptr<CANTalon> RobotMap::drivetrainCANTalon4;
std::shared_ptr<RobotDrive> RobotMap::drivetrainRobotDrive;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init()
{
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow *lw = LiveWindow::GetInstance();

	drivetrainCANTalon1.reset(new CANTalon(0));
	lw->AddActuator("Drivetrain", "CANTalon1", drivetrainCANTalon1);

	drivetrainCANTalon2.reset(new CANTalon(1));
	lw->AddActuator("Drivetrain", "CANTalon2", drivetrainCANTalon2);

	drivetrainCANTalon3.reset(new CANTalon(2));
	lw->AddActuator("Drivetrain", "CANTalon3", drivetrainCANTalon3);

	drivetrainCANTalon4.reset(new CANTalon(3));
	lw->AddActuator("Drivetrain", "CANTalon4", drivetrainCANTalon4);

	drivetrainRobotDrive.reset(
			new RobotDrive(drivetrainCANTalon1, drivetrainCANTalon2,
					drivetrainCANTalon3, drivetrainCANTalon4));

	drivetrainRobotDrive->SetSafetyEnabled(true);
	drivetrainRobotDrive->SetExpiration(0.1);
	drivetrainRobotDrive->SetSensitivity(0.5);
	drivetrainRobotDrive->SetMaxOutput(1.0);

	try
	{
		navx = new NavX(SPI::Port::kMXP);
	}
	catch(std::exception ex)
	{
		printf("Error! NavX did not initialize correctly: " + ex.what());
	}
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
