#include <iostream>

using namespace std;

#define PROPERTY_ACCESSOR_DEFINE(type, propertyName, repidAtomType) \
  type get ## repidAtomType ## PropertyValue(void) {                \
    cout<< #propertyName <<endl;                                       \
  }

PROPERTY_ACCESSOR_DEFINE(uint64_t, cpu, Uint);

int main(int argc, char const *argv[])
{

  getUintPropertyValue();
  return 0;
}
