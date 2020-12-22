/*  DiceProbability.cpp : Computes the probability for dice possibilites 
    Date: 21/12/2020
    Author: Bruno c. Messias
*/

#include <iostream> //Library to output and input
#include <cstdlib>  //Standart C library 
#include <ctime>    //Time C library   

using namespace std; //namespace for standart library
//encapsulation are good to work in any device

const int sides = 6; //Declare an int constant
inline int r_sides() { return (rand() % sides + 1); }; //declare a a not fuction called(macro function but better), without need to call - stack (better run time)

int main()
{
    const int n_dice = 2; //2 dice thrown const are good to checks in the code
    int d1, d2; //declare int variables
    srand(clock()); //intitialize seed generator(monte carlo simulation)

    cout << "\nEnter number of trials: "; //Compare with printf()[\n -> new line \t -> tab \a -> hardware sound] [<< -> overloaded{iostream}]
    int trials;
    cin >> trials; //compare to scanf

    int* outcomes = new int[n_dice * sides + 1]; //new -> memory management(heap(pilha)) -> allocatede in time of execution)
    //in c was malloc() and free() -> new and delete

    for (int j = 0; j < trials; ++j) //same for loop in c program -> j is a local loop variable
    {
        outcomes[(d1 = r_sides()) + (d2 = r_sides())]++;
        cout << "probability\n";
    }

    cout << "\n-----------------------\n\n";

    for (int j = 2; j < n_dice * sides + 1; ++j) 
    {
        cout << "j = " << j << " p = " << static_cast<double>(outcomes[j]) / trials //stream can shown string and variable numbers
        //static_cast -> safety cast(in c was (double)[expression]) in static_cast only convert in a secure condition
                << endl; //new line in iostream
    }
    
    return 0;
}

