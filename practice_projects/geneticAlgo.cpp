#include <iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

const int NUM_GENES = 15;

struct genome
{
  bool dna[NUM_GENES];
  float score;
  
  genome(){}
  genome(bool a0, bool a1, bool a2, bool a3, bool a4 )
  {
    dna[0] = a0;
    dna[1] = a1;
    dna[2] = a2;
    dna[3] = a3;
    dna[4] = a4;
  }
  void randomize()
  {
    for (int i = 0; i < NUM_GENES; i++)
      {
	dna[i] = rand()%2; 
      }
  }

  void print()
  {
    for (int i = 0; i < NUM_GENES; i++)
      {
	std::cout << dna[i] << " " ;
      }
    std::cout << "\n";
  }
  
  void setScore( genome key)
  {
    float newScore = 0.0;
    for (int i = 0; i < NUM_GENES; i++)
      {
	if (dna[i] == key.dna[i]) {newScore++;}
      }
    //get score as percentage
    newScore = newScore/NUM_GENES*100;
    score = newScore;
  }

  //comparison operator<
  bool operator < (const genome &a) const
  {
    return score < a.score;
  }
  
};

bool compareGenomePtr(genome* &a1, genome* &a2)
{
  return a1->score < a2->score;
}

genome mate(genome p1, genome p2)
{
  int splitIndex = rand()%(NUM_GENES+1);
  genome child;
  
  for (int i = 0; i < splitIndex; i++)
    {
      child.dna[i] = p1.dna[i];
    }
 for (int i = splitIndex; i >= splitIndex && i < NUM_GENES; i++)
    {
      child.dna[i] = p2.dna[i];
    }
  return child;
}

void generatePopulation(int populationSize, std::vector<genome*>  &population)
{
  for (int i = 0; i < populationSize; i++)
    {
      population.push_back(new genome);
      population[i]->randomize();
    }  
  
}



int main()
{
  srand(0);

  //set key for goal
  genome key;
  key.randomize();
  std::cout<< "KEY: ";
  key.print();

  //generate inital population
  int populationSize = 20;

  std::vector<genome*> population;  
  generatePopulation(populationSize, population);

  std::cout<< "Initial Population: " << populationSize << "\n"; 



  //main loop-----------------------------------------------------------------------------


  float maxScore = 0;
  int maxGeneration = 20;
  int currentGeneration = 0;
  int numChildren = 7;
  int numBreeders = 10;
  int mutationChance = 10; //unit: precentage points

  while (maxScore < 100 && currentGeneration < maxGeneration )
    {
      //update generation number
      currentGeneration++;
      std::cout << "\n--------------------------------\n";
      std::cout << "\nGeneration #" << currentGeneration << "\n";

      //evaluate scores and sort population based on most fit
      for (int i = 0; i < population.size(); i++)
	{
	  population[i]->setScore(key); 
	}

      
      //sort population list and reverse it to get it largest to smallest      
      std::sort(population.begin(), population.end(), compareGenomePtr );
      std::reverse(population.begin(), population.end());

      maxScore = population[0]->score;
      std::cout << "Best Score: " << maxScore << "\n";

      //print out current generation sorted
      std::cout<< "\nPopulation: \n";
      for (int i = 0; i < population.size(); i++)
	{
	  std::cout<< "Score: " << population[i]->score << " - ";
	  population[i]->print();
	}
      
      //if no solution found yet, mate current population
      for (int i = 0; i < numChildren; i++)
	{
	  //random selection of two parents within top numBreeders 
	  int p1Index = rand()%numBreeders;
	  int p2Index = rand()%numBreeders;
	  //no self breeding
	  while (p2Index == p1Index)
	    {p2Index = rand()%numBreeders;}
	  
	  //remove least fit, and replace with child
	  int newChildIndex = population.size()-i-1;
	  *population[newChildIndex] = mate(*population[p1Index], *population[p2Index]);
	}

      //mutation
      for (int i = 0; i < population.size(); i++)
        {
	  if (rand()%100+1 > 100-mutationChance)
	    {
	      std::cout<< "mutation!\n";
	      //flip the bit
	      int geneIndex = rand()%NUM_GENES;
	      population[i]->dna[geneIndex] = !population[i]->dna[geneIndex];
       
	    }
	}
      
      //end main loop
    }

  //-----------------------------------------------------------------------

  /*
  genome p1;
  
  p1.randomize();
  p1.print();
  
  genome p2;
  p2.randomize();
  p2.print();

  genome child;
  
  genome key;
  key.randomize();
  key.randomize();
  for (int i = 0; i < 3; i++)
    {
      child = mate(p1,p2);
      //child = p2;
      child.print();
      child.setScore(key);

      std::cout <<  child.score << "\n";
    }

  std::cout << "KEY: " ;
  key.print();
  */
  
  
  return 0;
}
