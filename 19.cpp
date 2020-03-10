#include <iostream>
using namespace std;

void enterArr(int** ptr, int* rows, int* columns) {
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
            cin >> ptr[i][j];
}

void printArr(int** ptr, int* rows, int* columns) {
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            cout << ptr[i][j] << " ";
        }

        cout << endl;
    }
}

int multiplication(int ptr1, int* rows1, int* columns1, int** ptr2, int* rows2, int* columns2) {
    int** ptr3 = new int* [*rows1];
    for (int i = 0; i < *rows1; i++)
    {
        ptr3[i] = new int[*columns2];
        for (int j = 0; j < *columns2; j++)
        {
            ptr3[i][j] = 0;
            for (int k = 0; k < *columns1; k++)
                ptr3[i][j] += ptr1[i][k] * ptr2[k][j];
        }
    }
    return ptr3;
}


int main()
{
    int rows_1 = 0, columns_1 = 0;
    cout << "Enter the amount of row in matrix: " << endl;
    cin >> rows_1;

    cout << "Enter the amount of column in matrix: " << endl;
    cin >> columns_1;

    int** matrix1 = new int* [rows_1];
    for (int i = 0; i < rows_1; i++)
        matrix1[i] = new int[columns_1];

    enterArr(matrix1, &rows_1, &columns_1);
    printArr(matrix1, &rows_1, &columns_1);

    int rows_2 = 0, columns_2 = 0;
    cout << "Enter the amount of row in matrix: " << endl;
    cin >> rows_2;

    cout << "Enter the amount of column in matrix: " << endl;
    cin >> columns_2;

    int** matrix2 = new int* [rows_2];
    for (int i = 0; i < rows_2; i++)
        matrix2[i] = new int[columns_2];

    enterArr(matrix2, &rows_2, &columns_2);
    printArr(matrix2, &rows_2, &columns_2);


    if (rows_1 != columns_2)
        cout << "Matrixes cannot be multiplied!" << endl;
    else {
        cout << "Result matrix: " << endl;
        printArr(multiplication(matrix1, &rows_1, &columns_1, matrix2, &rows_2, &columns_2), &rows_1, &columns_2);
    }

    

    return 0;
}