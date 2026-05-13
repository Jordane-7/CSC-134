#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Exercise 1 & 2: Weapon Class
class Weapon {
private:
    string name;
    int damage;
    int durability;

public:
    Weapon(string n = "Fists", int d = 5, int dur = 100) 
        : name(n), damage(d), durability(dur) {}

    void use() {
        if (durability > 0) {
            durability -= 10; // Lose 10 durability per use
            if (durability < 0) durability = 0;
        }
    }

    // A weapon with 0 durability deals only 1 damage (broken)
    int getDamage() const {
        return (durability > 0) ? damage : 1;
    }

    string getName() const { return name; }
    int getDurability() const { return durability; }
};

// Character Class with Encapsulation
class Character {
private:
    string name;
    int hp;
    int maxHp;
    Weapon equippedWeapon; // Composition: Character HAS A Weapon

public:
    Character(string n, int health, Weapon w) 
        : name(n), maxHp(health), hp(health), equippedWeapon(w) {}

    void takeDamage(int amount) {
        hp = max(0, hp - amount);
        cout << name << " takes " << amount << " damage!" << endl;
    }

    void attack(Character &enemy) {
        int dmg = equippedWeapon.getDamage();
        cout << name << " attacks with " << equippedWeapon.getName() << "!" << endl;
        enemy.takeDamage(dmg);
        equippedWeapon.use(); // Weapon loses durability after attack
    }

    void displayStatus() const {
        cout << "--- " << name << " ---" << endl;
        cout << "HP: " << hp << "/" << maxHp << endl;
        cout << "Weapon: " << equippedWeapon.getName() 
             << " (Durability: " << equippedWeapon.getDurability() << "%)" << endl;
        cout << "------------------" << endl;
    }
};

int main() {
    // Create a Weapon object
    Weapon sword("Iron Sword", 20, 30);

    // Create Character objects
    Character hero("Aldric", 100, sword);
    Character goblin("Goblin", 30, Weapon("Rusty Knife", 5, 100));

    // Simulate a brief battle
    hero.displayStatus();
    hero.attack(goblin);
    goblin.displayStatus();

    return 0;
}