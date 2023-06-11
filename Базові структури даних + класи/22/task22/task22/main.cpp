#include "auto.h"

int main() {
	List list;
	int num;
	cout << "Enter number of cars: ";
	cin >> num;
	cin.ignore();
	string mark;
	int year, speed;
	for (int i = 0; i < num; i++) {
		cout << "Car " << i + 1 << endl;
		cout << "Enter mark: ";
		getline(cin, mark);
		cout << "Enter year: ";
		cin >> year;
		cin.ignore();
		cout << "Enter speed: ";
		cin >> speed;
		cin.ignore();
		Auto car(mark, year, speed);
		list.push_back(car);
	}
	cout << "List: " << endl;
	list.show();

	Auto max_speed_car = list.max_speed();
	Auto max_year_car = list.max_year();

	cout << "The car with the max speed:" << endl;
	max_speed_car.show_info();
	cout << "The car with the latest year:" << endl;
	max_year_car.show_info();

	compare_cars(max_speed_car, max_year_car);

	List modified = list.modify(max_speed_car.get_year());

	cout << "Modified list: " << endl;
	modified.show();

	return 0;
}