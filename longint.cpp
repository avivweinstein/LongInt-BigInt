/*
Name: Aviv Weinstein
Class: CSS 501A
Professor: Wooyoung Kim
Assignment Name: Program #4
Date of last edit: 12/08/20

Purpose:
The purpose of this file is to implement the functions required by the program 4 assignment for CSS 501A. This file contains the implementation for all the functions that are prototyped in the longint.h file. I used the functions impelmented in the deque.cpp/deque.h file to implement the LongInt class

Assumptions:
There are assumptions made for cerain functions in this file. Specifically:
=> 
*/

#include "longint.h"
#include <math.h>
#include <iomanip>
using namespace std;

//Overloaded input operator.
//Takes an input string from the user and creates a LongInt with the string
istream &operator>>(istream &in, LongInt &rhs){
  string input_str;
  cin >> input_str;

  cout << input_str << endl;

  LongInt tmp (input_str);

  rhs = tmp;

  return in;
}

ostream &operator<<(ostream &out, const LongInt &rhs){
  //I want to create a copy of the LongInt being passed in.
  //I will then use that copy to print out the Deque object of the LongInt being passed in (the Deque object is called digits)
  //I will print out the Deque objects in a similar way to how it is done in the deque_test.cpp file
  //Like this:
  //  while (!deque1.isEmpty())
  //    cout << deque1.removeFront() << endl;

  LongInt tmp = rhs; //make a copy.
  LongInt control("-0");
  tmp.remove0s();

  if(tmp == control){
    cout << "0";
    return out;
  }

//If the LongInt is negative, print out a - sign in front of the number
  if(tmp.negative){
    cout << "-";
  }

  while (!tmp.digits.isEmpty()){
    cout << tmp.digits.removeFront();
  }
  
  return out;
}

//Constructors
//Here I want to go through the entire string and add all the values to the string in the correct order in the string.
LongInt::LongInt(const string& str){
  int i = 0;

  if(str[i]=='-')
  {
    this->negative = true;
    i++; //This is so I dont include the '-' as part of my Deque.
  }
  else{
    this->negative = false;
  }

  //Now I loop through my input string and add every digit to my LongInt
  while (str[i]){
    if(isdigit(str[i])){ //this if statement filters out non-digits from an input string.
      digits.addBack(str[i]);
      i++;
    }
    else{
      i++;
   }
  }
}

//Copy constructor.
//Makes use of the assignment operator that is implemented further down in this .cpp file.
LongInt::LongInt(const LongInt &rhs){
  *this = rhs;
}

//Constructor with no parameters
//A LongInt with no paremters is initialized to '0'
LongInt::LongInt(){
  digits.addBack('0');
  negative = false;
}

// Destructor
LongInt::~LongInt(){
  digits.clear();
}

