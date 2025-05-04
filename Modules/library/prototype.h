#include <iostream>
#include <fstream>

// Response to user write Command
void responseCommand(const std::string&, bool&);

// Path
std::string terminalPath();

// Check is that command a single
bool isSingleCommand(const std::string&);

// Write or Update to file
void writeToFile(const std::string, const std::string&);

// Read and output text from file
void readFromFile(const std::string);
