#include <iostream>



template <typename T>
struct node
{
  T value;
  node* parent;
  node* next;
};

template<typename T>
class doubleLinkedList
{
private:
  node<T>* head;
  node<T>* tail;
  
public:
  doubleLinkedList()
  {
    head = NULL;
    tail = NULL;
  }
  
  void push_back(T valueIn)
  {
    //check if list is empty
    if (head == NULL)
      {
	node<T>* temp = new node<T>;
	temp->value = valueIn;
	temp->parent = NULL;
	temp->next = NULL;
	head = temp;
	tail = temp;
      }
    
    else
      {
	node<T>* temp = new node<T>;
        temp->value = valueIn;
        temp->parent = tail;
        temp->next = NULL;
	
	//update tail info
	tail->next = temp;
	tail = temp;;
      }
  }

  void print()
  {
    if (head == NULL)
      {
	std::cout << "List is empty\n";
      }
    else
      {
	node<T>* current = head;
	while (current != NULL)
	  {
	    std::cout << current->value << " ";
	    current = current->next;
	  }
      }
  }


};




int main ()
{
  doubleLinkedList<int> list1;
  list1.print();

  for (int i = 0; i< 6; i++)
    {
      list1.push_back(i);
    }
  list1.print();
  return 0;
}
