//
//  genericClass.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-21.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "genericClass.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include "Song.hpp"
#include "Songs.hpp"
#include "Recordings.hpp"
#include <fstream>
using namespace std;

size_t genericClass::quit=0,
genericClass::help_pos=0,
genericClass::add_pos=0,
genericClass::delete_pos=0,

genericClass::show_pos=0,
genericClass::read_pos=0,
genericClass::command=0,
genericClass::log_pos=0;


void genericClass::parseIntFromString(string &str, int &id){
    string temp;
    
    
    for (int i=0; i<str.length(); i++){
        if (isdigit(str[i])){
            for (int j=i; j<str.length(); j++){
                temp += str[j];
            }
            break;
        }
    }
    
    istringstream stream(temp);
    stream >> id;
    
    
}

//delete
void genericClass::deleteItems(string &input){
    
   
    
    
}

//parsing commands
void genericClass::performOperation(string &input){
    
    string operation; //add, delete, show (first word)
    string collection;    //song, recording, playlist, etc
    string keyword;     //s, r
    size_t hyphen = input.find("-");
    operation = input.substr(0, input.find(" ")); //first word
    
    
    keyword = input.substr(hyphen+1, 1);
    
    if (hyphen==string::npos){
        printError();
        return;
    }
    
    
//-----adding----
    
    if (operation == "add"){
        

        if (keyword=="s"){  //if it's "s", then create song object+append to the vector
            
            songs.getData(input);
            song_ptr = &songs;

        }
        else if (keyword == "r"){
            recordings.getData(input, tracks);
            //recording_ptr = &recordings;
            
        }
        else if (keyword == "t"){
            tracks.getData(input);  //parsing track info ie albumID etc...
            
            tracks_ptr = &tracks;
            recordings.recordingsToRespectiveTrack(tracks_ptr, countForTracks); //points recording to respective tracks
            countForTracks++;
            
            if (count<=tracks_ptr->sizeOfTrackCollection()){
                songs.tracksToRespectiveSongs(tracks_ptr, count);
            }
            count++;
            
            
    //        for (int i=0; i<recordings.getRecordingCollectionSize(); i++){
    //            
    //            if (i<=recordings.getRecordingInstance(i)->getTrackPtrCollectionSize()){
    //                cout <<"Album ID: "<<recordings.getRecordingInstance(i)->getAlbumID()<<endl;
    //                recordings.getRecordingInstance(i)->printTrackPtrCollection(tracks_ptr);
    //            }
    //        }
            
        }
    }
    
    else if (operation == "delete"){
        
        
        if (keyword == "s"){
            songs.removeData(input);
        }
        
        else if (keyword == "r"){
            recordings.removeData(input);
        }
        
        else if (keyword == "t"){
            tracks.removeData(input);
        }
        
    }
    
}
//tracks.tracksToRespectiveAlbum(recording_ptr);
//
//count++;
void genericClass::readFile(string fileName){
    
    string input;
    
    ifstream file_input(fileName, ifstream::in);
    
    //cout <<"FILE NAME: "<<fileName<<endl;
    
    if (!file_input){
        cout <<"File couldn't open - Enter the correct file name!!"<<endl;
    }
   
    while (getline(file_input, input)){
        
        if (fileName == "helpfile.txt"){
            cout << input<<endl;
        }
        else{
            performOperation(input);
        }
    }
    
    cout <<endl;
}

bool genericClass::errorCheck(string &input){
    
    cout <<"INPUT: "<<input<<endl;
    
    // size_t add_pos, remove_pos, show_pos;
    quit = input.find(".quit");
    help_pos = input.find(".help");
    add_pos = input.find("add");
    
    delete_pos = input.find("delete");
    show_pos = input.find("show");
    read_pos = input.find(".read");

    log_pos = input.find(".log");
    
    if (add_pos!=string::npos || show_pos!=string::npos || delete_pos!=string::npos || read_pos!=string::npos || help_pos!=string::npos || quit!=string::npos || log_pos!=string::npos){
            return true;
    }
    
    return false;
    
}

void genericClass::printError(){
    cout << "Enter correct commands or type in .help!"<<endl<<endl;
}
