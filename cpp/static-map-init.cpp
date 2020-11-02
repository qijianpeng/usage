/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * @copyright Copyright (c) 2020
 */

#include <iostream>
#include <map>
typedef std::map<std::string, std::string> StringMap;

using namespace std;
class Parameters{
public:
  Parameters(){};
  ~Parameters(){};
  static StringMap TYPE_MAPPING;
    
private:
  static StringMap _TYPE_MAPPING(){
    StringMap tmpMap ;
    tmpMap["key"] = "value";
    return tmpMap;
  }
};
StringMap Parameters::TYPE_MAPPING =  Parameters::_TYPE_MAPPING();

int main(int argc, char const *argv[])
{
  cout<< Parameters::TYPE_MAPPING["key"] << endl;
  return 0;
}
