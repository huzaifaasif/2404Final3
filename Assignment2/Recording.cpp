//
//  Recording.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Recording.hpp"

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

string Recording::toString() const{
    return to_string(albumID) + " " + title + " " + artist + " " + producer + " " +to_string(year);
}
