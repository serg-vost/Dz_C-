#include <iostream>

// Функция inversion принимает на вход двумерный массив A размерности NxN и целочисленное значение N
void inversion(double** A, int N) {

    // Объявляем временную переменную temp
    double temp;
    // Создаем новый двумерный массив E размерности NxN и заполняем его нулями
    double** E = new double* [N];
    for (int i = 0; i < N; i++)
        E[i] = new double[N];
    // Заполняем массив E единицами по диагонали
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            E[i][j] = 0.0;
            if (i == j)
                E[i][j] = 1.0;
        }
    // Прямой ход метода Гаусса
    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];
        // Деление строки k на элемент A[k][k] и соответствующие операции с матрицей E
        for (int j = 0; j < N; j++)
        {
            A[k][j] /= temp;
            E[k][j] /= temp;
        }
        // Отнимание от оставшихся строк k-ой строки, умноженной на соответствующий коэффициент
        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];
            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    // Обратный ход метода Гаусса
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];
            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    // Записываем результат обратной матрицы в исходный массив A
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = E[i][j];
    // Освобождаем память, выделенную для массива E
    for (int i = 0; i < N; i++)
        delete[] E[i];
    delete[] E;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int N;

    std::cout << "Enter N: ";
    std::cin >> N;

    double** matrix = new double* [N];

    for (int i = 0; i < N; i++)
        matrix[i] = new double[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            std::cout << "Enter matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }


    inversion(matrix, N);

    if (matrix[0][1] < 0.00000001) {

        std::cout << "Матрицу найти невозможно";

    }
    else {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                std::cout << matrix[i][j] << "  ";

            std::cout << std::endl;
        }

        for (int i = 0; i < N; i++)
            delete[] matrix[i];

        delete[] matrix;

        std::cin.get();
        return 0;
    }

    
}