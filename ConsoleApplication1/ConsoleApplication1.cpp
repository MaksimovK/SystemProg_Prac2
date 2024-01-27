#include <iostream>
#include <cstdlib>   
#include <ctime>

using namespace std;

int main()
{   
    setlocale(LC_ALL, "Russian");
    const int size = 10;
    int array[size];

    srand(time(0));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 21 - 10; 
    }

    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    int countNegative = 0;
   
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            countNegative++;
        }
    }

    cout << "Количество отрицательных элементов: " << countNegative << endl;

    return 0;
}