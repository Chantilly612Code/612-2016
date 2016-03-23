#include "SetShooterAngle.h"
#include "Robot.h"

SetShooterAngle::SetShooterAngle()
{
	//Set the angle to the calculated angle needed to make the goal
	Requires(Robot::shooterrotation.get());
	Requires(Robot::vision.get());
	this->end_angle = 0.0;

	//get vision values
	std::shared_ptr<NetworkTable> table = Robot::vision.get()->GetRawTable();
	llvm::ArrayRef<double> arr;

	if(!(Robot::vision->GetTargetAmount() > 0 && table->GetNumberArray("BOUNDING_COORDINATES", arr).size() > 8)) //if a target is queued and if the target has all 4 coordinates (8 values, 2 x 2 y)
	{
		target_exists = Robot::vision.get()->UpdateCurrentTarget();
	}
}

SetShooterAngle::SetShooterAngle(float end_angle)
{
	/*
	 * This command can also be used to set for a specified angle
	 * Use this for shooter presets!
	 */
	Requires(Robot::shooterrotation.get());
	this->end_angle = end_angle;
	target_exists = false;
}

void SetShooterAngle::Initialize()
{
	/*
	 * Should this be empty? Testing to make sure...
	 */

	if(target_exists)
	{
		Robot::vision.get()->UpdateCurrentTarget(); //make sure the targets are updated
		end_angle = CalcAngle();
	}
}

void SetShooterAngle::Execute()
{
	Robot::shooterrotation.get()->ShootPos(end_angle);
}

bool SetShooterAngle::IsFinished()
{
	return Robot::shooterrotation.get()->getPIDOnTarget();
}

void SetShooterAngle::End()
{
	RobotMap::shooterRotateMotor.get()->Set(0.0f);
}

void SetShooterAngle::Interrupted()
{
	RobotMap::shooterRotateMotor.get()->Set(0.0f);
}

double SetShooterAngle::CalcAngle()
{
	if(target_exists)
	{
		double h = Robot::vision.get()->GetTrackedGoal()->GetHeight();
		double x = (0.0001592 * pow(h, 2)) - (0.06046*h) + 6.9204;
		printf("\nDistance Calculation: %f", x);
		double y = TARGET_HEIGHT_OFF_GROUND;
		double v = BOULDER_LAUNCH_SPEED;
		double g = 9.8; //gravity
		double sq = pow(v, 4) - (g * (g * (x * x) + 2 * y * (v * v)));

		sq = sqrt(abs(sq));

		double angleInRadians = atan(((v * v) - sq) / (g * x));
		double angleInDegrees = angleInRadians * (180 / M_PI);
		printf("Degree Calculation: %f\n", angleInDegrees);
		return angleInDegrees;
	}
	else
		return 0.0;
}