// Arithmetic binary operators
LongInt LongInt::operator+(const LongInt &rhs) const{

//Making copies of left hand side and right hand side arguments so I can manipulate them.
//Also made a LongInt called sum to store the output of this function.
  LongInt LHS = *this;
  LongInt RHS = rhs;
  LongInt sum;

  int LHS_size = LHS.digits.size();
  int RHS_size = RHS.digits.size();

  int longer;

//In this while loop I am padding the shorter number with extra 0's in the front to make addition easier.
  while (LHS_size != RHS_size){
    if(LHS_size < RHS_size){
      LHS.digits.addFront('0');
      LHS_size = LHS.digits.size();
    }
    else if (LHS_size > RHS_size){
      RHS.digits.addFront('0');
      RHS_size = RHS.digits.size();
    }
  }

//These next three if blocks determine which of the two LongInts is longer. I use this later on
  if (LHS_size < RHS_size){
    longer = RHS_size;
  }
  else if(LHS_size > RHS_size){
    longer = LHS_size;
  }
  else if(LHS_size == RHS_size){
    longer = LHS_size;
  }

  int temp[longer]; //builds an array of the result of the + operation
  int temp_remove; // Stores the temporary values of the addition of the current digits.
  int carry = 0; //To track carry/overflow in addition

  //this is the case where we are adding two negative numbers or two positive numbers
  if ((LHS.negative && RHS.negative) || (!(LHS.negative) && !(RHS.negative))){

    for (int i = 0; i < longer; i++){
      temp_remove = LHS.digits.removeBack() - '0' + RHS.digits.removeBack()-'0' + carry;
      temp[i] = temp_remove % 10;
      carry = temp_remove / 10;
      sum.digits.addFront(temp[i] + '0'); //Here is where I actually build the answer in the sum LongInt object
    }

    sum.digits.removeBack(); //I NEED THIS 0 REMOVED. NOT A TYPO. This 0 is a reminant from when I created the sum LongInt object. When a LongInt is created with no parameter, it is initialized to 0;

    //Here I am dealing with the carry bit once the addition is completed.
    if(carry==1){
      sum.digits.addFront('1');
    }

    //Here I am checking what the sign of the result will be. Negative + neg is always negative.
    //Positive + positive is always positive.
    if(LHS.negative && RHS.negative){
      sum.negative = true;
    }
    else if (!LHS.negative && !RHS.negative){
      sum.negative = false;
    }
  }
    //this is the case where we are adding a positive and a negative or a negative and a positive
    else if((LHS.negative && !RHS.negative)){
      LHS.negative = false;
      sum = RHS - LHS;
    }
    else if((!LHS.negative) && RHS.negative){
      RHS.negative = false;
      sum = LHS - RHS;
    }
  return sum;
}

LongInt LongInt::operator-(const LongInt &rhs) const{
  LongInt sub;
  LongInt LHS = *this;
  LongInt RHS = rhs;

  LongInt top;
  LongInt bottom;

  int top_dig = 0;
  int bot_dig = 0;

  int LHS_size = LHS.digits.size();
  int RHS_size = RHS.digits.size();

  int longer;
  int borrow = 0;

//In this while loop I am padding the shorter number with extra 0's in the front to make addition easier.
  while (LHS_size != RHS_size){
    if(LHS_size < RHS_size){
      LHS.digits.addFront('0');
      LHS_size = LHS.digits.size();
    }
    else if (LHS_size > RHS_size){
      RHS.digits.addFront('0');
      RHS_size = RHS.digits.size();
    }
  }

  if (LHS_size < RHS_size){
    longer = RHS_size;
  }
  else if(LHS_size > RHS_size){
    longer = LHS_size;
  }
  else if(LHS_size == RHS_size){
    longer = LHS_size;
  }

  int temp[longer];

  //LHS is positive and RHS is negative
  //sub = LHS + RHS
  if (!LHS.negative && RHS.negative){
    RHS.negative = false;
    sub = LHS + RHS;
  }

  //Negative LHS and positive RHS//Sub = -(LHS + RHS)
  else if(LHS.negative && !RHS.negative){
    LHS.negative = false;
    sub = LHS + RHS;
    sub.negative = true;
  }

  //positive LHS and positive RHS
  //sub = LHS - RHS
  else if (!(LHS.negative) && !(RHS.negative)){

    if (LHS == RHS){
      return sub;
    }
    else if(LHS<RHS){
      top = RHS;
      bottom = LHS;
      sub.negative = true;
    }
    else if(RHS<LHS){
      top = LHS;
      bottom = RHS;
      sub.negative = false;
    }

    for(int i = 0; i<longer; i++){
      top_dig = (top.digits.removeBack() - '0');
      bot_dig = (bottom.digits.removeBack() - '0');
      
      if(borrow == 1){
        top_dig = top_dig-1;
        borrow = 0;
      }

      if (top_dig - bot_dig < 0){
        top_dig = top_dig + 10;
        borrow = 1;
        temp[i] = top_dig - bot_dig;
      }
      else{
        temp[i] = top_dig - bot_dig;
        borrow = 0;
      }
      sub.digits.addFront(temp[i] + '0');
    }
    sub.digits.removeBack(); //Need to get rid of a 0! Not a typo!
  }

  //negative LHS and negative RHS
  // sub = RHS - LHS
  else if(LHS.negative && RHS.negative){
    if(LHS == RHS){
      return sub;
    }
    else if(RHS < LHS){
      sub.negative = false;
      top = RHS;
      bottom = LHS;
    }
    else if(LHS < RHS){
      sub.negative = true;
      top = LHS;
      bottom = RHS;
    }
    
    for(int i = 0; i<longer; i++){
      top_dig = (top.digits.removeBack() - '0');
      bot_dig = (bottom.digits.removeBack() - '0');
      
      if(borrow == 1){
        top_dig = top_dig-1;
        borrow = 0;
      }

      if (top_dig - bot_dig < 0){
        top_dig = top_dig + 10;
        borrow = 1;
        temp[i] = top_dig - bot_dig;
      }
      else{
        temp[i] = top_dig - bot_dig;
        borrow = 0;
      }
      sub.digits.addFront(temp[i] + '0');
    }
    sub.digits.removeBack(); //Need to get rid of a 0!
  }
  return sub;
}

