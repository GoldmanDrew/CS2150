/** file
*   Drew Goldman
*   dag5wd
*   11/12/2020
*   middlearth.h
*/
#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
public:

 /**
 * @brief MiddleEarth constructor
 *
 * @param xsize The size of the x-axis
 * @param ysize The size of the y-axis
 * @param num_cities The number of cities on the MiddleEarth
 * @param seed The seed of the MiddleEarth.
 */
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);
    
    
 /**
 * @brief Prints the MiddleEarth
 *
 * @see printTable()
 */    
    void print();
    
    
 /**
 * @brief Prints out a tab-spaced table of the MiddleEarth
 *
 * @see print()
 */      
    void printTable();
   
   
 /**
 * @brief Computes and returns the distance between two cities
 *
 * @return a float of the distance between two cities
 * @param city1 name of city1
 * @param city2 name of city2
 */    
    float getDistance(const string& city1, const string& city2);
    
    
 /**
 * @brief Computes a list of the cities to travel to
 *
 * @return a vector of the cities to travel to
 * @param length the length of the list
 */       
    vector<string> getItinerary(unsigned int length);

private:
 /**  
 * @var num_city_names number of cities
 * @var xsize length of the x-axis of MiddleEarth 
 * @var ysize length of the y-axis of MiddleEarth
 */
    int num_city_names, xsize, ysize;
    
 /**  
 * @var xpos an unordered_map of x positions
 * @var ypos an unordered_map of y positions
 */  
    unordered_map<string, float> xpos, ypos;
    
 /**  
 * @var cities a list of cities
 * @var distances an unordered_map distances
 */     
    vector<string> cities;
    unordered_map<string, unordered_map<string, float>> distances;

    mt19937 gen; // Mersenne-Twister random number engine
};

#endif
