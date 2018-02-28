#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
const string FRONTIER = "F";
const string OPEN = "O";
const string CLOSED = "C";


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
};

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
    while (!goalFound)
    {
    	goalFound = expandFrontier();
    	printGraph();
    }
    cout << "\n\nGoal Found!!!\n\n" << endl;
    printPath();
  }
  bool expandFrontier()
  {
    vector<node*> newFrontier;
    while (frontier.size() > 0)
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
    frontier = newFrontier;
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

};


int main ()
{

  graphClass graph1;
  graph1.initializeGraph();
  graph1.bfs(4,3,15,18);
  //graph1.print();
  //graph1.printGraph();
  return 0;
}
