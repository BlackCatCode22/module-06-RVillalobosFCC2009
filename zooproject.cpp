#include <iostream>
//#include <animalclass.h>
#include <ofstream
#include <string.h>
using namespace std;

// genAnimalName.cpp
// dH 9/28/22
// demo file for midterm program Fall '22 CIT-66 C++ Programming
//
// Use this file to help you write the genAnimalName() function in
// your midterm program.
//
// Common Programming Errors:
//   Miscounting number of lines in the file (open the file by hand, if possible, and check!)
//   Miscalculating array element length. the sizeof() method returns the number of bytes, not the number of elements.
//
// References:
//   https://www.w3schools.com/cpp/cpp_files.asp
//   https://www.w3schools.com/cpp/cpp_arrays_size.asp
//

// text files are in the directory: C:/cStuff/midProgFiles/


int main(){
  ///Animal 
  string myStr = "";
  string fileName = "";
  int myPause = 0;

  // Open a file for reading.
  
  ifstream myAnimalFile("C:/Users/letty/Desktop/College courses/66 +/module 4 test/animalNames.txt");
  fileName = ("C:/Users/letty/Desktop/College courses/66 +/module 4 test/animalNames.txt");
  ofstream zooreport("C:/Users/letty/Desktop/College courses/66 +/module 4 test/zooreport.txt");
  // Read the file one line at a time.
  while (getline(myAnimalFile, myStr) && myPause < 2) {
    cout << "\n  " << myStr;
    cout << " \n Enter 1 for next line, 2 to stop: ";
    cin >> myPause;
  }
  cout << "\n\n *********** end of while loop reading file a line at a time **********\n\n";

  // return to top of
  myAnimalFile.clear();
  myAnimalFile.seekg(0);

  // Prove that clear() and seekg(0) worked.
  getline(myAnimalFile, myStr);
  cout << myStr;

  // Get each line of the file into a 1D array.
  // Count the number of line in the file
  // Read the file one line at a time.
  int numOfLines = 1;
  while (getline(myAnimalFile, myStr)) {
    numOfLines++;
  }
  cout << "\n  There are " << numOfLines << " lines in the file!";

  // Create an array to hold the lines of the file.
  string myAnimalFileArray[numOfLines];

  // and...read each one of the file's lines into your new array.
  // return to top of file
  myAnimalFile.clear();
  myAnimalFile.seekg(0);
  // Read the file one line at a time and get each line into the array.
  // Now that we know how many lines are in the file, we can use a for loop!
  for (int i=0; i<numOfLines; i++) {
    getline(myAnimalFile, myAnimalFileArray[i]);
  }

  // let's see how our animal names look in an array...
 int lenOfArray = numOfLines;

  // divide by 24 to get the number of elements
 
  cout << "\n********* The Animal Name File Array *********\n";
  for (int i=0; i<lenOfArray; i++){
    cout << endl << myAnimalFileArray[i];
  }

  cout << "\n\n\n";

  // create two variables needed for array searching
  string speciesName = "";
  string arrayElementFirstWord = "";

  // Find the Hyena Names
  // Check for 'Hyena Names' in first line.
  speciesName = "Hyena";
  // find the first blank space in the array element
  int firstSpace = myAnimalFileArray[0].find(" ");
  cout << "\n the first space is at ..." << firstSpace;
  arrayElementFirstWord = myAnimalFileArray[0].substr(0,5);

  cout << "\n arrayElementFirstWord = " << arrayElementFirstWord;
    const char* Hyena = "Hyena";
  int compResult = strcmp(Hyena, arrayElementFirstWord.c_str());
  if ( compResult == 0) {
    cout << "\n strings are equal!";
  }
 
  // and... return to top again!
  myAnimalFile.clear();
  myAnimalFile.seekg(0);

  // Close the file.
  myAnimalFile.close();
// Open a file for reading.
  ifstream arrivingfile("C:/Users/letty/Desktop/College courses/66 +/module 4 test/arrivingAnimals.txt");
  fileName = ("C:/Users/letty/Desktop/College courses/66 +/module 4 test/arrivingAnimals.txt");

  // Read the file one line at a time.
  while (getline(arrivingfile, myStr) && myPause < 2) {
    cout << "\n  " << myStr;
    cout << " \n Enter 1 for next line, 2 to stop: ";
    cin >> myPause;
  }
  cout << "\n\n *********** end of while loop reading file a line at a time **********\n\n";
// Function to generate an animal's birthday
string genBirthDay(const string& birthDate, const string& birthSeason = "") {
    // If birth season is provided, generate birthday based on it
    if (!birthSeason.empty()) {
        // Mapping of birth seasons to months (assumed)
        map<string, string> seasonToMonth = {
            {"Spring", "03"},
            {"Summer", "06"},
            {"Fall", "09"},
            {"Winter", "12"}
        };

        string month = seasonToMonth[birthSeason];
        return birthDate.substr(0, 4) + "-" + month + "-01"; // Assuming day as 01 for simplicity
    } else {
        // If birth season is not provided, just use the birth date as is
        return birthDate;
    }
}

// Function to make a unique identifier for each animal
string genUniqueID(const string& species, int seqNumber) {
    static map<string, int> speciesCount;

    string prefix = species.substr(0, 2);
    speciesCount[prefix]++; // Increment count for this species prefix

    // Generate the unique ID using the species prefix and sequence number
    return prefix + setfill('0') + setw(2) + to_string(speciesCount[prefix]);
}

// Function to organize animals into their respective habitats
map<string, vector<string>> organizeAnimalsByHabitat(const vector<string>& animalNames) {
    map<string, vector<string>> habitatMap;
    for (const auto& name : animalNames) {
        string habitat = name.substr(0, name.find(" "));
        habitatMap[habitat].push_back(name);
    }
    return habitatMap;
}

// Function to compile a detailed report
void compileReport(const map<string, vector<string>>& habitatMap) {
    ofstream report("zooPopulation.txt");
    if (!report.is_open()) {
        cerr << "Error opening report file!" << endl;
        return;
    }

    report << "Zoo Population Report" << endl;
    report << "----------------------" << endl;

    for (const auto& habitat : habitatMap) {
        report << "Habitat: " << habitat.first << endl;
        report << "----------------------" << endl;
        for (const auto& animal : habitat.second) {
            // Split the animal name to get birthdate and species
            string birthDate = animal.substr(animal.find("(") + 1, 10);
            string species = animal.substr(0, animal.find(" "));

            report << "Name: " << animal << endl;
            report << "ID: " << genUniqueID(species, 1) << endl; // Assuming sequential numbers start from 1
            report << "Birthday: " << genBirthDay(birthDate) << endl;
            // Additional attributes can be added here
            report << endl;
        }
        report << endl;
    }

    report.close();
}

int main() {
    string myStr;
    vector<string> animalNames;

    // Open the animal names file
    ifstream myAnimalFile("C:/Users/letty/Desktop/College courses/66 +/module 4 test/animalNames.txt");
    if (!myAnimalFile.is_open) {
        cerr << "open animal names file" << endl;
        return 1;
    }

    // Read animal names from the file
    while (getline(myAnimalFile, myStr)) {
        animalNames.push_back(myStr);
    }
    myAnimalFile.close();

    // Organize animals by habitat
    map<string, vector<string>> habitatMap = organizeAnimalsByHabitat(animalNames);

    // Compile detailed report
    compileReport(habitatMap);

    cout << "Zoo population report has been generated: zooPopulation.txt" << endl;

    return 0;


}
