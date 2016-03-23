#include <Commands/Shooter/ShooterControl.h>
#include <Commands/Shooter/FireShooter.h>
#include "OI.h"
#include "Commands/Autonomous/Autonomous.h"
#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Drive/SetGear.h"

OI::OI()
{
	//GUNNER
	gunner.reset(new Joystick(1));

	// NOTE: Buttons 1-4 are reserved for shooter (aka A, B, X, Y)

	//servoPush.reset(new JoystickButton(gunner.get(), 1));
	//servoPush->WhenPressed(new FireShooter(ShooterServoPosition::Push));

	//servoClamp.reset(new JoystickButton(gunner.get(), 2));
	//servoClamp->WhenPressed(new FireShooter(ShooterServoPosition::Clamp));

	//DRIVER
	driver.reset(new Joystick(0));

	//resetButton.reset(new JoystickButton(driver.get(), 2));
	//resetButton->WhenPressed(new DriveJoystick());

	lowGear.reset(new JoystickButton(driver.get(), 5));
	lowGear->WhenPressed(new SetGear(Shifter::LOW));

	highGear.reset(new JoystickButton(driver.get(), 6));
	// TODO: Change this back to Shifter::HIGH when shifters are fixed
	highGear->WhenPressed(new SetGear(Shifter::HIGH));
}

std::shared_ptr<Joystick> OI::getDriver()
{
	return driver;
}

std::shared_ptr<Joystick> OI::getGunner()
{
	return gunner;
}
