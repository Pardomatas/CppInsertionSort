#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int smallest(int array[], int size, int index);
void swap(int array[], int first_index, int second_index);

////////////////////////////////////////////////////////////////////////////

void sort(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int index = smallest(array, size, i);
        swap(array, i, index);
    }
}

////////////////////////////////////////////////////////////////////////////

int smallest(int array[], int size, int index)
{
    int smallest_index = index;
    for(int i = index + 1; i < size; i++)
    {
        if(array[i] < array[smallest_index])
        {
            smallest_index = i;
        }
    }
    return smallest_index;
}

////////////////////////////////////////////////////////////////////////////

void swap(int array[], int first_index, int second_index)
{
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

////////////////////////////////////////////////////////////////////////////

void displayArray(int array[], int size)
{
    cout << "{";
    for(int i = 0; i < size; i++)
    {
        if(i != 0)
        {
            cout << ", ";
        }
        cout << array[i];
    }
    cout << "}";
}

////////////////////////////////////////////////////////////////////////////

int main()
{
    int array[10];
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        array[i] = rand() % 100;
    }
    cout << "Original array: ";
    displayArray(array, 10);
    cout << '\n';

    sort(array, 10);
    cout << "Sorted array: ";
    displayArray(array, 10);
    cout << '\n';

    return 0;
}
