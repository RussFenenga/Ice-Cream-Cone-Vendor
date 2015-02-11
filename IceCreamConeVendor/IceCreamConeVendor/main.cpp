//
//  main.cpp
//  IceCreamConeVendor
//
//  Created by Russ Fenenga on 2/11/15.
//  Copyright (c) 2015 Russ. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int numberCones;
int numberScoops;
float price;

class IceCreamCone{
    vector<char> flavors;
    public:
        IceCreamCone();
        void getFlavorsForCone(int);
        void printCone();
        float calcPrice(int);
};
IceCreamCone::IceCreamCone(){
    flavors.resize(5);
}
void IceCreamCone::getFlavorsForCone(int numberScoopsForCone){
    flavors.resize(numberScoopsForCone);
    for(int i = 0;i<numberScoopsForCone;i++){
        cout << "Specify the flavor for scoop ";
        cout << i+1; //user sees one based counting system
        cout << ": ";
        cin >> flavors[i];
    }
}
void IceCreamCone::printCone(){
    for(int i = 0; i<flavors.size();i++){
        cout << "(";
        cout << flavors[i];
        cout << ")\n";
    }
    cout << "\\ /\n";
    cout << " |  \n";
}
float IceCreamCone::calcPrice(int numberOfScoopsForCone){
    float total = 0.0;
    if (numberOfScoopsForCone==1){
        total+=2.00;
    }else if (numberOfScoopsForCone==2){
        total+=3.00;
    }else{
        total+=((numberOfScoopsForCone-2)*0.75)+3;
    }
    return total;
}

int main() {
    // insert code here...
    cout << "Welcome to Lt. Dan's Ice Cream Parlor!\n";
    cout << "--------------------------------------\n";
    cout << "1 Scoop -> $2:00\n";
    cout << "2 Scoops-> $3:00\n";
    cout << "Each Scoop after 2 -> $.75\n";
    cout << "--------------------------------------\n";
    cout << "Ice Cream Flavors: Only one input character for each flavor.\n";
    do{
        cout << "Please input the number of cones that you wish to purchase.(10 Max) ";
        cin >> numberCones;
    }while(numberCones<0 || numberCones>10);
    
    
    for(int i=0;i<numberCones;i++){
        do {
            cout << "How many scoops for cone ";
            cout << i+1;            //so the user gets a base 1 counting system for which cone they are on.
            cout <<"? (Limit of 5 scoops per cone.)";
            cin >> numberScoops;
        }while(numberScoops<0 || numberScoops>5);
        
        IceCreamCone cone;
        cone.getFlavorsForCone(numberScoops);
        cone.printCone();
        price+=cone.calcPrice(numberScoops);
    }
    cout << "Total charge: $";
    cout << price;
    cout <<"\n";
    return 0;
}
