#include <iostream>
#include <string>
using namespace std;

// Базовый класс "Животное"
class Animal {
protected:
    bool life = true;
    string name;
    int age;
    int satiety;

    bool check_satiety() {
        if (satiety < 10) life = false;
        return life;
    }

    
        
public:
    Animal& operator++(){
        age++;
        return *this;
    }
    Animal(int c = 0) : age(rand() % 11), satiety(c) {
        cout << "Call your pet: ";
        cin >> name;
    }

    virtual void Speak() = 0; 

    string GetName() const { return name; }
    int GetSatiety() const { return satiety > 0 ? satiety : 0; }
    int GetAge() const { return age; }
    bool GetLifeStatus() { return check_satiety() && life; }

    void Eat_food() {
        if (life) {
            satiety += 5;
            age++;
            life = check_satiety();
        }
    }
};


class Dog : public Animal {
public:
    Dog(int c) : Animal(c) {}

    void Speak() override {
        if (life) {
            satiety -= 5;
            if (check_satiety())
                cout << name << " speak: Woof!" << endl;
        }
        else
            cout << name << "I'm die..." << endl;

    }
};


class Cat : public Animal {
public:
    Cat(int c) : Animal(c) {}

    void Speak() override {
        if (life) {
            satiety -= 5;
            if (check_satiety())
                cout << name << " speak: Meow!" << endl;
        }
        else
            cout << name << "I'm die..." << endl;
    }
};

int main() {
    
    cout << "Choose your pet: 1 - Dog, 2 - Cat" << endl;
    int choice;
    cin >> choice;

    Animal* my_animal;

    if (choice == 1) {
        my_animal = new Dog(10);
    }
    else if (choice == 2) {
        my_animal = new Cat(10);
    }
    else {
        cout << "Wrong choice." << endl;
        return 1;
    }

    int numActions;
    cout << "Number of repetitions of actions: ";
    cin >> numActions;

    for (int i = 0; i < numActions && my_animal->GetLifeStatus() == true; ++i) {
        if (my_animal->GetSatiety() <= 10) cout << "Hint: your pet wants to eat, feed it" << endl;

        cout << "Choose action: 1 - Eat, 2 - Speak" << endl;
        int action;
        cin >> action;

        switch (action) {
        case 1:
            my_animal->Eat_food();
            break;
        case 2:
            my_animal->Speak();
            break;

        }
    }

    // Показатели животного
    cout << "Name: " << my_animal->GetName() << endl;
    cout << "Age: " << my_animal->GetAge() << " years" << endl;
    cout << "Satiety: " << my_animal->GetSatiety() << "%" << endl;
    cout << "Life status: " << (my_animal->GetLifeStatus() ? "life" : "die") << endl;



    return 0;
}