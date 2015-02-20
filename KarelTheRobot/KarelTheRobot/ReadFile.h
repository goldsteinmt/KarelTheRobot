#pragma once
#include <string>
#include <fstream>

class ReadFile {
private:
	std::string currentLine;
	char* commandArray;
	std::ifstream inputFile;
	const std::string FILENAME = "commands.txt";
	int numCommands;
public:
	ReadFile();
	int getNumLines();
	char** parseCommandFile();
};