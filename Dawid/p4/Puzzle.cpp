#include "Puzzle.h"

Puzzle::Puzzle(string init, string ans){

        //answer = List<char>();
        //actual = List<char>();

        for(int i = 0; i < init.length(); i++){
            answer.insert(ans[i]);
            actual.insert(init[i]);
        }
    
}

Puzzle::~Puzzle(){
    ///nicz
}


bool Puzzle::solved(){
    
    return answer.isEqual(actual);
}


void Puzzle::display(){
    cout << endl << "actual state: ";
    actual.showStructure();
    cout << "    "<< "solution: ";
    answer.showStructure();    

}

void Puzzle::swapEnds(){
    actual.gotoEnd();
    char temp = actual.getCursor();
    actual.gotoBeginning();
    char temp2 = actual.getCursor();
    actual.replace(temp);
    actual.gotoEnd();  
    actual.replace(temp2);  
}


void Puzzle::execute_cmd(char cmd){

   
    if(cmd == '<')
        actual.shiftLeft();
    else if(cmd == '>')
        actual.shiftRight();
    else if(cmd == '/')
        swapEnds();
   else if(cmd == 'q')
        system("exit");
    else
        cout << "nie rozpoznano komendy";     

}

void Puzzle::debug(){
    actual.debugNext(100);
    actual.debugPrior(100);


}