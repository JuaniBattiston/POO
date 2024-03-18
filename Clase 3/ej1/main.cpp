#include <iostream>
#include <random>

using namespace std;

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(2, 20);

    std::cout << distr(gen) << ' ';
}
