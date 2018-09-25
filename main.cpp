// THIS PROGRAM IS A SIMPLE SIMULATION OF A CONUN BULL

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// x = x0 + v0*t - 0.5*a*t*t

double compute_position(double x0, double v0, double a, double t)
{
	double pos = x0 + v0*t + 0.5*a*t*t;
	return pos;
}

int main()
{
	double x0 = 0.0;
	double y0 = 0.0;

	double speed = 0.0;
	cout << "Enter a speed:" << endl;
	cin >> speed;

	double theta = 0.0;
	cout << "Enter a launch angle (degrees):" << endl;
	cin >> theta;

	double pi = 4.0 * atan(1.0);

	double vx0 = speed * cos(theta * pi / 180.0);
	double vy0 = speed * sin(theta * pi / 180.0);

	double ax = 0.0;
	double ay = -9.81;

	double time = 0.0;
	double dt = 0.25;

	ofstream data_file("trajectory.dat");

	while (time < 10.0)
	{
		double x = compute_position(x0, vx0, ax, time);
		double y = compute_position(y0, vy0, ay, time);

		data_file << time << " " << x << " " << y << endl;
		time += dt;
	}
}

