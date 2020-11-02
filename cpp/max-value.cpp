#include <limits.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

  std::cout<<"UINT_MAX: " << UINT_MAX << ", Size: " << sizeof(UINT_MAX) << " Bytes"<<std::endl;
  std::cout<<"ULONG_MAX: " << ULONG_MAX << ", Size: " << sizeof(ULONG_MAX) << " Bytes"<<std::endl;
  std::cout<<"ULLONG_MAX: " << ULLONG_MAX << ", Size: " << sizeof(ULLONG_MAX) << " Bytes" <<std::endl;
  uint64_t i1 = 1;
  std::cout<<"uint64_t: " << i1 << ", Size: " << sizeof(i1) << " Bytes" <<std::endl;

  return 0;
}
