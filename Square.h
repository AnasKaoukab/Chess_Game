#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Square{
private:
  vector <int> pos;
public:
  Square(string);
  Square(int x, int y);
  vector<int> to_pos(string str);
  vector <int> get_posi();
};
