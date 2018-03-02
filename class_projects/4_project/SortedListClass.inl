
//Programmer: Alex Page
//The sorted list class does not store any data directly. Instead,
//it contains a collection of LinkedNodeClass objects, each of which
//contains one element.
//-----------------------------------------------------------------------------
 

//SortedListClass Constructors-------------------------------------------------

//default constructor
template < class T >
SortedListClass< T >::SortedListClass()
{
  head = NULL;
  tail = NULL;
}

//copy constructor
template < class T >
SortedListClass< T >::SortedListClass(const SortedListClass< T > &rhs)
{
  bool endOfList = false;
  LinkedNodeClass< T >* currentNode = rhs.head;
  head = NULL;
  tail = NULL;
  if (rhs.head != NULL) //check the list is not empty
    {
      while(!endOfList)
	{
	  this->insertValue(currentNode->getValue());
	  if (currentNode->getNext() == NULL) {endOfList = true;}
	  currentNode = currentNode->getNext();
	}  
    }
}

template < class T >
void SortedListClass< T >::clear()
{
  bool endOfList = false;
  LinkedNodeClass< T >* currentNode = tail;
  while (!endOfList)
    {
      if (tail == NULL) {endOfList = true;}
      else
	{
	  currentNode = tail;
	  tail = tail->getPrev();
	  delete currentNode;
	  currentNode = NULL;
	}
    }
  head = NULL; //so that head does not point at deleted memory
}




//insertValue function
template < class T >
void SortedListClass< T >::insertValue( const T &valToInsert )
{   

  LinkedNodeClass< T >* currentNode = head;
  LinkedNodeClass< T >* newPrev;
  LinkedNodeClass< T >* newNext;
  T newValue;
  bool endOfList = false; //while loop condition
 
  while (!endOfList)
    {
      //insert into empty list
      if (head == NULL && tail == NULL)
	{
	  newPrev = NULL;
	  newValue = valToInsert;
	  newNext = NULL;
	  endOfList = true;
	}
      
      //insert the newNode before the currentNode if value is less than
      //the currentNode val
      else if (valToInsert < currentNode->getValue())
	{
	  newPrev = currentNode->getPrev();
	  newValue = valToInsert;
	  newNext = currentNode;  
	  endOfList = true;
	}
      
      //insert node at tail if not less than the tail node.
      else if (currentNode->getNext() == NULL)
	{
	  endOfList = true;
	  newPrev = currentNode;
	  newValue =  valToInsert;
	  newNext = NULL;    
	}
      
      //move on to next node
      else
	{
	  currentNode = currentNode->getNext();
	}
    }

  //define new node
  LinkedNodeClass< T >* newNode = new LinkedNodeClass< T >(newPrev, newValue, newNext);
  
  //check if newNode is the head now
  if (newPrev == NULL) {head = newNode;}
  if (newNext == NULL) {tail = newNode;}
  newNode->setBeforeAndAfterPointers();
  
}

//print forwards
template < class T >
void SortedListClass< T >::printForward() const
{
  bool endOfList = false;
  LinkedNodeClass< T > *currentNode = head;

  cout <<  "Forward List Contents Follow:" << endl;

  while (!endOfList)
    {
      if (currentNode == NULL)//empty list
	{cout << "End Of List Contents" << endl; endOfList = true;}
      else
	{
	  cout << "  " << currentNode->getValue() << endl;
	  currentNode = currentNode->getNext();
	}
    }
}

//print backwards
template < class T >
void SortedListClass< T >::printBackward() const
{
  bool startOfList = false;
  LinkedNodeClass< T > *currentNode = tail;

  cout <<  "Backward List Contents Follow:" << endl;

  while (!startOfList)
    {
      cout << "  " << currentNode->getValue() << endl;
      if (currentNode->getPrev() == NULL)
        {
          startOfList = true;
          cout << "End Of List Contents" << endl;
        }
      else { currentNode = currentNode->getPrev();}
    }
}

//removeFront node
template < class T >
bool SortedListClass< T >::removeFront(T &theVal)
{
  bool emptyList = false;
  LinkedNodeClass< T >* currentNode = head;
    
  if (head ==NULL)
    {	   
    emptyList = true;
    }	      
  else
    {
      head = head->getNext();
      theVal = currentNode->getValue(); //give theVal the value before delete
      delete currentNode;
      currentNode = NULL;
      //set prevNode to NULL in new head
      if (head != NULL) {head->setPreviousPointerToNull();}
      if (head == NULL) {tail = NULL;}
    }
  return emptyList;
}


//remove last node
template < class T >
bool SortedListClass< T >::removeLast(T &theVal)
{
  bool emptyList = false;
  LinkedNodeClass< T >* currentNode = tail;

  if (tail == NULL)
    {emptyList = true;}
  else
    {
      tail = tail->getPrev();
      theVal = currentNode->getValue(); //give theVal the value before delete
      delete currentNode;
      currentNode = NULL;
      //set NextNode to NULL in new tail
      if (tail != NULL) { tail->setNextPointerToNull(); }
    }
  return emptyList;
}

template < class T >
int SortedListClass< T >::getNumElems() const
{
  bool endOfList = false;
  LinkedNodeClass< T >* currentNode = head;
  int listSize =0;
  while (!endOfList)
    {
      if (currentNode == NULL) {endOfList = true;}
      else {currentNode = currentNode->getNext(); listSize++;}
    }
  return listSize;
}  

template < class T >
bool SortedListClass< T >::getElemAtIndex(const int index, T &outVal)
{
  bool atTarget = false;
  bool inRange;
  int tempIndex = 0;
  LinkedNodeClass< T >* currentNode = head;

  while (!atTarget)
    {
      if (currentNode == NULL)
	{inRange = false; atTarget = true; }
      else if (tempIndex == index)
	{
	  atTarget = true;
	  inRange = true;
	  outVal = currentNode->getValue();
	}
      else {currentNode = currentNode->getNext(); tempIndex++;}
    }
  return inRange;
}

