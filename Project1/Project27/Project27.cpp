// Project27.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<thread>

using namespace std;

int Х1 = 0;
int Х2 = 0;
void print(int n, char k) {
	
	for (int i = 0; i < n; ++i)
	{
		if (k == '1') {
			if (Х2 % 2 == 0) { cout << "?"; Х1++; }
		}
		if (k == '0') {
			if (Х1 % 2 == 0) { cout << "%"; Х2++; }
		}
	}
	cout << endl;
	
}

int main()
{
	
		thread t1(print, 10, '1');
		thread t2(print, 10, '0');

		t1.join();
		t2.join();
		cout << "X1 = " << Х1 << "; X2 = " << Х2 << endl;
	}
	





// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
