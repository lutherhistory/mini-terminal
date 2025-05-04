#include <iostream>
#include <fstream>
#include "../library/prototype.h"

using namespace std;

void writeToFile(const std::string file_path, const std::string& text, bool& run){
    ofstream File(file_path, ios::app);

    if (!File.is_open())
        run = false;
    else
        File << text << endl;

    File.close();
}

void readFromFile(const string file_path, bool run){
    ifstream File(file_path);
    string text;

    if (!File.is_open()){
        File.close();
        run = false;
    }
    else
        while (getline(File, text))
            cout << "\t" << text << endl;

    File.close();
}

void responseCommand(const std::string& cmd, bool& run){
    writeToFile("/home/luther/Programming/Program/mini-terminal/back-end/history.txt", cmd, run);

    if (isSingleCommand(cmd)){
        if (cmd == "clear")
            system("clear");

        else if (cmd == "history")
            readFromFile("/home/luther/Programming/Program/mini-terminal/back-end/history.txt", run);

        else if (cmd == "help")
            cout << "Available Commands: clear, help, exit" << endl;

        else
            cout << "Invalid Command!" << endl;
    }
}

string terminalPath(){
    return "~";
}

bool isSingleCommand(const string& cmd){
    std::string text;

    for (int i=0; i < cmd.length(); i++){
        if (cmd[i] != ' ')
            text += cmd[i];
        else
            return false;
    }

    return true;
}
