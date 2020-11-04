
//#define BOOST_MPL_LIMIT_SET_SIZE 20 //< Default is `20`, which is too small for extending the `FieldSet`.
//Ref: 
//     [1]. http://boost.2283326.n4.nabble.com/BOOST-MPL-LIMIT-SET-SIZE-td2585091.html
//     [2]. https://www.boost.org/doc/libs/1_53_0/libs/mpl/doc/refmanual/limit-set-size.html
#include <boost/mpl/set.hpp>

#include <iostream>
typedef uint64_t A1;
typedef uint64_t A2;
typedef uint64_t A3;
typedef uint64_t A4;
typedef uint64_t A5;
typedef uint64_t A6;
typedef uint64_t A7;
typedef uint64_t A8;
typedef uint64_t A9;
typedef uint64_t A10;
typedef uint64_t A11;
typedef uint64_t A12;
typedef uint64_t A13;
typedef uint64_t A14;
typedef uint64_t A15;
typedef uint64_t A16;
typedef uint64_t A17;
typedef uint64_t A18;
typedef uint64_t A19;
typedef uint64_t A20;
typedef uint64_t A21;
typedef uint64_t A22;
typedef boost::mpl::set<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15,
  A16, A17, A18, A19, A20> Set0; //Default size: 20

// Insert element without limitation
typedef boost::mpl::insert<Set0, A21>::type Set1;
typedef boost::mpl::insert<Set1, A22>::type Set;

using namespace std;
int main(int argc, char const *argv[])
{
  return 0;
}
