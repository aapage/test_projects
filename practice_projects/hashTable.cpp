#include <iostream>
#include <string>
#include <forward_list>


//global
const int TABLE_SIZE =13;


struct pair
{
  std::string  value;
  std::string key;

  pair(std::string valueIn, std::string keyIn): value(valueIn), key(keyIn){;}
 
};


class hashTable
{
private:
  std::forward_list< pair >* table[TABLE_SIZE];
  
public: 
  //ctor
  hashTable()
  {
    for (int i = 0; i < TABLE_SIZE; i++)
      {
	table[i] = NULL;
      }
  }
  
  void addPair(std::string valueIn, std::string keyIn)
  {
    pair inPair(valueIn, keyIn);
    
    int element = hash(inPair.key);
    
    if (table[element] != NULL)
      {
	//collision detected
	//pop new pair to the front of the flist
	table[element]->push_front(inPair);
      }
    else
      {
	table[element] = new std::forward_list<pair>();
	table[element]->push_front(inPair);
      }

  }

  int hash(std::string key)
  {

    int keyValue = 0;
    for (int i = 0; i < key.length(); i++)
      { keyValue += key[i];}

    int hashedKey = keyValue % TABLE_SIZE;
    return hashedKey;
  }
  
  void print()
  {
    for (int i = 0; i < TABLE_SIZE; i++)
      {
	std::cout << "[" << i << "] ";

	if (table[i] == NULL)
	  {std::cout << "NULL" << std::endl;}
	else
	  {
	    for (auto it = table[i]->begin(); it != table[i]->end(); it++)
	      {
		std::cout << it->value << " ";
	      }
	    std::cout << std::endl;
	  }
      }

  }

  bool findValue(std::string key)
  {

    int hashedKey = hash(key);
    if (table[hashedKey] == NULL)
      {
	std::cout << "ERROR: No Value Stored" << std::endl;
	return false;
      }

    else
      {
	for (auto it = table[hashedKey]->begin(); it != table[hashedKey]->end(); it++)
	  {
	    if (it->key == key)
	      {
		std::cout << "Key: " << key << " Value: " << it->value << std::endl;
		return true;
	      }
	    
	  }
	std::cout << "ERROR: No Value Stored" << std::endl;
	return false;
      }

  }


};







int main()
{
  
  hashTable table1;
  //pair eddie( "75", "eddie") ;
  table1.addPair( "75","eddie");
  table1.addPair( "70","gloria");
  table1.addPair( "30","sven");
  table1.addPair( "28","alex");

  table1.addPair( "28","alre");
  table1.addPair( "28","alwerwetx");
  table1.addPair( "28","aldfsfex");
  table1.addPair( "28","ale44x");
  table1.addPair( "28","ale22x");
  table1.addPair( "28","alddfex");  
  table1.print();
  
  table1.findValue("eddie");


  return 0;
}
