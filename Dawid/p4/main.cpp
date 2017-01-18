#include "List.h"
#include "Puzzle.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
int main(){
  srand(time(0));
  string ans = "whatdoesthefox";
  string init = "whattoesdhefox";
  long int i = 0;
  unsigned long long int i2 = 0;
  Puzzle p = Puzzle(init, ans);
  int random_command;
    p.execute_cmd('<');
    p.execute_cmd('<');
    p.execute_cmd('<');

while(!p.solved()){

random_command = rand()%3;
  //p.display();

switch (random_command){
  case 0:
    p.execute_cmd('<');
    break;
  case 1:
    p.execute_cmd('/');
    break;

}

if (i > 999999999){
  i2++;
  srand(time(0));
  
  cout << i2 << "    " << time(0) << endl;
  i = 0;
}
i++;
}/////////while

  p.display();
  cout << i<< endl << endl  << i2 << "end";

  return 0;
}