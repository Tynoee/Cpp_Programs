#include <iostream>
#include <string>

// Exercises

class Ship {
private:
    int id;
    std::string name;
    float speed;
    int maxCrew;
    float capacity;
    size_t crew;


public: 
    Ship() : id(-1), speed(0.0), maxCrew(0), capacity(0.0) {}

    Ship(int id, std::string name, float speed, int maxCrew, float capacity): id(id), name(name), speed(speed), maxCrew(maxCrew), capacity(capacity) {}
    
    Ship(int id, float speed, int maxCrew) :  Ship(id, "", speed, maxCrew, 0) {}

    int getId() const {
        return id;
    }
    
    std::string getName() const {
        return name;
    }

    float getSpeed() const {
        return speed;
    }

    int getMaxCrew() const {
        return maxCrew;
    }

    float getCapacity() const {
        return capacity;
    }

    size_t getCrew() const {
        return crew;
    }

    void setName(const std::string& newName) {
        name = newName;
    }


    Ship& operator+=(const int addCrew) {
        crew += static_cast<size_t>(addCrew);
        return *this;
    }

    Ship& operator-=(const int subtractCrew) {
        if (crew >= static_cast<size_t>(subtractCrew)) {
            crew -= static_cast<size_t>(subtractCrew);
        } else {
            crew = 0;
        }
        return *this;
    }


};

class Cargo {
private:
    std::string name;
    float amount;
    float basePrice;

public:
    Cargo(const std::string name, float amount, float basePrice)
        : name(name), amount(amount), basePrice(basePrice) {}

    std::string getName() const {
        return name;
    }

    float getAmount() const {
        return amount;
    }

    float getBasePrice() const {
        return basePrice;
    } 

    Cargo& operator+=(const size_t addAmount) {
        amount += static_cast<float>(addAmount);
        return *this;
    }

    Cargo& operator-=(const size_t subtractAmount) {
        if (amount >= static_cast<float>(subtractAmount)) {
            amount -= static_cast<float>(subtractAmount);
        } else {
            amount = 0.0;
        }
        return *this;
    }
};

int main() {
    Ship ship1(1, "Banshee", 20.0, 50, 100.0);
    Cargo cargo1("Gatsby", 500.0, 10.0);

    ship1 += 1;
    std::cout << "Name of Ship is " <<ship1.getName() << std::endl;
    std::cout << "Current crew count on the ship: " << ship1.getCrew() << std::endl;


};