// assignment operators
const LongInt& LongInt::operator=(const LongInt &rhs){

  this->negative = rhs.negative; //Set the new LongInt sign to the RHS sign.
  this->digits = rhs.digits; //Here I should be setting the deque of the LHS to the deque of the RHS

  return *this;
}


void LongInt::remove0s(){

  int i = 0; //this variable will tell us how many leading 0's we have on a LongInt

  LongInt tmp = *this; //I want to make a copy of the current object.
  int tmp_size = tmp.digits.size();

  if(tmp_size == 1){
    //the only time we enter this is statement is when we have a single value in our Deque.
    //Meaning, if our deque is '0', we enter this, as we dont want to remove this 0.
    return; //leave this function
  }

  //Here we are incrementing i every time we have a leading 0
  while (tmp.digits.getFront() == '0')
  {
    tmp.digits.removeFront();
    i++;
  }

  //Now that we know the count of leading 0's, we remove them from the actual LongInt object.
  for(int j=0; j < i; j++){
    this->digits.removeFront();
  }
}

// Logical binary operators
bool LongInt::operator< (const LongInt & rhs) const{
  LongInt LHS = *this;
  LongInt RHS = rhs;

  int LHS_size = LHS.digits.size();
  int RHS_size = RHS.digits.size();

  int LHS_arr[LHS_size];
  int i = 0;
  int j = 0;
  int RHS_arr[RHS_size];

  //I am building up this array in reverse order. The LSB is located at index 0 of these arrays.
  while(!LHS.digits.isEmpty()){
    LHS_arr[i] = LHS.digits.removeFront() - '0';
    i++;
  }

  while(!RHS.digits.isEmpty()){
    RHS_arr[j] = RHS.digits.removeFront() - '0';
    j++;
  }

  //comparing two negative numbers
  if(LHS.negative && RHS.negative){
    if(LHS_size > RHS_size){
      return true;
    }
    else if(LHS_size < RHS_size){
      return false;
    }
    else if (LHS_size == RHS_size){
      int q = 0;
      while (LHS_arr[q] == RHS_arr[q]){
        q++;
      }
      if(LHS_arr[q] > RHS_arr[q]){
        return true;
      }
      else{
        return false;
      }
    }

  }
  //comparing two positive numbers
  else if(!(LHS.negative) && !(RHS.negative)){
    if(LHS_size < RHS_size){
      return true;
    }
    else if(LHS_size > RHS_size){
      return false;
    }
    else if (LHS_size == RHS_size){
      int q = 0;
      while (LHS_arr[q] == RHS_arr[q]){
        q++;
      }
      if(LHS_arr[q] < RHS_arr[q]){
        return true;
      }
      else{
        return false;
      }
    }
  }
  //comparing a postive number on the LHS and a negative number on the RHS
  else if(!(LHS.negative) && RHS.negative){
    return false;
  }
  else if(LHS.negative && !(RHS.negative)){
    return true;
  }
  return false;
}


