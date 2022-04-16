// Project27.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex mtx;
int X1 = 0;
int X2 = 0;
void print(int n, char k) {
	mtx.lock();
	for (int i = 0; i < n; ++i)
	{
		if (k == '1') {
			if (X2 % 2 == 0) { cout << "?"; X1++; }
		}
		if (k == '0') {
			if (X1 % 2 == 0) { cout << "%"; X2++; }
		}
	}
	cout << endl;
	mtx.unlock();
}
mutex rr_lock;
void threadFunction()
{
	rr_lock.lock();

	cout << "entered thread " << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::seconds(rand() % 10));
	cout << "leaving thread " << this_thread::get_id() << endl;

	rr_lock.unlock();
}
int main()
{
	
		srand((unsigned int)time(0));
		thread t1(threadFunction);
		thread t2(threadFunction);
		thread t3(threadFunction);
		t1.join();
		t2.join();
		t3.join();
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
