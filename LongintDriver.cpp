#include <iostream>
#include "longint.h"

using namespace std;

int main() {

  cout << "*****Testing Constructors for LongInt*****" << endl;

  cout << "Default Constructor" << endl;
  LongInt l;
  cout << "Testing: LongInt l; " << endl;
  cout << "LongInt l: " << l << endl;

  cout << "Constructor w/String Input Parameter" << endl;
  LongInt l2("1234567890987654321");
  cout << "Testing: LongInt l2 = 1234567890987654321;" <<  endl;
  cout << "LongInt l2: " << l2 << endl;

  cout << "Copy Constructor" << endl;
  LongInt l3 = l2;
  cout << "Testing LongInt l3 = l2;" << endl;
  cout << "LongInt l3: " << l3 << endl;

  cout << "l: " << l << endl;
  cout << "l2: " << l2 << endl;
  cout << "l3: " << l3 << endl;

  cout << "" << endl;
  cout << "*****Testing Input/Output Operator for LongInt*****" << endl;
  cout << "In this section, I am testing to make sure that I accept proper inputs and that I output them correctly." << endl;

  LongInt in1, in2, in3, in4;
  cout << "Enter a LongInt that is positive for the first input: ";
  cin >> in1;
  cout << "Enter a LongInt that is negative for the second input: ";
  cin >> in2;
  cout << "Enter a LongInt that has 0's on the front for the third input: ";
  cin >> in3;
  cout << "Enter a LongInt that has non-digit characters for the fourth input: ";
  cin >> in4;

  cout << "First Input: " << in1 << endl;
  cout << "Second Input: " << in2 << endl;
  cout << "Third Input: " << in3 << endl;
  cout << "Fourth Input: " << in4 << endl;

  cout << "" << endl;
  cout << "For this next portion of my driver code, I will be testing my arithmetic operators and my local binary operators against the same few LongInts." << endl;
  cout << "These LongInts are the following: " << endl;
  LongInt a("123456");
  LongInt b("-999999");
  LongInt c("111111");
  LongInt d("-101010");

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;

  cout << "Again, I will use the LongInts a, b, c, and d when testing the arithmetic and binary operators." << endl;
  cout << "" << endl;

  cout << "*****Testing Arithmetic Operators for LongInt*****" << endl;
  cout << "Operator+" << endl;  
  cout << "a + b = " << a+b << endl;
  cout << "b + a = " << b+a << endl;
  cout << "c + d = " << c+d << endl;
  cout << "d + c = " << d+c << endl;
  cout << "" << endl;

  cout << "Operator-" << endl;  
  cout << "a - b = " << a-b << endl;
  cout << "b - a = " << b-a << endl;
  cout << "c - d = " << c-d << endl;
  cout << "d - c = " << d-c << endl;
  cout << "" << endl;

  cout << "*****Testing Binary Comparison Operators for LongInt*****" << endl;
  cout << "Operator<" << endl;
  cout << "(a < b) ? : ";
  if (a<b)
  {
    cout << "a is less than (<) b" << endl;
  }
  else{
    cout << "a is NOT less than (<) b" << endl;
  }
  cout << "" << endl;

  cout << "(c < d) ? : ";
  if (c<d)
  {
    cout << "c is less than (<) d" << endl;
  }
  else{
    cout << "c is NOT less than (<) d" << endl;
  }
  cout << "" << endl;

  cout << "Operator>" << endl;
  cout << "(a > b) ? : ";
  if (a>b)
  {
    cout << "a is greater than (>) b" << endl;
  }
  else{
    cout << "a is NOT greater than (>) b" << endl;
  }
  cout << "" << endl;

  cout << "(c > d) ? : ";
  if (c>d)
  {
    cout << "c is greater than (>) d" << endl;
  }
  else{
    cout << "c is NOT greater than (>) d" << endl;
  }
  cout << "" << endl;

  cout << "Operator==" << endl;
    cout << "(a == b) ? : ";
  if (a==b)
  {
    cout << "a is exactly equal to b" << endl;
  }
  else{
    cout << "a is NOT exactly equal to b" << endl;
  }
  cout << "" << endl;

  cout << "(c == d) ? : ";
  if (c==d)
  {
    cout << "c is exactly equal to d" << endl;
  }
  else{
    cout << "c is NOT exactly equal to d" << endl;
  }
  cout << "" << endl;

  cout << "Operator!=" << endl;
  cout << "(a != b) ? : ";
  if (a!=b)
  {
    cout << "a is NOT equal to b" << endl;
  }
  else{
    cout << "a is exactly equal to b" << endl;
  }
  cout << "" << endl;

  cout << "(c != d) ? : ";
  if (c!=d)
  {
    cout << "c is NOT equal to d" << endl;
  }
  else{
    cout << "c is exactly equal to d" << endl;
  }
  cout << "" << endl;

  cout << "Operator<=" << endl;
  cout << "(a <= b) ? : ";
  if (a<=b)
  {
    cout << "a is less than or equal to (<=) b" << endl;
  }
  else{
    cout << "a is NOT less than or equal to (<=) b" << endl;
  }
  cout << "" << endl;

  cout << "(c <= d) ? : ";
  if (c<=d)
  {
    cout << "c is less than or equal to (<=) d" << endl;
  }
  else{
    cout << "c is NOT less than or equal to (<=) d" << endl;
  }
  cout << "" << endl;

  cout << "Operator>=" << endl;
  cout << "(a >= b) ? : ";
  if (a>=b)
  {
    cout << "a is greater than or equal to (>=) b" << endl;
  }
  else{
    cout << "a is NOT greater than or equal to (>=) b" << endl;
  }
  cout << "" << endl;

  cout << "(c >= d) ? : ";
  if (c>=d)
  {
    cout << "c is greater than or equal to (>=) d" << endl;
  }
  else{
    cout << "c is NOT greater than or equal to (>=) d" << endl;
  }
  cout << "" << endl;

cout << "I have tested general cases for all the functions in the LongInt class." << endl;

cout << "I will now test some edge cases." << endl;
cout << "First I will create the following LongInt variables: " << endl;

LongInt t1("123456789");
LongInt t2("-123456789");
LongInt t3("-0");
LongInt t4("0");
LongInt t5("123456789");

cout << "LongInt t1: " << t1 << endl;
cout << "LongInt t2: " << t2 << endl;
cout << "LongInt t3: " << t3 << " -> This LongInt was initialized with the string '-0', just to show an edge case."  << endl;
cout << "LongInt t4: " << t4 << endl;
cout << "LongInt t5: " << t5 << endl;
cout << "" << endl;

cout << "t1 + t2 = " << t1+t2 << endl;
cout << "t2 + t1 = " << t2+t1 << endl;

cout << "" << endl;
cout << "t1 - t2 = " << t1-t2 << endl;
cout << "t2 - t1 = " << t2-t1 << endl;
cout << "t2 - t2 = " << t2-t2 << endl;


cout << "Testing Edge Caes of Binary Comparison Operators" << endl;
if(t1>t5){
  cout << "Error in > operator for edge case." << endl;
}
else{
  cout << "Correct." << endl;
}

if(t1<t5){
  cout << "Error in < operator for edge case." << endl;
}
else{
  cout << "Correct." << endl;
}
if (t1 == t5){
  cout << "Correct." << endl;
}
else{
  cout << "Error in == operator for edge case." << endl;
}
if (t1 == t1){
  cout << "Correct." << endl;
}
else{
  cout << "Error in == operator for edge case." << endl;
}

return 0;
}