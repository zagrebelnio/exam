#include "sphere.h"

int main() {
	try {
		int num;
		cout << "Enter number of spheres: ";
		cin >> num;
		cin.ignore();

		if (num < 1) {
			throw exception("Enter at least 1 sphere.");
		}

		Sphere* spheres = new Sphere[num];
		double radius;

		for (int i = 0; i < num; i++) {
			cout << "Sphere " << i + 1 << endl;
			cout << "Enter radius: ";
			cin >> radius;
			cin.ignore();

			if (radius <= 0) {
				throw exception("Radius should be a positive number!");
			}

			Sphere sphere(radius);
			spheres[i] = sphere;
		}

		cout << endl;

		for (int i = 0; i < num; i++) {
			cout << "Sphere " << i + 1 << endl;
			spheres[i].show();
		}

		File file;

		file.write(spheres, num);

		cout << "File data: " << endl;;

		file.read();

	}
	catch (const exception& e) {
		cout << "Error!\n" << e.what() << endl;
	}
	catch (...) {
		cout << "Unknown error!" << endl;
	}
	return 0;
}