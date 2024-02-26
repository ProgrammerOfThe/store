#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "macro.h"
#include "string.h"


struct Player{
  int money = STARTING_MONEY;
  std::string itemList[PLAYER_PRODUCT_SIZE];

  private:
    std::string saveFileName = "PSF.txt";

  bool checkSaveFile(){
    
    std::ifstream file;
    file.open(saveFileName);

    if(file){
      exit(FILE_EXIST);
    }else{
      exit(FILE_NOT_EXIST);
    }

    return false;
  }
  int itemAssign(std::string input){

    checkSaveFile();
    for (int i = 0; i < PLAYER_PRODUCT_SIZE; i++){
      if (itemList[i].empty()){
        itemList[i] = input;
        std::cout << "Assigned item: " << itemList[i] << std::endl;
         // Exit the function after assigning the item

        return EXIT_SUCCESS;
      }
    }
    std::cout << "Could not assign data. The array is full.\n";
  }

  int purchase(std::string item, int itemCost){
    if (itemCost > money){
      return ERROR_PURCHASING;
    }else{
      itemAssign(item);
    }
    
    return 0;
  }

  void saveData(std::string filename, std::string input, std::string dataDesc){
    std::ofstream file(filename);

    file << dataDesc << " " <<  input << '\n';
    file.close();
  }
};
#endif
