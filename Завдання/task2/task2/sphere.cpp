#include "sphere.h"

Sphere::Sphere(double radius) : radius(radius)
{
}

double Sphere::area()
{
	return 4 * PI * radius * radius;
}

void Sphere::show()
{
	cout << "Radius: " << radius << endl;
	cout << "Area: " << area() << endl;
}

string Sphere::line()
{
	string line = "";
	line += to_string(radius);
	line += " ";
	line += to_string(area());
	return line;
}

void File::write(Sphere* spheres, int num)
{
	ofstream fout(name);
	for (int i = 0; i < num; i++) {
		fout << spheres[i].line() << endl;
	}
}

void File::read()
{
	fstream fin(name);
	if (!fin.is_open()) {
		throw (exception("Can't open a file!"));
	}
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
}
