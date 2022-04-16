#include <omp.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
    omp_set_num_threads(1);
    int i, j, n, m;
    //создаем массив
    cout << "Number of equations: ";
    cin >> n;
    cout << "Number of variables: ";
    cin >> m;
    m += 0;
    float** matrix = new float* [n];
#pragma omp parallel for
    for (i = 0; i < n; i++)
        matrix[i] = new float[m];
    //инициализируем
#pragma omp parallel for
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cout << " Element " << "[" << i + 1 << " , " << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    //выводим массив
    cout << "matrix: " << endl;
#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    //Метод Гаусса
    //Прямой ход
    float  tmp;
    int k;
    float* xx = new float[m];
#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
        tmp = matrix[i][i];
        for (j = n; j >= i; j--)
            matrix[i][j] /= tmp;
        for (j = i + 1; j < n; j++)
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }
  //  обратный ход
    xx[n - 1] = matrix[n - 1][n];
#pragma omp parallel for
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
    }
    //решениe
#pragma omp parallel for
    for (i = 0; i < n; i++)
        cout << xx[i] << " ";
    cout << endl;
    delete[] matrix;
    system("pause");
    return 0;
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
