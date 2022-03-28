#include <iostream>

using namespace std;

// prototyped the functions so that the compiler doesn't complain that it doesn't know wtf I'm doing
double bmr();
double physicalActivity();

// declaration of variables
double p, totalCalories, calories, servings; // these are global variables. p is the weight
int minutes, intensity; // these too...

int main()
{
	cout << "Survivor Logistics Planner" << endl;
	cout << "This program will help plan your foraging missions" << endl;
	cout << "\n";

	cout << "Please Enter your weight: ";
	cin >> p;

	cout << "Please Enter intensity of activity: ";
	cin >> intensity;

	cout << "Please Enter minutes of activty: ";
	cin >> minutes;

	cout << "Please Enter number of calories in available food: ";
	cin >> calories;
	cout << "\n";

	totalCalories = (bmr() + physicalActivity()) / 0.9;
	cout << "For the activity, the survivor will need a total of " << totalCalories << " calories";
	cout << "\n";

	servings = totalCalories / calories;
	printf("To maintain their weight, they will need to consume %.0lf", servings); cout << " servings of the available food.";
	cout << "\n";

	return -1;
}
 
double bmr()
{
	double calories; // this is a local variable
	calories = (p / 2.2) * 24.2;
	return calories;
}

double physicalActivity()
{
	double calories; // this is also a local variable
	calories = 0.0385 * intensity * p * minutes;
	return calories;
}




