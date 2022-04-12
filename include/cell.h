#include <string>
#include <map>
#include <random>

using std::map;
using std::string;
using std::rand;

class Cell{
    private:
        int probToReproduce;
        int probToDie;
        string id;
        int numOfChilds;

    public:
        void init(int p1, int p2, int c, string i);
        void live(map<string, Cell>& cells);
        void die(map<string, Cell>& cells);
        void reproduce(map<string, Cell>& cells);
        void mutate();
};


void Cell::init(int p1, int p2, int c, string i){
    probToReproduce = p1;
    probToDie = p2;
    numOfChilds = c;
    id = i;
}


void Cell::live(map<string, Cell>& cells){
    int dead = rand() % 101, rep = rand() % 101, mut = rand() % 101;

    if(mut <= 6){ //Permanent 6% probability
        mutate();
    }

    if(dead <= probToDie){
        
        die(cells);
    }else if(rep <= probToReproduce){
        
        reproduce(cells);
    }
}


void Cell::die(map<string, Cell>& cells){
    cells.erase(id);
}


void Cell::reproduce(map<string, Cell>& cells){
    cells.erase(id);

    Cell c1; c1.init(probToReproduce, probToDie, numOfChilds, id + '0');
    Cell c2; c2.init(probToReproduce, probToDie, numOfChilds, id + '1');

    cells[id + '0'] = c1; cells[id + '1'] = c2;
}

void Cell::mutate(){
    int n = rand() % 2; //Binary

    if(n == 1){ //Prioritize living
        if(probToDie > 1){
            probToDie -= 1;
        }
    }else{ //Prioritize reproducing
        if(probToReproduce < 100){
            probToReproduce += 1;
        }
    }
}