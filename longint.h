#ifndef LONGINT_H
#define LONGINT_H
#include <iostream>
#include <string>
#include "deque.h"

using namespace std; // this is here???

class LongInt {
  friend istream &operator>>(istream &in, LongInt &rhs);
  friend ostream &operator<<(ostream &out, const LongInt &rhs);
 public:
  // Constructors
  LongInt(const string& str); // make this a ref so don't need to include <string> (iostream at least forward declares it), and so a deep copy doesn't happen 
  LongInt(const LongInt &rhs);
  LongInt();

  // Destructor
  ~LongInt();

  // Arithmetic binary operators
  LongInt operator+(const LongInt &rhs) const;
  LongInt operator-(const LongInt &rhs) const;

  // assignment operators
  const LongInt &operator=(const LongInt &rhs);

  // Logical binary operators
  bool operator< (const LongInt & rhs) const;
  bool operator<=(const LongInt & rhs) const;
  bool operator> (const LongInt & rhs) const;
  bool operator>=(const LongInt & rhs) const;
  bool operator==(const LongInt & rhs) const;
  bool operator!=(const LongInt & rhs) const;

 private:
  Deque<char> digits; // Yoni: is the front the most significant digit?
  //Aviv: Yes. The front end is the most signficant and the back would be least significant
  bool negative;
  void remove0s();
};

#endif
