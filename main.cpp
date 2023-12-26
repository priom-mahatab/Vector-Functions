#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function Prototypes
void display_menu ();
char get_choice ();
void print_list (const vector <int> &v);
void display_list (const vector <int> &v);
void add_num (vector <int> &v);
double calc_mean (double total, const vector <int> &v);
void mean (const vector <int> &v);
void smallest_num (const vector <int> &v);
void largest_num (const vector <int> &v);


// Function Definitions
void display_menu () {
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

char get_choice () {
    char choice {};
    cin >> choice;
    return toupper (choice);
}

void print_list (vector <int> &v) {
        if (v.size() == 0)
            cout << "The list is empty" << endl;
        else{
            display_list (v);
        }
}

void display_list (const vector <int> &v) {
    cout << "[ ";
    for (auto num: v)
        cout << num << " ";
    cout << "]" << endl;
}

void add_num (vector <int> &v) {
        int new_entry {};
        cout << "Enter a new number to add: ";
        cin >> new_entry;
        v.push_back(new_entry);
        cout << new_entry << " added" << endl;
}

double calc_mean (double total, const vector <int> &v) {
    cout << fixed << setprecision(2);
    return total / v.size();
}

void mean (const vector <int> &v) {
    double total {};
    for (auto c: v)
        total += c;
    if (v.size() == 0)
        cout << "Cannot calculate mean" << endl;
    else
        cout << "The mean is: " << calc_mean (total, v) << endl;
}

void smallest_num (const vector <int> &v) {
    if (v.size() == 0)
        cout << "Cannot display the smallest element, list is empty" << endl;
    else {
        int smallest = v.at(0);
        for (auto num: v)
            if (num < smallest)
                smallest = num;
        cout << "The smallest element is: " << smallest << endl;
    }
}

void largest_num (const vector <int> &v) {
    if (v.size() == 0)
        cout << "Cannot display the largest element, list is empty" << endl;
    else {
        int largest = v.at(0);
        for (auto num: v)
            if (num > largest)
                largest = num;
        cout << "The largest element is: " << largest << endl;
    }
}

int main () {
    vector <int> nums {1, 2, 3, 4, 5};
    char choice {};
    
    do{
        display_menu ();
        choice = get_choice();
        
        if (choice == 'P')
            print_list(nums);
        
        else if (choice == 'A')
            add_num(nums);
            
        else if (choice == 'M')
            mean(nums);
            
        else if (choice == 'S')
            smallest_num(nums); 
            
        else if (choice == 'L')
            largest_num(nums);
        
        else if (choice == 'Q')
            cout << "Program terminated!" << endl;
        
        else 
            cout << "Invalid choice. Please choose a valid option" << endl;
    
    } while (choice != 'Q');
    
    cout << endl;
    return 0;
}

