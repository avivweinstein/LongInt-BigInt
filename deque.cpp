
#include "deque.h"
#include <stddef.h> // if you used the NULL keyword, you
                    // wouldn't have to include this. But IDK if // your instructor will compile with c++11 or
                    // newer.


template <class Object>
Deque<Object>::Deque() {                          // the constructor
  front = back = NULL;
}

template <class Object>
Deque<Object>::Deque(const Deque<Object> &rhs) {         // the copy constructor
  front = back = NULL;
  *this = rhs;
}

template <class Object>
Deque<Object>::~Deque() {                         // the destructor
  clear();
}

template <class Object>
bool Deque<Object>::isEmpty() const {             // check if a deque is empty
  return front == NULL;
}

template <class Object>
int Deque<Object>::size() const {                 // retrieves # deque nodes
  int i = 0;
  for ( DequeNode *ptr = front; ptr != NULL; ptr = ptr->next ) // traverse que
    ++i;

  return i;
}

template <class Object>
const Object &Deque<Object>::getFront() const {   // retrieve the front node
  if (isEmpty())
    throw "empty queue";
  return front->item;
}

template <class Object>
const Object &Deque<Object>::getBack() const {    // retrieve the tail node
  if (isEmpty())
    throw "empty queue";
  return back->item;
}

template <class Object>
void Deque<Object>::clear() {          // clean up all entries.
  while (!isEmpty())                 // dequeue till the queue gets empty.
    removeFront();
}
// add a new node to front
template <class Object>
void Deque<Object>::addFront(const Object &obj){

  DequeNode *new_node = new DequeNode;

  new_node->prev = NULL;
  new_node->next = front;
  new_node->item = obj;

//Checking for the edge case where we have no nodes
  if (front == NULL){  //If we have no nodes, both front and back get set to the only node.
    back = new_node;
    front = new_node;
  }
  else{ //Else, everything else is handled by this
    front->prev = new_node;
    front = new_node;
  }
}

// add a new node to tail
template <class Object>
void Deque<Object>::addBack(const Object &obj){

  DequeNode *new_node = new DequeNode;
  
  new_node->prev = back;
  new_node->next = NULL;
  new_node->item = obj;
  
//Checking for the edge case where we have no nodes
  if (back==NULL){ //If we have no nodes, both front and back get set to the only node.
    front = new_node;
    back = new_node;
  }
  else{ //Else, everything else is handled by this
    back->next = new_node;
    back = new_node;
  }
}

template <class Object>
Object Deque<Object>::removeFront(){  //remove the front node

  DequeNode *pos = front; //create a pointer to keep track of node to be deleted

  //Need to find a way to access the item being help at the location of front.
  Object removedItem = pos->item;

  if(front == back){ //Case for when there is only a single node left in the Queue.
    front = NULL;
    back = NULL;
  }
  else{ //All other cases should fall into this else statement
    front->next->prev = NULL;
    //front->next = NULL;
    front = front->next;
  }

  delete pos;

  return removedItem;
}

template <class Object>
Object Deque<Object>::removeBack(){   // remove the tail node

  DequeNode *pos = back; //create a pointer to keep track of node to be deleted

  //Need to find a way to access the item being help at the location of front.
  Object removedItem = pos->item;

  if(front==back){
    front = NULL;
    back = NULL;
  }
  else{
    back->prev->next = NULL;
    back = back->prev;
  }

  delete pos;
  return removedItem;
}

template <class Object>
const Deque<Object> &Deque<Object>::operator=(const Deque &rhs) { // assign
  if (this != &rhs) { // avoid self assignment
    clear();
    for (DequeNode *rptr = rhs.front; rptr != NULL; rptr = rptr->next)
      addBack(rptr->item);
  }
  return *this;
}


