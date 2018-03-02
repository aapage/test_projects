using namespace std;


//Programmer: Alex Page
//Purpose: General Template for nodes to be used in linked list class
//-----------------------------------------------------------------------------


// LinkedNodeClass Constructor

template < class T >
LinkedNodeClass< T >::LinkedNodeClass(
		 LinkedNodeClass *inPrev,
		 const T &inVal,          
      		 LinkedNodeClass *inNext
		 )
{
	prevNode = inPrev;
	nodeVal = inVal;
	nextNode = inNext;
}

// LinkedNodeClass memeber funcitons

template < class T >
T LinkedNodeClass< T >::getValue() const
{
	return nodeVal; 
}

template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getNext() const
{
	return nextNode;
}

template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getPrev() const
{
        return prevNode;
}

template < class T >
void LinkedNodeClass< T >::setNextPointerToNull()
{
  nextNode = NULL;
}

template < class T >
void LinkedNodeClass< T >::setPreviousPointerToNull()
{
  prevNode = NULL;
}

template < class T >
void LinkedNodeClass< T >::setBeforeAndAfterPointers()
{
  if (prevNode != NULL) { prevNode->nextNode = this; }
  if (nextNode != NULL) { nextNode->prevNode = this; }
}
