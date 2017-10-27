//
//  Recording.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Recording.hpp"
#include "Track.hpp"
#include <iostream>

Recording::Recording(int albumID, string title, string artist, string producer, int year){
    this->title=title;
    this->artist=artist;
    this->producer=producer;
    this->year=year;
    this->albumID=albumID;
}

Recording::~Recording(){
    
    for (auto *ptr: trackPtrCollection){
        delete ptr;
    }
    
    trackPtrCollection.clear();

}
//getter
int Recording::getAlbumID(){
    return albumID;
}

Track *Recording::createNewPtr(){
    Track *ptr = nullptr;
    return ptr;
}

void Recording::addTrackPtr(Track *track){
    //ptr_track = track;
    
    trackPtrCollection.push_back(track);
    cout << "Track pointer collection vector: "<<trackPtrCollection.size()<<endl;
}

Track *Recording::getTrackPointer(int index){
    return trackPtrCollection[index];
}

string Recording::toString() const{
    return to_string(albumID) + " " + title + " " + artist + " " + producer + " " +to_string(year);
}
