#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Phone
{
private:
    float height = 0;
    float width = 0;
    float price = 0;
    string brand;

public:
    Phone(float height, float width, float price, string brand)
    {
        this->height = height;
        this->width = width;
        this->price = price;
        this->brand = brand;
    }

    float getHeight()
    {
        return height;
    }

    float getWidth()
    {
        return width;
    }

    float getPrice()
    {
        return price;
    }

    string getBrand()
    {
        return brand;
    }
};

int main()
{
    vector<Phone> phones;
    phones.push_back(Phone(15.5, 7.5, 700, "Samsung"));
    phones.push_back(Phone(15.5, 7.5, 1000, "Iphone"));
    phones.push_back(Phone(15.5, 7.5, 500, "Xiomi"));

    sort(phones.begin(), phones.end(), [](Phone a, Phone b)
         { return a.getPrice() < b.getPrice(); });

    cout << "Telefonos ordenados por precio: " << endl;
    for (int i = 0; i < phones.size(); i++)
    {
        cout << phones[i].getBrand() << " " << phones[i].getPrice() << endl;
    }
    return 0;
}
