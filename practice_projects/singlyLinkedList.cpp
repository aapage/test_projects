#include <iostream>


template <typename T >
struct node
{
  T value;
  
  node* next;

  //ctor
  node(T valueIn, node* nextNode): value(valueIn), next(nextNode){;}

};


template <typename T>
class singleList
{
private:
  node<T>* head;
  
public:
  //ctor
  singleList(T value)
  {
    head = new node<T>(value, NULL);
  }
  
  void addValue(T value)
  {
    node<T>* currentNode = head;

    if (head != NULL)
      {
	//scan to end of list
	while (currentNode->next != NULL)
	  {
	    currentNode = currentNode->next;
	  }
	node<T> * newNodePtr = new node<T>(value, NULL);
	currentNode->next = newNodePtr;
	currentNode = NULL;

      }
    else
      {
	//make new head
	head = new node<T>(value, NULL);
      }
  }


  
  bool isValueInList(T target)
  {
    node<T>* currentNode = head;
    while (currentNode != NULL)
      {
	if (currentNode->value == target)
	  {return true;}
	else
	  {currentNode = currentNode->next;}
      }
    return false;

  }
  
  void print()
  {
    node<T>* currentNode = head;
    while (currentNode != NULL)
      {
	std::cout << currentNode->value << "  ";
	currentNode = currentNode->next;
      }
    std::cout << std::endl;
    currentNode = NULL;

  }

  void reverseList()
  {
    node<T>* currentNode = head;
    node<T>* tmpNode = NULL;
    node<T>* previousNode = NULL;
    while (currentNode != NULL)
      {	
	tmpNode = currentNode->next;
	currentNode->next = previousNode;
	previousNode = currentNode;

	if (tmpNode == NULL)
	  {
	  //set new head
	  head = currentNode;
	  break;
	  }
	else currentNode = tmpNode;
      } 

  }

  bool popFront()
  {
    if (head == NULL) {return false;}
    if (head->next != NULL)
      {
	node<T>* tmpNode = head->next;
	delete head;
	head = tmpNode;

	return true;
      }
    else
      {
	//only 1 node left
	delete head;
	head = NULL;
	return true;
      }
  }


};









int main()
{
  
  singleList<int> list1(12);
  list1.addValue(13);
  list1.addValue(14);
  list1.addValue(44);
  list1.addValue(12309438);
  list1.print();
  list1.reverseList();
  list1.print();
  while (list1.popFront())
    {
      list1.print();
    }
  list1.popFront();
  list1.print();
  list1.addValue(20);
  list1.print();
  //bool find = list1.isValueInList(15);
  
  //std::cout << find << std::endl;

  return 0;
}
