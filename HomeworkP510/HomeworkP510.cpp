
/*
CSCI 182 - Assignment 2
HomeworkP510.cpp
Programming warm-up exercises 1 - 4

Brett Huffman
v1.0 2/2/20
*/

#include <iostream>
#include <string>
using namespace std; // necessary to avoid doing <std::string> for string declarations

// Global string array of all planets
// technically Pluto is not part of the solar system anymore
const string solarSystem[] = { "MERCURY", "VENUS", "EARTH", "MARS", "JUPITER",
    "SATURN", "URANUS", "NEPTUNE", "PLUTO" };
// saving the length of the previous line array 
const int solarSystemLength = 9;

//useful functions
/// <summary>
/// Return the uppercase version of the passed string argument. Only
/// </summary>
/// <param name="lowerString"></param>
/// <returns></returns>
string uppercaseString(string input) {
    
    for (size_t i = 0; i < input.length(); i++) {
        input[i] = toupper(input[i]);
    }

    return input;
}

/// <summary>
/// Search for key position in stringArray. Returns an int between 0 and stringArray.length()
/// if found else return -1.
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
int positionInArray(string key, const string stringArray[], int length) {
    bool found = false;
    int i = 0;

    while (i < length && !found) {
        if (key == stringArray[i]) {
            found = true; // we found it in the array
        }else {
            i++; // else we keep looking until we go through the whole array
        }
    }

    if (found) {
        return i; // we return the index
    }else{
        return -1;
    }
}

// 1. named type with solar system planets names as value
enum planet {MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};

// 2. 
/// <summary>
/// Return a planet enum value associated with passed string planet name. Returns planet EARTH
/// if the passed string isn't a proper planet name.
/// </summary>
/// <param name="planetName"></param>
/// <returns></returns>
planet stringToEnum(string planetName) {
    planet namedPlanet =  MERCURY; // initialise it at the first value
    
    // we check if planetName is in the solar system array and get its position back.
    // we uppercase the name just to be sure to match the form in the array.
    int position = positionInArray(uppercaseString(planetName), solarSystem, solarSystemLength);

    if ( position != -1) { // we found it in the array so we return the corresponding
        return static_cast<planet>(namedPlanet + position);
    }
    else {// else we return EARTH
        return EARTH;
    }
}

//3.
/// <summary>
/// Return the string form of a planet name that corresponds to the passed enum planet.
/// Return "error" if the passed enum planet is not valid.
/// </summary>
/// <param name="aPlanet"></param>
/// <returns></returns>
string enumToString(planet somePlanet) {
    planet namedPlanet = MERCURY;
    bool found = false;
    int i = 0;

    while(i < solarSystemLength && !found){
        if (namedPlanet == somePlanet) { // is the planet we are looking for
            found = true;
        }else {
            namedPlanet = static_cast<planet>(namedPlanet + 1); // check next planet
            i++; // keep count
        }
    }

    if (found) {
        return solarSystem[i];
    }else {
        return "error";
    }
}

int main()
{
    /*//used for testing purpose
    string testPlanet = "PlutO";
    cout << enumToString(stringToEnum(testPlanet)) << endl;
    cout << enumToString(GULLIVER) << endl; // doesn't accept non planet values anyway
    */

    // go through all possible values of enumerators for planet type and print the string by calling enumToSpring
    // on enum identifier
    for (planet solarSystemPlanet = MERCURY; solarSystemPlanet <= PLUTO;
        solarSystemPlanet = static_cast<planet>(solarSystemPlanet + 1)) {
        cout << enumToString(solarSystemPlanet) << endl;
    }
}