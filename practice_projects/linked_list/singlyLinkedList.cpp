#include <iostream>


template <typename  T>
struct node
{
  T value;
  node* next;
};

template <typename T> 
class linkedList
{
private:
  node<T>*  head;
  node<T>*  tail;

public:
  linkedList()
  {
    head = NULL;
    tail = NULL;
  }
  
  void insert(T valueIn)
  {
    node<T> * temp = new node<T>;
    temp->value = valueIn;
    temp->next = NULL;

    //check if list is empty
    if(head == NULL)
      {
	head = temp; 
	tail = temp;
      }
    else
      {
	tail->next = temp;
	//update tail to last node
	tail = temp;
      }
  }
  
  void deleteList()
  {
    //check if already empty
    if (head == NULL)
      {
	std::cout << "List is already Empty\n";
      }
    else
      {
	while (head != NULL)
	  {
	    node<T>* temp = head;
	    if (head == tail)
	      {
		head = NULL;
		tail = NULL;
		delete temp;
	      }
	    else
	      {
		head = head->next;
		delete temp;	    
	      }
	  }
      }
  }

  void print()
  {
    node<T>* current = head;
    
    if (current == NULL)
      {
	std::cout<< "list is empty!\n";
      }
    else
      {
	while (current != NULL)
	  {
	    std::cout << current->value << " ";;
	    current = current->next;
	  }
	std::cout << "\n";
      }
  }
};



int main ()
{
  
  linkedList<int> list1;
  
  list1.deleteList();
  list1.print();

  list1.insert(12);
  list1.insert(14);
  list1.print();
  


  return 0;
}
