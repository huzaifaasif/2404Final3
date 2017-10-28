//
//  genericClass.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-21.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef genericClass_hpp
#define genericClass_hpp

#include <stdio.h>
#include <string>
#include "Songs.hpp"
#include "Recordings.hpp"
#include "Track.hpp"
#include "Tracks.hpp"
using namespace std;

class genericClass{
public:
    
    //parse command strings methods
     void performOperation(string &input);
     static void parseIntFromString(string &input, int &id);
     void readFile(string fileName);
    
    //error related methods
    static bool errorCheck(string &input);
    static void printError();
    
    static string toTitleCase(string &str);
    static void moveToEnd(string &str, string value);
    
    
private:
    static size_t add_pos, delete_pos, help_pos, show_pos, read_pos, command, log_pos, quit;
    
    //songs
    Songs songs; //instantiating Songs object
    Recordings recordings;
    Recordings * recording_ptr;
    
    Tracks * tracks_ptr;
    Songs * song_ptr;

    Track track;
    Tracks tracks;
    
    int countForTracks=0;
    int count=0;
    
       
};


#endif /* genericClass_hpp */
