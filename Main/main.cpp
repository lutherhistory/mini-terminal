#include <iostream>
#include "../Modules/library/prototype.h"

using namespace std;

int main(){
    string cmd;
    bool run = true;

    system("clear");

    while (run){
        terminalPath();
        cout << "> ";
        getline(cin, cmd);

        if (cmd == "exit")
            run = false;

        else
            responseCommand(cmd, run);
    }

    return 0;
}
