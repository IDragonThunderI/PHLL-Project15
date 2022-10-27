#include <iostream>
#include <fstream>
using namespace std;

struct Train
{
	int number;
	char station[30];
	char time_start[6];
	char time_in_way[6];
	char ticket[4];
};

int main()
{
	system("chcp 1251");
	system("cls");

	Train a;
	int n;
	
	fstream f;
	f.open("f.dat", ios::in | ios::out | ios::trunc);
	if (!f.is_open())
	{
		cout << "file error!";
		exit(1);
	}
	cout << "Введите количество рейсов: ";
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nВведите номер поезда: ";
		cin >> a.number;
		cout << "\nВведите пункт прибытия: ";
		cin >> a.station;
		cout << "\nВведите время отправки (Пример: 06:00; 09:30; 15:00): ";
		cin >> a.time_start;
		cout << "\nВведите время в пути: ";
		cin >> a.time_in_way;
		cout << "\nВведите наличие билетов (Да или Нет): ";
		cin >> a.ticket;
		cout << endl;
		
		f << a.number << "\n" << a.station << "\n" << a.time_start << "\n" << a.time_in_way << "\n" << a.ticket << "\n";
	}
	
	char searching_station[30];
	char searching_time_A[6];
	char searching_time_B[6];
	cout << "\nВведите искомый пункт прибытия: ";
	cin >> searching_station;
	cout << "\nВведите начало интервала искомого времени отправки (Пример: 06:00; 09:30; 15:00): ";
	cin >> searching_time_A;
	cout << "\nВведите конец интервала искомого времени отправки (Пример: 06:00; 09:30; 15:00): ";
	cin >> searching_time_B;

	f.seekp(0);
	
	cout << "\n\nНайденные подходящие рейсы: " << endl;
	for (int i = 0; i < n; i++)
	{
		f >> a.number >> a.station >> a.time_start >> a.time_in_way >> a.ticket;
		
		if (strcmp(searching_station, a.station) == 0 && strcmp(searching_time_A, a.time_start) <= 0 && strcmp(searching_time_B, a.time_start) >= 0)
			cout << a.station << "; " << a.number << " => " << a.time_start << endl;
	}

	int searching_number;
	cout << "\n\nВведите искомый номер поезда: ";
	cin >> searching_number;

	f.seekp(0);

	for (int i = 0; i < n; i++)
	{
		f >> a.number >> a.station >> a.time_start >> a.time_in_way >> a.ticket;

		if (searching_number == a.number)
			cout << "\nНаличие билетов на выбранный рейс: " << endl << searching_station << "; " << searching_number << " => " << a.ticket << endl << endl;
	}
	
	f.close();
	
	system("Pause");
	return 0;
}