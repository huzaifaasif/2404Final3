//
//  main.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-17.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include <iostream>
#include "Song.hpp"
#include "Songs.hpp"
#include "genericClass.hpp"
#include <string>
#include <algorithm>

using namespace std;

int main() {
    
    string input;
    //--> add -s "Ross" "Jim" 101
    
    //inside add method
    
    genericClass general_instance;

    string helpFile = "helpfile.txt";
    string scriptFile = "scriptfile.txt";
    
    for (;;){
        
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        
        
        //if unrecognizable commands are entered, print error
        
        if(!genericClass::errorCheck(input)){
            genericClass::printError();
            
        }
        
        else{
            //quit, help, read
            
            if (input == ".quit"){
                return 0;
            }
            else if (input == ".help"){
                general_instance.readFile(helpFile);
            }
            else if (input == ".read"){
                general_instance.readFile(scriptFile);
            }
            
            //performing any operation
            else{
                //genericClass::performOperation(input);
                general_instance.performOperation(input);
            }
        
            
            
            
            
//            Song *song = new Song("Ross", "Jim", 101);
//            
//            Songs collection;
//            collection.add(song);
//            
//            
//            //---
//            Song *songs = new Song("Taylor", "Kha", 105);
//            collection.add(songs);
//            
//            cout <<collection;
        }
    
    }
//    Song Ross("Ross", "Jim", 101);
//    Song Taylor("Taylor","kha",105);
//    Song Jim("Jim", "Ha", 110);
    //cout<<Ross;
    
//    Songs coll;
//
//    cout <<coll;
//    Song newSong = *coll.findByID(105);
//    cout << newSong<<"\n";
    
    
    
}
