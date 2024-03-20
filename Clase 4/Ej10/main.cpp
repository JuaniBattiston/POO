#include <iostream>
#include <vector>

using namespace std;

class Player
{
private:
    int speed;
    int strength;
    string name;

public:
    Player(int speed, int strength, string name)
    {
        this->speed = speed;
        this->strength = strength;
        this->name = name;
    }

    ~Player() {}

    int getSpeed()
    {
        return speed;
    }

    int getStrength()
    {
        return strength;
    }

    string getName()
    {
        return name;
    }

    void setSpeed(int speed)
    {
        this->speed = speed;
    }

    void setStrength(int strength)
    {
        this->strength = strength;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void printInfo()
    {
        cout << "Jugador:  " << name << " Velocidad: " << speed << " Fuerza: " << strength << endl;
    }
};

int main()
{
    vector<Player> players;
    players.push_back(Player(1, 2, "Jugador 1"));
    players.push_back(Player(3, 4, "Jugador 2"));
    players.push_back(Player(5, 6, "Jugador 3"));
    players.push_back(Player(7, 8, "Jugador 4"));
    players.push_back(Player(9, 10, "Jugador 5"));
    players.push_back(Player(11, 12, "Jugador 6"));
    players.push_back(Player(13, 14, "Jugador 7"));
    players.push_back(Player(15, 16, "Jugador 8"));
    players.push_back(Player(17, 18, "Jugador 9"));
    players.push_back(Player(19, 20, "Jugador 10"));

    for (int i = 0; i < players.size(); i++)
    {
        players[i].printInfo();
    }

    return 0;
}
