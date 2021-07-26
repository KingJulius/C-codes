#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    T *data;
    int length;
    int size;

public:
    void Append(int val);
    int Get(int index);
    void Display();
    ~Array();
    Array(int size);
    Array();
};

template <class T>
void Array<T>::Append(int val)
{
    if (length < size)
    {
        data[length++] = val;
    }
}

template <class T>
int Array<T>::Get(int index)
{
    if (index <= length && index >= 0)
        return data[index];
    else
        return -1;
}

template <class T>
void Array<T>::Display()
{
    cout << "The Elements are: ";
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << "\n";
}

template <class T>
Array<T>::~Array()
{
    delete[] data;
}

template <class T>
Array<T>::Array(int length)
{
    this->length = length;
    this->size = length > 0 ? length * 2 : 10;
    data = new T[size];
    for (int i = 0; i < this->length; i++)
        if (i < length)
            data[i] = i + 100;
    for (int i = this->length; i < this->size; i++)
        data[i] = -1;
}

template <class T>
Array<T>::Array()
{
    size = 5;
    length = 0;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = -1;
}

int main()
{
    Array<int> arr1;
    arr1.Display();

    Array<float> arr2(4);
    arr2.Display();

    printf("\n%d is the element at the given index\n ", arr2.Get(2));

    arr2.Append(300);
    arr2.Append(900);
    arr2.Display();

    return 0;
}