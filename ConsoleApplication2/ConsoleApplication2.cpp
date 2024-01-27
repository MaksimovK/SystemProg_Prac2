#include <iostream>
#include <vector>
#include <cstdlib>   
#include <ctime>  

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int numArrays;
    cout << "Введите количество массивов: ";
    cin >> numArrays;

    for (int i = 0; i < numArrays; i++) {
        const int numRows = 3;
        const int numCols = 3;

        int array[numRows][numCols];
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                array[row][col] = rand() % 10;  
            }
        }

        cout << "Двумерный массив " << i + 1 << ":\n";
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                cout << array[row][col] << " ";
            }
            cout << endl;
        }

        int zeroCount = 0;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (array[row][col] == 0) {
                    zeroCount++;
                }
            }
        }

        cout << "Количество нулевых элементов: " << zeroCount << "\n\n";
    }

    return 0;
}
