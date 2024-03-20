#include <iostream>
#include <vector>

using namespace std;

template <class T>
void print_in_order(vector<T> &vec, int size, bool higher_to_lower)
{
    if (higher_to_lower)
    {
        for (int i = 1; i < size; ++i)
        {
            T key = vec[i];
            int j = i - 1;
            while (j >= 0 && vec[j] < key)
            {
                vec[j + 1] = vec[j];
                j = j - 1;
            }
            vec[j + 1] = key;
        }
    }
    else
    {
        for (int i = 1; i < size; ++i)
        {
            T key = vec[i];
            int j = i - 1;
            while (j >= 0 && vec[j] > key)
            {
                vec[j + 1] = vec[j];
                j = j - 1;
            }
            vec[j + 1] = key;
        }
    }

    for (int i = 0; i < size; ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vector1 = {3, 1, 6, 2, 5};
    cout << "Vector ordenado descendiente: ";
    print_in_order(vector1, vector1.size(), true);

    vector<float> vector2 = {3.5, 1.2, 6.7, 2.3, 5.1};
    cout << "Vector ordenado ascendente: ";
    print_in_order(vector2, vector2.size(), false);

    return 0;
}
