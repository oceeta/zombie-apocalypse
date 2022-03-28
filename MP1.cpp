#include <iostream> // Provides basic input and output services.
#include <cmath> // Include this to use the trig and floor functions that our program will make use of.

// Include this to avoid having to use std::cout or std::cin
using namespace std;

// Execution of your program starts and ends in the main() function.
int main()
{
	// Our Program Title
	cout << "Daylight-Sensitive Zombie Protection System" << endl;
	// For a space between our program title and the rest of the program. I did this all over the program for aesthetic purposes.
	cout << "" << endl;

	cout << "This program will calculate the sunrise and sunset time for any date and location" << endl;
	cout << "Good luck as we survive this zombie apocalypse together, my fellow homo sapien!" << endl;
	cout << "'Say NO to Zombification'" << endl;
	cout << "" << endl;

	/* We need the following four inputs to run this program: Latitude, longitude, timezone, and day of the year. These values will help us calculate the sunrise and sunset time in a
	* given location (longitude and latitude) and time zone.
	// I feel like we need some code to help check that the values we receive from the viewer, especially for longitude and latitude actually make sense
	// Min/Max Value of Latitude = -90S/+90N (Remember the poles make a 90 degree angle with the prime meridian (0,0))
	// Min/Max Value of Longitude = -180W/+180E (Travelling 180 degrees in either direction from the prime meridian will lead to 180 degrees latitude, or the opposite meridian)*/


	// Displays the text in cout, then prompts the user to input the latitude using cin
	// I also feel the need to create functions for latitudes, longitudes, time zones, and days of the year. How will our program handle the wrong input from a user?

	cout << "Please Enter the LATITUDE" << endl;
	float latitude;
	cin >> latitude;
	cout << "" << endl;

	// Displays the text in cout, then prompts the user to input the longitude using cin
	cout << "Please Enter the LONGITUDE" << endl;
	float longitude;
	cin >> longitude;
	cout << "" << endl;

	// Displays the text in cout, then prompts the user to input the time zone using cin
	cout << "Please Enter the TIME ZONE" << endl;
	int timeZone;
	cin >> timeZone;
	cout << "" << endl;

	// Displays the text in "cout", then prompts the user to input the day of the year using "cin"
	// We might need a line of code to check if the year is a leap year or not. Can't have people dying to a zombie apocalypse due to our own miscalculations
	// We might also need a line of code to make sure that the value of dayOfYear is positive
	cout << "Please Enter the DAY OF THE YEAR" << endl;
	int dayOfYear;
	cin >> dayOfYear;
	cout << "" << endl;
	cout << "" << endl;


	// Declare the variable pi and assign the value of "3.1415..." to it. It's a pretty large value, so double is the data type we should use
	double pi;
	pi = 3.141592654;


	// Converts our dayOfYear value to a value in radians
	double dayOfYearRad;
	dayOfYearRad = (2 * pi / 365) * (dayOfYear - 1);

	// Equation of time in MINUTES (the number of minutes that the position of the sun differs from the actual time)
	double eqTime;
	eqTime = 229.18 * (0.000075 + (0.001868 * cos(dayOfYearRad)) - (0.032077 * sin(dayOfYearRad))
		- (0.014615 * cos(2 * dayOfYearRad)) - (0.040849 * sin(2 * dayOfYearRad)));

	// Decliniation of the sun in radians. Broke the code into pieces to make it a bit easier to read
	double decl;
	decl = 0.006918 - (0.399912 * cos(dayOfYearRad)) + (0.070257 * sin(dayOfYearRad))
		- (0.006758 * cos(2 * dayOfYearRad)) + (0.000907 * sin(2 * dayOfYearRad))
		- (0.002697 * cos(3 * dayOfYearRad)) + (0.00148 * sin(3 * dayOfYearRad));

	// Hour angle of the sun in DEGREES
	double hourAngle;
	hourAngle = acos((cos(1.5853)) / (cos(latitude * (pi / 180)) * cos(decl)) - ((tan(latitude * pi / 180)) * tan(decl))) * 180 / pi;

	// Time in local minutes
	double sunrise, sunset;
	sunrise = 720 + (4 * (longitude - hourAngle)) - eqTime - (60 * timeZone);
	// Time in UTC minutes of sunset 
	sunset = 720 + (4 * (longitude + hourAngle)) - eqTime - (60 * timeZone);

	// Floor function from the cmath library to round down our float values. Also remember that you can declare functions using "," to save line space and look professional.
	// Changed from float to double to account for memory loss
	double sunriseHour, sunsetHour;
	sunriseHour = floor(sunrise / 60);
	sunsetHour = floor(sunset / 60);

	// Used int here because we need the minute values to be whole numbers and nothing else. Besides, we don't have the floor function here (or something similar) to approximate numbers.
	int sunriseMin, sunsetMin;
	sunriseMin = sunrise - (sunriseHour * 60);
	sunsetMin = sunset - (sunsetHour * 60);

	// Displays the sunrise time and sunset time. You can place the colon as a string value in-between sunriseHour and sunriseMin.
	cout << "SUNRISE AND SUNSET TIMES" << endl;

	// Line of code to check if the sunriseMin variable has a value that is less than or equal to 9.
	// The code checks the value, then either prints an output with a 0 in front, or hides the zero completely.
	// This is the same thing that's happening with the sunsetMin variable.
	if (sunriseMin <= 9)
		cout << "The Sunrise time is: " << sunriseHour << ":0" << sunriseMin << endl;
	else cout << "The Sunrise time is: " << sunriseHour << ":" << sunriseMin << endl;

	if (sunsetMin <= 9)
		cout << "The Sunset time is: " << sunsetHour << ":0" << sunsetMin << endl;
	else cout << "The Sunrise time is: " << sunsetHour << ":" << sunsetMin << endl;

	// Of course, we have the trusty "return 0;" statement here to return the value 0 if and only if our code runs properly.
	return 0;
}
