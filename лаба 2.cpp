#include<iostream>
using namespace std;

int main() {
    {
    setlocale(0, "");
}
    int N, M;
    cout << "Задай размеры матрицы (N x M): ";
    cin >> N;
    cin >> M;

    int** Matrix = new int* [N];
    for (int i = 0; i < N; i++) {
        Matrix[i] = new int[M];
    }

    cout << "Заполни матрицу элементами по её размерам: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Matrix[i][j];
            
        }
    }

    int* max_element = &Matrix[1][0]; 
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i > j && Matrix[i][j] > *max_element) {
                max_element = &Matrix[i][j];
            }
        }
    }

    int* min_element = &Matrix[0][M - 2];
    for (int i = 0; i < N - 1; i++) {
        for (int j = M - 1; j > i; j--) {
            if (Matrix[i][j] < *min_element) {
                min_element = &Matrix[i][j];
            }
        }
    }

    cout << "Максимальный элемент ниже побочной диагонали матрицы: " << *max_element << endl;
    cout << "Минимальный элемент выше главной диагонали матрицы: " << *min_element << endl;

    for (int i = 0; i < N; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
    return 0;
}