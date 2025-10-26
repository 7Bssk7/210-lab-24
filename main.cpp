// COMSC-210 | Lab 24 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

//Constants for array sizes and goat age range 
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat>& trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
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

    //Set to store Goat objects
    set<Goat> t;

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
    cout << "Bye!" << endl;


    return 0;
}

// main_menu() outputs main menu and validates user input
// arguments: none
// returns: integer representing user's choice
int main_menu(){
    int c; // int for user's choice 

    // Outputs main menu and validates the input
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

// add_goat() creates a new Goat with random (names,color and age) and adds it to the set
// arguments: set of Goat objects (by reference), arrays of names and colors
// returns: none
void add_goat(set<Goat>& trip, string n[], string c[]){
    // Creates goat with random name,age and color 
    Goat temp(n[rand() % SZ_NAMES], (rand() % (MAX_AGE+1)),c[rand() % SZ_COLORS]);
    // Outputs what was added to the set
    cout << "You added: " << temp.get_name() << "(" << temp.get_age() << ", " << temp.get_color() << ")" << endl;
    cout << endl;

    // Adds goat to the set
    trip.insert(temp); 

}

// delete_goat() deletes a goat from the set based on user selection
// arguments: set of Goat objects (by reference)
// returns: none
void delete_goat(set<Goat>& trip){
    if(trip.empty()){ // checks if set is empty
        cout << "Sorry, the set is empty." << endl;
        cout << endl;
        return;
    }

    // Asks user to select goat to delete
    int c = select_goat(trip);

    // Advance iterator to selected goat
    auto it = trip.begin();
    advance(it, c-1);
    // Deletes selected goat from the set
    trip.erase(it);

    // Outputs updates set
    cout << "After you have deleted the goat from the set" << endl;
    display_trip(trip);

}

// select_goat() asks user to choose a goat from the set
// arguments: set of Goat objects (by reference)
// returns: integer index of selected goat in the set
int select_goat(set<Goat>& trip){
    int choice; 
    // Outputs current set
    display_trip(trip);
    // Asks user to select the goat they want to delete
    cout << "Which of the goats would you like to remove?" << endl;
    cout << "Choice --> ";
    cin >> choice;
    cout << endl;
    // Validates input
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

// display_trip() outputs all goats in the set
// arguments: set of Goat objects (by value)
// returns: none
void display_trip(set<Goat> trip){
    int count = 1; // counts number of items in the set
    if(trip.empty()){
        cout << "Sorry, the set is empty." << endl;
    }
    else{ // Outputs every goat in the set with index 
        cout << "Here is the set of all goats from the trip:" << endl;
        for(auto g : trip){
            cout << "[" << count << "] " << g.get_name() << "(" << g.get_age() << ", " << g.get_color() << ")" << endl;
            count++;
        }
    }
    cout << endl;
}

