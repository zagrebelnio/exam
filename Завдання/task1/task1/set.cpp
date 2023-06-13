#include "set.h"

char Set::operator[](int i)
{
	return data[i];
}

int Set::get_size()
{
	return size;
}

void Set::add(const char& value)
{
	if (!is_full()) {
		data[size] = value;
		size++;
	}
}

void Set::remove(const char& value)
{
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			data[i] = data[size - 1];
			size--;
			return;
		}
	}
}

Set Set::operation(Set other)
{
	Set result;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < other.size; j++) {
			if (data[i] == other.data[j]) {
				result.add(data[i]);
				other.remove(data[i]);
				break;
			}
		}
	}
	cout << "Перетин: ";
	result.show();
	return result;
}

bool Set::is_full()
{
	return size == MAX_SIZE;
}

string Set::line()
{
	string line = "";
	for (int i = 0; i < size; i++) {
		line += data[i];
		line += ":";
	}
	line.erase(2 * size - 1, 1);
	return line;
}

void Set::show()
{
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

void File::write(Set& set1, Set& set2, Set& set3)
{
	ofstream fout(name);
	fout << set1.line() << "\n" << set2.line() << "\n" << set3.line();
	fout.close();
}

void File::show()
{
	ifstream fin(name);
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
}
