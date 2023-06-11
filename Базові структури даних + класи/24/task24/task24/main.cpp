#include "rectangle.h"

int main() {
	List list;
	int num;
	cout << "Enter number of rectangles: ";
	cin >> num;
	cin.ignore();
	double width, height;
	for (int i = 0; i < num; i++) {
		cout << "Rectangle " << i + 1 << endl;
		cout << "Enter width: ";
		cin >> width;
		cin.ignore();
		cout << "Enter height: ";
		cin >> height;
		cin.ignore();
		Rectangle rect(width, height);
		list.push_back(rect);
	}

	cout << "List: " << endl;
	list.show();

	list.area_sort();
	cout << "Area sorted list: " << endl;
	list.show();

	Rectangle biggest = list.end();
	double sum = biggest.get_height() + biggest.get_width();
	list.check_rects(sum);

	return 0;
}