#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		// TO BE COMPLETED
		noOfBriths = 0;
		noOfBabiesWithLowWeight = 0;
		noOfUniqueName = 0;

		MAX_NO_OF_UNIQUE_BABIES = 1000;
		uniqueBabyName = new string[MAX_NO_OF_UNIQUE_BABIES];
		uniqueBabyNameCount = new int[MAX_NO_OF_UNIQUE_BABIES];
		for (int i = 0; i < MAX_NO_OF_UNIQUE_BABIES; i++) {
			uniqueBabyName[i] = "";
			uniqueBabyNameCount[i] = 0;
		}
	}

	// destructor
	~MedicalRecord() {
		// TO BE COMPLETED
	}

	// Load information from a text file with the given filename..
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				//cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file.
	string mostPopularName() {
		int max = uniqueBabyNameCount[0];
		int max_index = 0;
		for (int i = 1; i < noOfUniqueName; i++) {
			if (uniqueBabyNameCount[i] > max) {
				max = uniqueBabyNameCount[i];
				max_index = i;
			}

		}
		return uniqueBabyName[max_index]; // TO BE COMPLETED
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return noOfBriths; // TO BE COMPLETED
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		return noOfBabiesWithLowWeight; // TO BE COMPLETED
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		for (int i = 0; i < noOfUniqueName; i++) {
			if (uniqueBabyName[i].compare(s) == 0) {
				return uniqueBabyNameCount[i];
			}
		}
		return -1; // TO BE COMPLETED
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
		// TO BE COMPLETED
		bool name_present = false;
		noOfBriths++;
		if (b.getWeight() < 2500) {
			noOfBabiesWithLowWeight++;
		}
		for (int i = 0; i < noOfUniqueName; i++) {
			if (uniqueBabyName[i].compare(b.getName()) == 0) {				
				uniqueBabyNameCount[i]++;
				name_present = true;
				break;
			}
		}
		//----------------------
		if(!name_present) {
			uniqueBabyName[noOfUniqueName] = b.getName();
			uniqueBabyNameCount[noOfUniqueName]++;
			noOfUniqueName++;
		}
		//--------------
	}
	/*void print() {
		cout << "--------------------------------------" << endl;
		for (int i = 0; i < noOfUniqueName; i++) {
			cout << uniqueBabyName[i] <<" --- " << uniqueBabyNameCount[i] << endl;
		}
		cout << "--------------------------------------" << endl;
	}*/

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions
	int MAX_NO_OF_UNIQUE_BABIES;  // maximum number of unique babies
	string* uniqueBabyName;   // number of unique baby names
	int* uniqueBabyNameCount;  // count of each unique baby names 

	int noOfUniqueName; // total number of unique baby names
	int noOfBabiesWithLowWeight; // no of babies with low weight 
	int noOfBriths;  // tatal no of births 
	
};
