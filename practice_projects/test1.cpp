#include <iostream>


struct node
{
  int value;
  node* next;

  node(int valueIn): value(valueIn)
  {
    next = NULL;
  }
  
  ~node()
  {
    delete next;
  }

};


int main ()
{

  node node1(20);

  node1.value = 20;

  return 0;
}
