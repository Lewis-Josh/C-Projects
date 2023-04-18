# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <string>

using namespace std;

//Main Menu Class
class MainMenu {
	
	//Initialize Private Variables
	private:
		
		//Initialize Empty Item String
		string item = "";
		string input = "";

		//Initialize Character for Formatting and Histogram
		char star = '*';

		//Initialize Empty Value String
		int num = 0;

		//Input File Stream
		ifstream myFile;

		//Create Backup File
		ofstream productFile;

		//Create Product Map and Iterator
		map<string, int> productMap;
		map<string, int>::iterator it;

		//Create MultiMap for Sorting 
		multimap<int, string, greater<int>> multiMap;

	public:

		//Load Input File
		void loadFile() {
			//Open Input File
			myFile.open("TESTFILE.txt", ios::in);

			//Check if Input File is Open
			if (myFile.is_open()) {
				while (getline(myFile, item)) {
					productMap.insert(make_pair(item, num));
					++productMap[item];
				}

				//Close Input File
				myFile.close();
			}
			else {
				cout << "Unable to Open File.\n";
				cout << endl;
			}
		}

		//Create Backup File
		void outFile() {

			for (auto m : productMap) {
				multiMap.insert(make_pair(m.second, m.first));
			}
			
			productFile.open("frequency.dat", ios::out);
			if (productFile.is_open()) {
				for (map<int, string>::iterator it = multiMap.begin(); it != multiMap.end(); ++it) {
					productFile << (*it).second << " : " << (*it).first << endl;
					productFile << '\n';
				}
			}

		}

		//Menu Option to search individual products
		void menuOne() {

			cout << "Please enter the product you wish to search.\n";
			cin >> input;
			it = productMap.find(input);

			//Search Product Map and return item and count if found
			if (it != productMap.end()) {
				cout << (*it).first << " : " << (*it).second << endl;
			}
			else {
				cout << "Product not Found!\n";
				cout << endl;
			}
		}

		//Menu Option to return All products and frequencies
		void menuTwo() {

			for (auto m : productMap) {
				multiMap.insert(make_pair(m.second, m.first));
			}

			//Output Sorted Multimap
			for (map<int, string>::iterator it = multiMap.begin(); it != multiMap.end(); ++it) {
				cout << (*it).second << " : " << (*it).first << endl;
				cout << '\n';
			}



		}

		//Menu Option to return All products and Histogram
		void menuThree() {
			
			for (auto m : productMap) {
				multiMap.insert(make_pair(m.second, m.first));
			}

			//Output Sorted Multimap
			for (map<int, string>::iterator it = multiMap.begin(); it != multiMap.end(); ++it) {
				cout << (*it).second << "   " << string((*it).first, star) << endl;
				cout << '\n';
			}
		}

		//Main Menu Loop until exit
		void mainMenu() {

			//Initialize Choice character
			char choice = ' ';

			//Initialize integer for menu formatting
			int divider = 30;

			//Main Menu Loop
			while (true) {

				cout << string(divider, star) << '\n';
				cout << '\n';
				cout << "Enter " << "1" << " to search for product.\n";
				cout << '\n';
				cout << string(divider, star) << '\n';
				cout << '\n';
				cout << "Enter " << "2" << " to display all items and frequency of purchase.\n";
				cout << '\n';
				cout << string(divider, star) << '\n';
				cout << '\n';
				cout << "Enter " << "3" << " to display items and histogram.\n";
				cout << '\n';
				cout << string(divider, star) << '\n';
				cout << '\n';
				cout << "Enter " << "4" << " to exit the program.\n";
				cout << '\n';
				cin >> choice;

				//Input Validation(s)
				if (choice == '1') {
					menuOne();
				}

				else if (choice == '2') {
					menuTwo();
				}

				else if (choice == '3') {

					menuThree();
				}

				else if (choice == '4') {

					cout << "Exiting Program...";
					break;
				}

				else {
					cout << "Invalid Input!\n";
					cout << endl;
				}
			}
		}
	
};


// TESTING CLASS
class TEST {

public:

	//Creating testing map with input variables
	void mapCreate() {
		string item = "MAP TEST";
		int num = 0;

		map<string, int> testList;
		testList.insert(make_pair(item, num));
		for (map<string, int>::iterator it = testList.begin(); it != testList.end(); ++it) {
			cout << (*it).first << " : " << (*it).second << endl;
		}
	}

	//Testing Reading of Text File
	void readFileTest() {
	
		//Input File Stream
		ifstream testFile;

		//Open Input File
		testFile.open("TESTFILE.txt", ios::in);

		//Initialize empty String Variable
		string testString = "";

		//Check if Input File is Open
		if (testFile.is_open()) {

			//While Loop to read Input File
			while (getline(testFile, testString)) {
				cout << testString << endl;
			}
		}
		else {
			cout << "Unable to Open File";
		}

		//Close Input File
		testFile.close();
	}

	void productMapTest() {

		//Initialize empty String Variable
		string item = "";

		//Initialize empty Integer Variable
		int num = 0;

		//Create empty Map
		map<string, int> productMap;
		

		//Input File Stream
		ifstream testFile;

		//Open Input File
		testFile.open("TESTFILE.txt", ios::in);


		//Check if Input File is Open
		if (testFile.is_open()) {

			//While the file is open, read the file, insert the product name into map and count duplicates
			while (getline(testFile, item)) {
					productMap.insert(make_pair(item, num));
					++productMap[item];
			}

			//Close Input File
			testFile.close();
		}
		//Unable to open file message
		else {
			cout << "Unable to Open File";
		}

		//Create MultiMap for Sorting 
		multimap<int, string, greater<int>> multiMap;

		for (auto m : productMap) {
			multiMap.insert(make_pair(m.second, m.first));
		}

		//Output Sorted Multimap
		for (map<int, string>::iterator it = multiMap.begin(); it != multiMap.end(); ++it) {
			cout << (*it).second << " : " << (*it).first << endl;
		}
	}

};