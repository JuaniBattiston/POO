#include <iostream>

using namespace std;

class Post
{
private:
    int height;
    int section;

public:
    Post(int height, int section)
    {
        this->height = height;
        this->section = section;
    }

    int getHeight()
    {
        return this->height;
    }

    int getSection()
    {
        return this->section;
    }
};

class Person
{
private:
    string name;
    int age;
    int height;

public:
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }

    string getName()
    {
        return this->name;
    }

    int getAge()
    {
        return this->age;
    }

    int getHeight()
    {
        return this->height;
    }
};

template <class T>
void print_height(T obj)
{
    std::cout << obj.getHeight() << std::endl;
}

int main()
{
    Post post = Post(10, 5);
    Person person = Person("Juan", 20, 180);

    print_height(post);
    print_height(person);
    return 0;
}
