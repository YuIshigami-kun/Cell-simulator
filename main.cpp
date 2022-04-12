#include <map>
#include <string>
#include <time.h>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "include/cell.h"

using namespace std;

int main(){
    map<string, Cell> cells;
    srand(time(NULL));
    
    for(short i = 0; i < 10; i++){
        Cell c; c.init(50, 50, 2, to_string(i));
        cells[to_string(i)] = c;
    }

    cout << "Ready, press enter to start!" << endl;

    string pressStart;
    getline(cin, pressStart);

    vector<string> ids = {};
    while(true){
        system("cls");
        ids.clear();

        for(auto it = cells.begin(); it != cells.end(); it++){
            ids.push_back(it->first);
        }

        for(int i = 0; i < ids.size(); i++){
            cells[ids[i]].live(cells); //If I go this in the previous loop it caused memory errors
        }

        cout << "Number of cells: " << cells.size() << endl;
        Sleep(1000);
    }

    return 0;
}
