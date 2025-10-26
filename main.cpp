#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    list<Goat> t;

    int choice = main_menu();
    while((choice != 4)){
        if(choice == 1){
            add_goat(t, names, colors);
        }
        else if(choice == 2){

        }
        else{

        }

    }


    return 0;
}

int main_menu(){
    int c;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat"<< endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice -->";
    cin >> c;
    while((c < 1) || (c > 4)){
        cout << "Ivalid choice, please select again" << endl;
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat"<< endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice -->";
        cin >> c;
    }

    return c;
}

void add_goat(list<Goat>& trip, string n[], string c[]){
    Goat temp(n[rand() % SZ_NAMES-1], (rand() % MAX_AGE),c[rand() % SZ_COLORS]);
    trip.push_back(temp);

}


