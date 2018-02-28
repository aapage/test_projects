//Programmer: Alex Page
//-----------------------------------------------------------------------------

//FIFOQueueClass constructor

template < class T >
FIFOQueueClass< T >::FIFOQueueClass()
{
  head = NULL;
  tail = NULL;
}

//FIFOQueueClass member fuctions

//Inserts the value provided (newItem) into the queue.
template < class T >
void FIFOQueueClass< T >::enqueue( const T &newItem)
{
  
  LinkedNodeClass< T >* newPrev;
  LinkedNodeClass< T >* newNext;

  if (head == NULL )
    {
      newPrev = NULL;
      newNext = NULL;
    }
  else
    {
      newPrev = tail;
      newNext = NULL;
    }

  LinkedNodeClass< T > *newNode = 
    new LinkedNodeClass< T >(newPrev,newItem,newNext);  
  newNode->setBeforeAndAfterPointers();

  //set new head and tail
  if (newPrev == NULL) {head = newNode;}
  tail = newNode; 
}

//Attempts to take the next item out of the queue. If the
//queue is empty, the function returns false and the state
//of the reference parameter (outItem) is undefined. If the
//queue is not empty, the function returns true and outItem
//becomes a copy of the next item in the queue, which is
//removed from the data structure.
template < class T >
bool FIFOQueueClass< T >::dequeue(T &outItem)
{
  bool queueNotEmpty;
  LinkedNodeClass< T >* currentNode = head;

  if (head == NULL)
    {
      queueNotEmpty = false;
    }
  else
    {
      queueNotEmpty = true; 
      outItem = head->getValue();
      head = head->getNext();
      delete currentNode;
      currentNode = NULL;

      //if new head is a node, set prev to null
      if (head != NULL)
	{ head->setPreviousPointerToNull(); }
      else //list is now empty
	{tail = NULL;}
    }
  return queueNotEmpty;
}



//Prints out the contents of the queue. All printing is done
//on one line, using a single space to separate values, and a
//single newline character is printed at the end.
template < class T >
void FIFOQueueClass< T >::print() const
{
  bool endOfQueue = false;
  LinkedNodeClass< T >* currentNode = head;

  while(!endOfQueue)
    {
      if (currentNode == NULL) {endOfQueue = true;}

      else
	{
	  cout << currentNode->getValue() << " "; 
	  currentNode = currentNode->getNext();
	}
    }
  cout << endl;
}
