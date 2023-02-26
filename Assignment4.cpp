#include <iostream>
using namespace std;

void sort(int arr1[], int n)
{
    int arr_even[n];
    int arr_odd[n];
    int length_even = 0;
    int length_odd = 0;

    // Category odd and even numbers
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] % 2 == 0)
        {
            arr_even[length_even] = arr1[i];
            length_even++;
        }
        if (arr1[i] % 2 != 0)
        {
            arr_odd[length_odd] = arr1[i];
            length_odd++;
        }
    }

    // odd sort
    for (int i = 0; i < length_odd - 1; i++)
    {
        for (int j = 0; j < length_odd - i - 1; j++)
        {
            if (arr_odd[j] > arr_odd[j + 1])
            {
                int temp = arr_odd[j];
                arr_odd[j] = arr_odd[j + 1];
                arr_odd[j + 1] = temp;
            }
        }
    }
    
    // Print odd numbers first
    for (int i = 0; i < length_odd; i++)
    {
        cout << arr_odd[i] << " ";
    }

    // even sort
    for (int i = 0; i < length_even; i++)
    {
        for (int j = 0; j < length_even - i - 1; j++)
        {
            if (arr_even[j] < arr_even[j + 1])
            {
                int temp = arr_even[j];
                arr_even[j] = arr_even[j + 1];
                arr_even[j + 1] = temp;
            }
        }
    }

    // print even numbers
    for (int i = 0; i < length_even; i++)
    {
        cout << arr_even[i] << " ";
    }
}

int main()
{
    int arr[1000];
    int length = 0;
    int num;
    bool finish = false;

    // store numbers in the array
    cout << "Enter a sequence of integer (-999 to finish): ";
    while (!finish)
    {
        cin >> num;
        if (length == 1000 || num == -999)
        {
            finish = true;
        }
        else
        {
            arr[length] = num;
            length++;
        }
    }

    sort(arr, length);

    cout << endl;
    system("pause");
    return 0;
}