//
//  Songs.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-19.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

/*
	Songs represents a collection of compositions, specifically Song objects.
	A Songs container OWNS the songs within it.
	If the container is destroyed it deletes the Song objects it contains
	If a Song is removed from the container the Song object is deleted from heap space.
	*/

#include "Songs.hpp"
#include "genericClass.hpp"
#include <vector>
#include <iostream>

Songs::Songs(){
    
}

Songs::~Songs(){
    
    //delete [] collection;
    
//    for (int i=0; i<collection.size(); i++){
//        delete[] collection[i];
//    }
    
    for (auto *ptr: collection){
        delete ptr;
    }
    collection.clear();
    
}

void Songs::add(Song *aSong){
    
    collection.push_back(aSong);
    
}

//delete


void Songs::getData(string &input){
    
    //title
    size_t start = input.find("\"");
    size_t end = input.find("\"", start + 1);
    size_t diff = end-start+1;
    
    //composer
    size_t composer_start = input.find("\"", end+1);
    size_t composer_end = input.find("\"", composer_start+1);
    size_t diff_composer = composer_end-composer_start+1;
    
    int id=-1;
    
    //check for ID
    if (start==string::npos || end == string::npos || composer_start==string::npos || composer_end==string::npos){
        genericClass::printError();
        return;
    }
    
    //parsing ID
    genericClass::parseIntFromString(input, id);
    
    //----ERROR CHECK FOR ID----
    if (id == -1) {
        genericClass::printError();
        return;
    }
    
    
    //parsing title and composer
    string title = input.substr(start, diff);
    string composer = input.substr(composer_start+1, diff_composer-2);
    
    
    //calling constructor to create a Song object
    
    Song *song = new Song(title, composer, id);

    //this->add(song);
    
    //Appending it to the collection vector
    collection.push_back(song);
    
 
    cout<<*this<<endl;
}


vector<Song*>::iterator Songs::findPosition(Song & aSong){
    for (vector<Song*>::iterator it = collection.begin() ; it != collection.end(); ++it)
        if(*it == &aSong){
            return it;
        }
    return collection.end();
}


Song * Songs::findByID(int anID){
    for (vector<Song*>::iterator it = collection.begin() ; it != collection.end(); ++it)
        if( (*it)->getID() == anID){
            return *it;
        }
    return NULL;
}


/*Songs::findByID(int anID){
 Song song;
 
 for (int i=0; i<collection.size(); i++){
 
    if (collection[i]->getID()==anID){ //-> = derefencing and invoking method
        return collection[i];
    }
 }
 
 return NULL;
 }*/


void Songs::tracksToRespectiveSongs(Tracks *tracks, int count){
    
    for (int i=count; i<collection.size(); i++){
        
        if (collection[i]->getID() == tracks->getSongID(i)){
            tracks->getTrackInstance(i)->setSongPtr(collection[i]);
            
            cout <<"Track->Song: "<<tracks->getTrackInstance(i)->getSongPointer()<<endl;
            cout <<"Song ID: "<<collection[i]->getID()<<", "<<tracks->getSongID(i)<<endl;
            
            break;
        }
        cout <<endl;
    }
    
//    for (int i=0; i<tracks->sizeOfTrackCollection(); i++){
//        
//    }
    
//    for (int i=0; i<collection.size(); i++){
//        if (collection[i]->getID() == track->getSongID()){
//            track->setSongPtr(collection[i]);
//            
//            
//            break;
//            
//        }
//        
//        
//    }
    
    //cout <<track->getSongPointer()<<endl;
    
}

void Songs::printOn(ostream & o) const {
    cout <<"SONGS: "<<endl;
    for (int i=0; i<collection.size(); i++){
        o <<(*collection[i]).toString()<<endl;
    }
    
    cout <<"Size: "<<collection.size()<<endl;
    
}

ostream & operator<<(ostream & out, const Songs & Songs){
    Songs.printOn(out);
    
    return out;
}









