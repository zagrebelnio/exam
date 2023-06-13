#include "day.h"

/*
������������ ���� "����" � ���� "������ �����". ���� "����" ������ ���������� ��� ����
(������ ����, �����, ��), ��� ������� ������ ���, � �������� ������ � ��� ����.
���� "������ �����" ������ ����� ��� � ����������� ��� ������ ����� � �� ��. �����
������ ���� ������������, ������ ��������� ��'����, ������ ��� ��������� �����������
�������, ������� ���� ������.

��������� ��������, ��� ������� ��'��� - ������ ����� �� ������� � ������� ���� � ���������
�������� ������ �� ��� �����.

�������� ��������� ��'��� � ���������� ���� � ��������� ����. ������� (���������) ���� ����������
����� ��� ���������.

�������� ������� ������������� ������ ��������� ��� �������, �������� �� �������� �����, � �����
�������� �������� �������. ��� ������� ������� (� ���� ���� � �� ���������� �������� �����)
����������� ������� ��������.
*/

int main() {
	try {
		int day, month, year;
		double wet;
		cout << "Enter the first day: " << endl;
		cout << "Enter day: ";
		cin >> day;
		cin.ignore();
		if (!day_valid(day)) {
			throw exception("The day is invalid!");
		}
		cout << "Enter month: ";
		cin >> month;
		cin.ignore();
		if (!month_valid(month)) {
			throw exception("The month is invalid!");
		}
		if (!date_exists(day, month)) {
			throw exception("The date doesn't exist!");
		}
		cout << "Enter year: ";
		cin >> year;
		cin.ignore();
		if (!year_valid(year)) {
			throw exception("The year is invalid!");
		}

		Day* days = new Day[7];

		for (int i = 0; i < 7; i++) {
			cout << "Day " << i + 1 << endl;
			cout << "Enter wetness: ";
			cin >> wet;
			cin.ignore();
			if (wet < 0) {
				throw exception("The wetness should be positive number!");
			}
			Day new_day(day, month, year, wet);
			days[i] = new_day;
			day++;
			if (day > 31 || ((day > 30) && (month == 4 || month == 6 || month == 9 || month == 11)) || (day > 29 && month == 2)) {
				day = 1;
				month = month % 12 + 1;
				if (month == 1) { year++; }
			}
		}

		Weather weather(7, days);

		cout << endl;
		weather.show_info();

		cout << endl;

		Day max = weather.max_wet();

		cout << "Day with the highest wetness: ";
		max.show();

		File file;
		file.write(weather);

		cout << endl << "File content: " << endl;
		file.read();
	}
	catch (const exception& e) {
		cout << "Error! " << e.what() << endl;
	}

	return 0;
}