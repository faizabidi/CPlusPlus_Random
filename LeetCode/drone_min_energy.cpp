// https://www.pramp.com/challenge/BrLMj8M2dVUoY95A9x3X

#include <iostream>
#include <vector>

void printvector(std::vector<int> array){
  for(int i = 0; i < array.size(); i++)
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

int calcDroneMinEnergy(std::vector<std::vector<int>> route){
  int current_energy = 0;
  int min_energy_needed = 0;

  // Save all the z-coordintes
  std::vector<int> z_coordinates;
  for(int i = 0; i < route.size(); i++){
    std::vector<int> point = route[i];
    z_coordinates.push_back(point[2]);
  }
  
  printvector(z_coordinates);

  // If drone goes desc, energy gained. If it goes asc, energy lost.
  for(int i = 1; i < z_coordinates.size(); i++){
    current_energy += (z_coordinates[i - 1] - z_coordinates[i]);
    std::cout << "Current energy = " << current_energy << std::endl;
    // Add energy if enerygy is less than 0
    if(current_energy < 0){
      min_energy_needed += std::abs(current_energy);
      std::cout << "Minimum energy needed = " << min_energy_needed 
                                                    << std::endl;
      current_energy = 0;
    }
  }
  return min_energy_needed;
}

int main(){
  std::vector<std::vector<int>> route{
    {0, 2, 10},
    {3, 5, 0},
    {9, 20, 6},
    {10, 12, 15},
    {10, 10, 8}
  };

  std::cout << calcDroneMinEnergy(route) << std::endl;
  return 0;
}
