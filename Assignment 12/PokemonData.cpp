#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Class representing a Pokémon entry
class Pokemon {
private:
    string name;
    string type1;
    string type2;
    int total;
    int hp;
    int speed;

public:
    // Constructor
    Pokemon(string name, string type1, string type2, int total, int hp, int speed)
        : name(name), type1(type1), type2(type2), total(total), hp(hp), speed(speed) {}

    // Method for printing out data columns
    void printPokemonData() const {
        cout << "Name: " << name
             << " | Type 1: " << type1
             << " | Type 2: " << type2
             << " | Total Stats: " << total
             << " | HP: " << hp
             << " | Speed: " << speed << endl;
    }
};

// Splits row into columns
vector<string> splitRow(const string& line, char delimiter) {
    vector<string> columns;
    string column;
    stringstream ss(line);
    while (getline(ss, column, delimiter)) {
        columns.push_back(column);
    }
    return columns;
}

int main() {
    ifstream file("Pokemon.csv");
    string line;
    vector<Pokemon> pokedex;

    if (!file.is_open()) {
        cerr << "Error: Could not open Pokemon.csv.\n";
        return 1;
    }

    // Skip header line because we don't want to print out the column names. We only want to print out the data.
    getline(file, line);

    int count = 0;
    while (getline(file, line) && count < 10) {
        vector<string> fields = splitRow(line, ',');
            
        string name = fields[1];
        string type1 = fields[2];
        string type2 = fields[3];
        int total = stoi(fields[4]);
        int hp = stoi(fields[5]);
        int speed = stoi(fields[10]);

        Pokemon p(name, type1, type2, total, hp, speed);
        pokedex.push_back(p);
        count++;
    }

    file.close();

    cout << "First 10 entries from Pokemon.csv:\n";
    for (const Pokemon& p : pokedex) {
        p.printPokemonData();
    }

    return 0;
}
