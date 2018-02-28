#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
const string FRONTIER = "F";
const string OPEN = "O";
const string CLOSED = "C";
const string OBSTACLE = "X";
const int NUM_PRIORITY_NODES = 5;

struct position
{
  int x;
  int y;
};

struct node
{
  position pos; //x and y location in graph
  node* parent;
 
  //other info
  int distance;
  float score;
  string tag; 
  bool isStart;
  bool isGoal;
  
  node (int xPos, int yPos, string tagIn, node* parentIn = NULL)
  {
    pos.x = xPos;
    pos.y = yPos;
    tag = tagIn;
    parent = parentIn;
    distance = 10000; //something to represent inf
    
    isStart = false;
    isGoal = false;
  }
  
  bool operator < (const node nodeIn) const
  {
    return score < nodeIn.score; 
  }
};


static bool ptrCompare(node* ptr1, node* ptr2)
{
  return *ptr1 < *ptr2;
}


class graphClass
{
private:
  vector< vector<node*> > grid;
  vector<node*> frontier;
  
  node* start;
  node* goal;
public:
  
  void initializeGraph()
  {
    for (int i = 0; i < HEIGHT; i++)
      {
	vector<node*> tempVector;
	for (int j = 0; j < WIDTH; j++)
	  {
	    node* tempNode = new node(j, i, OPEN);
	    tempVector.push_back(tempNode);
	  }
	grid.push_back(tempVector);
      }
  }
  void print()
  {
    for (auto it1 = grid.begin(); it1 != grid.end(); it1++)
      {
	for (auto it2 = it1->begin();
	     it2 < it1->end(); it2++)
	  {
	    cout << (*it2)->pos.y << "-" << (*it2)->pos.x << ": " << 
	      (*it2)->tag << ", dist = " << (*it2)->distance  << ", parent: ";
	    if ((*it2)->parent != NULL)
	      {
		cout << (*it2)->parent->pos.y << "-"
		    << (*it2)->parent->pos.x << endl;
	      }
	    else if ((*it2)->isStart == true)
	      {cout << "START" << endl;}
	  
	    else if ((*it2)->isGoal == true)
	      {cout << "END" << endl;}
                
            else
	      {cout << "unkown" << endl;}
	  }
      }
  }
  void printGraph()
  {
    for (auto it1 = grid.begin(); it1 != grid.end(); it1++)
      {
        for (auto it2 = it1->begin();
             it2 < it1->end(); it2++)
          {
            cout << (*it2)->tag;
	    if (it2 + 1 < it1->end()) {cout << "  ";}
	  }
	cout << endl;
      }
    cout << "---------------" << endl;
  }
  
  void printPath()
  {
    node* parent = goal->parent;
    cout << "Distance from START to GOAL = " << goal->distance << endl;
    cout << "Path: ";
    while(parent != NULL)
      {
	cout << "(" <<  parent->pos.y << "," << parent->pos.x << ") ";
	parent = parent->parent;
      }
    cout << endl;
  }

  void bfs(int startX, int startY, int goalX, int goalY)
  {
    //initialize frontier to start
    start = grid[startY][startX];
    start->isStart = true;
    start->distance = 0;
    addToFrontier(start, NULL);    

    goal = grid[goalY][goalX];
    goal->isGoal = true;
    bool goalFound = false;
    int numIterations = 0;
    while (!goalFound)
      {
	goalFound = expandFrontier();
	printGraph();
	sortFrontier();
	numIterations++;
      }
    goal->tag = "G";
    start->tag = "S";
    printGraph();
    cout << "\n\nGoal Found in " << numIterations
	 << " iterations!!!\n\n" << endl;

    
    printPath();
  }
  bool expandFrontier()
  {
    vector<node*> newFrontier;
    //------------------------------------------------------------
    //limit number of nodes expanded on the frontier, priority first
    //
    //
    for (int i = 0; i < NUM_PRIORITY_NODES && frontier.size()>0; i++ )
      {
	node* back = frontier.back();
	vector<node*> neighbors = getNeighbors(back);
	for (auto it2 = neighbors.begin(); it2 < neighbors.end(); it2++)
	  {
	    if ((*it2)->distance > back->distance +1)
	      {
		(*it2)->distance = back->distance + 1;
		(*it2)->parent = back;
	      }

	    //check if neighbor is open
	    if ((*it2)->tag == OPEN)
	      {
		//add to frontier
		newFrontier.push_back(*it2);
		(*it2)->tag = FRONTIER;
		//check if open node is goal
		if (*it2 == goal){return true;}
      	      }  
	  }
	//remove node from frontier and close
	back->tag = CLOSED;
	frontier.pop_back();
      }
    frontier.insert(frontier.end(), newFrontier.begin(), newFrontier.end());
  }
  float  getScore(node* nodeIn)
  {
    //greedy
    float score;
    int dX2 = nodeIn->pos.x - goal->pos.x;
    dX2 *= dX2;
    
    int dY2 = nodeIn->pos.y - goal->pos.y;
    dY2 *= dY2;
    
    //A*
    score = sqrtf((float)dX2+(float)dY2) + nodeIn->distance;

    nodeIn->score = score;
    return score;
  }
  void sortFrontier()
  {
    for (auto it = frontier.begin(); it < frontier.end(); it++)
      {
	getScore(*it);
      }
    //sort------------
    sort(frontier.begin(), frontier.end(), ptrCompare);
    reverse(frontier.begin(), frontier.end());
    //print sorted-----------
    //cout << "---------Sorted------------" << endl;
    //for (auto it = frontier.begin(); it < frontier.end(); it++)
    //  {
    //	cout << (*it)->pos.x << "," << (*it)->pos.y;
    //  cout << ": " << getScore(*it) << endl;
    //  }

  }
  
  void addToFrontier ( node* &nodeIn, node * parentNode )
  {
    frontier.push_back(nodeIn);
    nodeIn->tag = FRONTIER;
    nodeIn->parent = parentNode;  
  }

  vector<node*> getNeighbors (node* nodeIn)
  {
    //for direct nearest neighbors in fully connected graph
    vector<node*> neighbors;
    int x = nodeIn->pos.x;
    int y = nodeIn->pos.y;
    if (x > 0) {neighbors.push_back(grid[y][x-1]);}
    if (x < WIDTH - 1) {neighbors.push_back(grid[y][x+1]);}
    if (y > 0) {neighbors.push_back(grid[y-1][x]);}
    if (y < HEIGHT - 1) {neighbors.push_back(grid[y+1][x]);}
    
    return neighbors;
  }
  
  void createObstacle(int xPos, int yPos)
  {
    grid[yPos][xPos]->tag = OBSTACLE;
  }
};


int main ()
{

  graphClass graph1;
  graph1.initializeGraph();

  //creat obstacles
  for (int x = 3; x < 10; x++)
    {
      graph1.createObstacle(x,10);
    }  
  for (int y = 1; y < 12; y++)
    {
      graph1.createObstacle(10,y);
    }



  graph1.bfs(4,3,15,15);


  //graph1.print();
  //graph1.printGraph();
  return 0;
}
