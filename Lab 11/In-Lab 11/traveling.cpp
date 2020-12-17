#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, const vector<string>& dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    vector<string> printV = dests;
    sort(1 + dests.begin(), dests.end());
    string s = dests[0];
    float tmp = 0.0;
    float shortestPath = computeDistance(me, s, dests);
    
    while(next_permutation(1 + dests.begin(), dests.end())) {
    	tmp = computeDistance(me, s, dests);
    	if (tmp < shortestPath) { // this line may cause issue
    		shortestPath = tmp;
    		printV = dests;
    	}
    }
    cout << "Minimum path has distance " + to_string(shortestPath) + ": ";
    s = printV[0];
    printRoute(s, printV);
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    string b = start;
    float distance = 0.0;
    int size = dests.size();
    
    for(int i = 0; i < size; i++) {
    	distance = distance + me.getDistance(b, dests[i]);
    	b = dests[i];
    }
    
    return floor(10000 * (distance + me.getDistance(dests[0], dests.back())))/10000;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    int size = dests.size();

    for (int i = 0; i < size; i++) cout << dests[i] + " -> ";
    cout << start << endl;
}
