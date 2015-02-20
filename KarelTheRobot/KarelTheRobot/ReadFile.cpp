#include "ReadFile.h"
#include <sstream>
//#include <ctype.h>
#include <algorithm>

ReadFile::ReadFile(){
	numCommands = getNumLines(); // get the number of lines from the file
	commandArray = new char*[numCommands]; // initialize array of <numCommands> arrays
	for (int i = 0; i < numCommands; i++){ // for every array in commandArray...
		commandArray[i] = new char[5];	   // ...create an array of 5 characters
	}
}

int ReadFile::getNumLines(){
	inputFile.open(FILENAME); // open file
	int numLines; // holds number of lines
	std::string tempHolder; // allows getline to be used
	while (std::getline(inputFile, tempHolder)){ // while there are more lines
		numLines++; // increment numlines
	}

	inputFile.close(); // close file

	return numLines; 
}

char** ReadFile::parseCommandFile(){
	std::string currentLine; // buffer for reading lines and parsing
	std::string words[5]; // array of words for current line to be parsed
	std::string currentWord; // current word being read
	inputFile.open(FILENAME); // open input file
	while (std::getline(inputFile, currentLine)){
		std::stringstream sstream(currentLine);  // allows to parse string into array of words
		int i = 0;
		while (sstream.good() && i < 5){
			sstream >> words[i];
		}

		currentWord = std::tolower(words[0]);
	}
	
}