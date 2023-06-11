#include "triangle.h"

int main() {
	List list;
	int num;
	cout << "Enter number of triangles: ";
	cin >> num;
	cin.ignore();
	double a, b, c;
	for (int i = 0; i < num; i++) {
		cout << "Triangle " << i + 1 << endl;
		cout << "Enter side a: ";
		cin >> a;
		cin.ignore();
		cout << "Enter side b: ";
		cin >> b;
		cin.ignore();
		cout << "Enter side c: ";
		cin >> c;
		cin.ignore();
		Triangle triangle(a, b, c);
		list.push_back(triangle);
	}

	cout << "List: " << endl;
	list.show();

	list.perimeter_sort();
	cout << "Perimeter sorted list: " << endl;
	list.show();

	double max_side = list.end().longest_side();
	cout << "Max side: " << max_side << endl;

	list.check_perimeters(max_side);

	return 0;
}