#include <string>
#include <vector>
#include <iostream>
#include "Square.h"
using namespace std;



Square::Square(int x , int y){
  pos.push_back(x);
  pos.push_back(y);
}


Square::Square(string str){
  pos = to_pos(str);
}


vector<int> Square:: get_posi(){
  return pos;
}


vector<int> Square:: to_pos(string str){
    for (int i = 0; i < 2; i++) {
        pos.push_back(0);
    }
    switch(str[0]){
        case 'a':
            pos[1]=0;
            break;
        case 'b':
            pos[1]=1;
            break;
        case 'c':
            pos[1]=2;
            break;
        case 'd':
            pos[1]=3;
            break;
        case 'e':
            pos[1]=4;
            break;
        case 'f':
            pos[1]=5;
            break;
        case 'g':
            pos[1]=6;
            break;
        case 'h':
            pos[1]=7;
            break;
        default:
            break;
    }

    int s=atoi(&str[1]);
    switch(s) {
      case 1:
        pos[0]=0;
        break;
      case 2:
        pos[0]=1;
        break;
      case 3:
          pos[0]=2;
          break;
      case 4:
          pos[0]=3;
          break;
      case 5:
          pos[0]=4;
          break;
          case 6:
            pos[0]=5;
            break;
          case 7:
            pos[0]=6;
            break;
          case 8:
              pos[0]=7;
              break;
          default:
              break;
      }
  return pos;
}
