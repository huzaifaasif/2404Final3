//
//  Recording.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Recording.hpp"
#include "Track.hpp"
Recording::Recording(int albumID, string title, string artist, string producer, int year){
    this->title=title;
    this->artist=artist;
    this->producer=producer;
    this->year=year;
    this->albumID=albumID;
}

//getter
int Recording::getAlbumID(){
    return albumID;
}

Track *Recording::createNewPtr(){
    Track *ptr = nullptr;
    return ptr;
}

void Recording::setTrackPtr(Track *track){
    //ptr_track = track;
    
}

Track *Recording::getTrackPointer(){
    return ptr_track;
}

string Recording::toString() const{
    return to_string(albumID) + " " + title + " " + artist + " " + producer + " " +to_string(year);
}
