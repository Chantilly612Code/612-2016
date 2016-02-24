// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Robot.h"

#include "Commands/ArmToPosition.h"
#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Arm/ArmMove.h"
#include "Commands/Autonomous/AutoWheels.h"
#include "Commands/Shooter/FireShooter.h"
#include "Commands/Drive/DriveSet.h"
#include <SmartDashboard/SmartDashboard.h>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<ShooterWheels> Robot::shooterwheels;
std::shared_ptr<ShooterRotation> Robot::shooterrotation;
std::shared_ptr<ShooterLever> Robot::shooterlever;
std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Shifter> Robot::shifter;
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit()
{
	RobotMap::init();
	navx = new NavX(SPI::Port::kMXP);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	drivetrain.reset(new Drivetrain());
	shooterwheels.reset(new ShooterWheels());
	shooterrotation.reset(new ShooterRotation());
	arm.reset(new Arm());
	shooterlever.reset(new ShooterLever());
	shifter.reset(new Shifter());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	SmartDashboard::PutData("FireShooter", new FireShooter());
	SmartDashboard::PutData("Autonomous", new Autonomous());
	SmartDashboard::PutData("DriveSet", new DriveSet(0.0f, 0.0f));
	SmartDashboard::PutData("DriveJoystick", new DriveJoystick());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new Autonomous());
	drivejoystick.reset(new DriveJoystick());
	//armmove.reset(new ArmMove());
	//autowheels.reset(new AutoWheels());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
	shooterrotation->SetAngle(3);
}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	drivejoystick->Start();
	//armmove->Start();
	//autowheels->Start();
	shifter->Set(Shifter::HIGH);
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
	shooterrotation->SetSpeed(oi->getGunner()->GetRawAxis(3));
}

void Robot::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Robot);

