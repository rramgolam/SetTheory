//
//  main.cpp
//  SetTheory
//
//  Created by Rishi Ramgolam on 05/12/2017.
//  Copyright © 2017 Rishi Ramgolam. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Set theory
    set<string> water_life;
    set<string> land_life;
    set<string> amphibians;
    set<string> all_life;
    set<string> not_amphibious_life;
    set<string> fish_life;
    int nWater = 10; int nFish = 4; int nLand = 9;
    
    string water[] = {"eel", "piranha", "shrimp", "frog", "trout", "pike", "newt", "beaver", "water flea", "beaver"};
    
    string fish[] = {"eel", "piranha", "trout", "pike"};
    
    string land[] = {"lemming", "hedgehog", "frog", "beaver", "badger", "fox","cow" ,"anteater", "newt"};
    
    // add items to set
    for (int i = 0; i < nWater; i++) water_life.insert(water[i]);
    for (int i = 0; i < nFish; i++) fish_life.insert(fish[i]);
    for (int i = 0; i < nLand; i++) land_life.insert(land[i]);
    
    for (int i = 0; i < nWater; i++)
    {
        cout << water[i] << endl;
    }
    
    set<string>::const_iterator p;
    cout << endl << "here is the set water-based life forms" << endl;
    
    for (p = water_life.begin(); p != water_life.end(); ++p)
    {
        cout << *p << endl;
    }
    
    
    // intersections
    insert_iterator<set<string, less<string> > > res_ins(amphibians, amphibians.begin());
    
    set_intersection(land_life.begin(), land_life.end(), water_life.begin(), water_life.end(), res_ins);
    
    cout << endl << "Set Intersection" << endl;
    for (p = amphibians.begin(); p != amphibians.end(); ++p)
    {
        cout << *p << endl;
    }
    
    
    // union of two sets
    insert_iterator<set<string, less<string> > > res2_ins(all_life, all_life.begin());
    
    set_union(land_life.begin(), land_life.end(), water_life.begin(), water_life.end(), res2_ins);
    
    cout << "Set Union" << endl;
    for (p = all_life.begin(); p != all_life.end(); ++p)
    {
        cout << *p << endl;
    }
    
    // difference
    insert_iterator<set<string, less<string> > > res3_ins(not_amphibious_life, not_amphibious_life.begin());
    
    set_difference(land_life.begin(), land_life.end(), water_life.begin(), water_life.end(), res3_ins);
    
    cout << "Set Difference" << endl;
    for (p = not_amphibious_life.begin(); p != not_amphibious_life.end(); ++p)
    {
        cout << *p << endl;
    }
    
    // whether one set is a subset of another
    if (includes(water_life.begin(), water_life.end(), fish_life.begin(), fish_life.end())) cout << "Fishes belong in water!" << endl;
}
