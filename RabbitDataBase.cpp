#include "RabbitDataBase.h"
#include <iostream>
using namespace std;
RabbitDataBase::RabbitDataBase(){
  numRabbits = 0;
  read();
}
void RabbitDataBase::read(){
      ifstream rabbitFile("rabbits.txt");
   numRabbits = 0;
    while(rabbitFile.peek() != EOF && numRabbits < MAX_RABBITS) {
        rabbitArray[numRabbits].readFromFile(rabbitFile);
        numRabbits++;
      }
}

void RabbitDataBase::printRab(ostream &out, bool printIndex){
    for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbitArray[index].isValid) {
            if (printIndex) {
                out << "Index " << index << ": ";
            }
            rabbitArray[index].print(out);
        } 
    }
}

void RabbitDataBase::save(){
   ofstream out("rabbits.txt");
    rabbitArray.printRab(out,false);
}

void RabbitDataBase::remove(){
  int index = 0;
    do {
        index = readInt("Enter an index to remove between 0 and 500: ");
    }
      while (index < 0 || index >= MAX_RABBITS);
    rabbitArray[index].makeInvalid();
}

void RabbitDataBase::add(){
    for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbitArray[index].isValid == false) {
            rabbitArray[index].readFromUser();
        }
    }
    cout << "Too many rabbits! No room for more!" << endl;
}