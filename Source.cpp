#include "Header.h"

int main() {

	//Main Menu Class
	MainMenu mm;

	//Call Load Input File
	mm.loadFile();

	//Call Backup File
	mm.outFile();

	//Call Main Menu Loop
	mm.mainMenu();

	return 0;
}