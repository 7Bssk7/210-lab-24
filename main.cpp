// COMSC-210 | Lab 23 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

//Constants for array sizes and goat age range 
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat>& trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0)); // seed random number generator 
    bool again = 1;

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

    //List to store Goat objects
    list<Goat> t;

    //Main menu loop
    int choice = main_menu();
    while((again)){
        if(choice == 1){ // checks if choice is 1
            add_goat(t, names, colors);
        }
        else if(choice == 2){ // checks if choice is 2
            delete_goat(t);
        }
        else if(choice == 3){ // checks if choice is 3
            display_trip(t);
        }
        else{ // checks if choice is 4
            again = 0;
        }
        if(again){ 
            choice = main_menu(); // Outputs menu again if user didn't choose 4
        }

    }


    return 0;
}

// main_menu() outputs main menu and validates user input
// arguments: none
// returns: integer representing user's choice
int main_menu(){
    int c;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat"<< endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> c;
    cout << endl;
    while((c < 1) || (c > 4)){
        cout << "Invalid choice, please select again" << endl;
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat"<< endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice --> ";
        cin >> c;
        cout << endl;
    }

    return c;
}

// add_goat() creates a new Goat with random (names,color and age) and adds it to the list
// arguments: list of Goat objects (by reference), arrays of names and colors
// returns: none
void add_goat(list<Goat>& trip, string n[], string c[]){
    Goat temp(n[rand() % SZ_NAMES], (rand() % (MAX_AGE+1)),c[rand() % SZ_COLORS]);
    cout << "You added: " << temp.get_name() << "(" << temp.get_age() << ", " << temp.get_color() << ")" << endl;
    cout << endl;
    trip.push_back(temp);

}

void delete_goat(list<Goat>& trip){
    if(trip.empty()){
        cout << "Sorry, the list is empty." << endl;
        cout << endl;
        return;
    }
    int c = select_goat(trip);

    auto it = trip.begin();
    advance(it, c-1);
    trip.erase(it);

    cout << "After you have deleted the goat from the list" << endl;
    display_trip(trip);

}

int select_goat(list<Goat>& trip){
    int choice;
    display_trip(trip);
    cout << "Which of the goats would you like to remove?" << endl;
    cout << "Choice --> ";
    cin >> choice;
    cout << endl;
    while((choice < 1) || (choice > trip.size())){
        cout << "Invalid choice, please select again" << endl;
        display_trip(trip);
        cout << "Which of the goats would you like to remove?" << endl;
        cout << "Choice --> ";
        cin >> choice;
        cout << endl;
    }

    return choice;
}

void display_trip(list<Goat> trip){
    int count = 1;
    if(trip.empty()){
        cout << "Sorry, the list is empty." << endl;
    }
    else{
        cout << "Here is the list of all goats from the trip:" << endl;
        for(auto g : trip){
            cout << "[" << count << "] " << g.get_name() << "(" << g.get_age() << ", " << g.get_color() << ")" << endl;
            count++;
        }
    }
    cout << endl;
}

