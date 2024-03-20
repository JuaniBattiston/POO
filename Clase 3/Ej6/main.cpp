#include <iostream>

using namespace std;

class Phone
{
private:
    float *height = 0;
    float *width = 0;
    float *price = 0;
    string *brand = nullptr;

public:
    Phone(float height, float width, float price, string brand)
    {
        this->height = new float(height);
        this->width = new float(width);
        this->price = new float(price);
        this->brand = new string(brand);
    }

    ~Phone()
    {
        delete height;
        delete width;
        delete price;
        delete brand;
    }

    float setHeight(float height)
    {
        *this->height = height;
    }

    float setWidth(float width)
    {
        *this->width = width;
    }

    float setPrice(float price)
    {
        *this->price = price;
    }

    string setBrand(string brand)
    {
        *this->brand = brand;
    }

    float getHeight()
    {
        return *height;
    }

    float getWidth()
    {
        return *width;
    }

    float getPrice()
    {
        return *price;
    }

    string getBrand()
    {
        return *brand;
    }
};

int main()
{
    Phone phone1(15.5, 7.5, 1000, "Samsung");
    cout << "Height: " << phone1.getHeight() << endl;
    cout << "Width: " << phone1.getWidth() << endl;
    Phone phone2(15.5, 7.5, 1000, "Iphone");
    cout << "Price: " << phone2.getPrice() << endl;
    cout << "Brand: " << phone2.getBrand() << endl;
    return 0;
}