bool LongInt::operator>(const LongInt & rhs) const{
  LongInt LHS = *this;
  LongInt RHS = rhs;

  int LHS_size = LHS.digits.size();
  int RHS_size = RHS.digits.size();

  int LHS_arr[LHS_size];
  int i = 0;
  int j = 0;
  int RHS_arr[RHS_size];

  if (LHS == RHS){
    return false;
  }

  //I am building up this array in reverse order. The LSB is located at index 0 of these arrays.
  while(!LHS.digits.isEmpty()){
    LHS_arr[i] = LHS.digits.removeFront() - '0';
    i++;
  }

  while(!RHS.digits.isEmpty()){
    RHS_arr[j] = RHS.digits.removeFront() - '0';
    j++;
  }

  //comparing two negative numbers
  if(LHS.negative && RHS.negative){
    if(LHS_size < RHS_size){
      return true;
    }
    else if(LHS_size > RHS_size){
      return false;
    }
    else if (LHS_size == RHS_size){
      int q = 0;
      while (LHS_arr[q] == RHS_arr[q]){
        q++;
      }
      if(LHS_arr[q] < RHS_arr[q]){
        return true;
      }
      else{
        return false;
      }
    }

  }
  //comparing two positive numbers
  else if(!(LHS.negative) && !(RHS.negative)){
    if(LHS_size > RHS_size){
      return true;
    }
    else if(LHS_size < RHS_size){
      return false;
    }
    else if (LHS_size == RHS_size){
      int q = 0;
      while (LHS_arr[q] == RHS_arr[q]){
        q++;
      }
      if(LHS_arr[q] < RHS_arr[q]){
        return false;
      }
      else{
        return true;
      }
    }
  }
  //comparing a postive number on the LHS and a negative number on the RHS
  else if(!(LHS.negative) && RHS.negative){
    return true;
  }
  else if(LHS.negative && !(RHS.negative)){
    return false;
  }
  return false;
}

bool LongInt::operator==(const LongInt & rhs) const{
  LongInt LHS = *this;
  LongInt RHS = rhs;

  int LHS_size = LHS.digits.size();
  int RHS_size = RHS.digits.size();

  int LHS_arr[LHS_size];
  int RHS_arr[RHS_size];
  int i = 0;
  int j = 0;

  bool sizes = false; //Variable to check that sizes are the same
  bool signs = false; //Variable to check that signs are the same
  bool values = false; //Variable to monitor if all values are the same.

  //I am building up this array in regular order. The MSB is located at index 0 of these arrays.

  if(LHS_size == RHS_size){
    sizes = true;
    //cout << "Lengths of LongInts are the same!" << endl;
  }
  else if(LHS_size != RHS_size){
    //cout << "Lengths of LongInts are NOT the same!" << endl;
    return false;
  }

  if(LHS.negative == RHS.negative){
    signs = true;
    //cout << "Pos/Neg Signs of the LongInts are the same!" << endl;
  }
  else if(LHS.negative != RHS.negative){
    //cout << "Pos/Neg Signs of the LongInts are NOT the same!" << endl;
    return false;
  }

  for(int e=0; e < LHS_size; e++){
    if(LHS.digits.removeFront() == RHS.digits.removeFront()){
      values = true;
    }
    else{
      //cout << "Values in the LongInts are different! NOT EQUAL" << endl;
      return false;
    }
  }

//If the size, negative sign, and values and the same, then the LongInts are the same.
  if(sizes && signs && values){
    return true;
  }
  //Otherwise, the LongInts are not ==
  else{
    return false;
  }
}


//I am re-using the > and == functions to create the >= function.
bool LongInt::operator>=(const LongInt & rhs) const{
  if ( (*this > rhs) || (*this == rhs)){
    return true;
  }
  else{
    return false;
  }
}

//I am re-using the < and == functions to create the <= function.
bool LongInt::operator<=(const LongInt & rhs) const{
  if ( (*this < rhs) || (*this == rhs)){
    return true;
  }
  else{
    return false;
  }
}

//I am reusing the == function to create the != function.
//The != function is simply the inverse of the == function.
bool LongInt::operator!=(const LongInt & rhs) const{
  if(*this == rhs){
    return false;
  }
  else{
    return true;
  }
}

