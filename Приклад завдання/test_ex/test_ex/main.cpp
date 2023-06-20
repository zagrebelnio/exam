#include "set.h"

/*  ������������ ���� �Set�, ���� ������ ������� ������������� ��������, ����'������ 
��������� � �������������. ����������� � ���� ����������� �� �������������, ���� �������
������� �������.
  ��� ����� �Set� ��������� �������� ��'������� "+" ������, �������� �������� "*" ������, 
  �������� ������ "/" ������. ���������������� ����� ��������.
  ����������� ������ ��������� �������� � ������� �� ��������� �������� � ������� (������� 
  ���� ��������� �������� �������� ������� � ���������).
  ��� ������� ������� (� ���� ���� � �� ���������� �������� �����) ����������� ������� ��������.
  ���������� ����� ������ ������� � ��������� ���� �� ������� ������ �����.*/

int main() {
	try {
		string input;
		Set set1, set2;
		int num;
		cout << "Enter number of elements to insert: ";
		cin >> input;
		cin.ignore();
		num = stoi(input);
		if (num < 1) {
			throw exception("There should be at least 1 number to enter!");
		}
		for (int i = 0; i < num; i++) {
			int value;
			cout << "Enter number " << i + 1 << ": ";
			cin >> input;
			cin.ignore();
			value = stoi(input);
			set1.insert(value);
		}

		cout << "Enter number of elements to insert: ";
		cin >> input;
		cin.ignore();
		num = stoi(input);
		if (num < 1) {
			throw exception("There should be at least 1 number to enter!");
		}
		for (int i = 0; i < num; i++) {
			int value;
			cout << "Enter number " << i + 1 << ": ";
			cin >> input;
			cin.ignore();
			value = stoi(input);
			set2.insert(value);
		}

		cout << endl;

		cout << "Set 1: ";
		set1.show();

		cout << "Set 2: ";
		set2.show();

		cout << endl;

		Set sum = set1 + set2;

		Set intersection = set1 * set2;

		Set difference = set1 / set2;

		cout << "Sum of sets: ";
		sum.show();
		cout << endl;

		cout << "Intersection of sets: ";
		intersection.show();
		cout << endl;

		cout << "Difference of sets: ";
		difference.show();
		cout << endl;

		string filename;
		cout << "Enter the filename: ";
		getline(cin, filename);

		File file(filename);

		file.write(set1);
		file.write(set2);

		cout << "Content of file: " << endl;
		file.read();

	}
	catch (const exception& e) {
		cout << "Error! " << e.what() << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Error! " << e.what() << endl;
	}
	return 0;
}