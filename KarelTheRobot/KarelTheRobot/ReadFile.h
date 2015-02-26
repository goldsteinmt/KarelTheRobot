#pragma once
#include <string>
#include <fstream>

// AUTHOR: MATTHEW GOLDSTEIN

class ReadFile {
private:
	char **commandArray; // array holding commands
	std::ifstream inputFile; // instream to read file
	const std::string FILENAME = "commands.txt"; // filename of commands text file
	int numCommands; // number of commands for array
public:
	ReadFile(); // constructor
	int getNumLines(); // inputs file and gets number of lines in the file
	char** parseCommandFile(); // parses individual lines and adds commands to the array
};