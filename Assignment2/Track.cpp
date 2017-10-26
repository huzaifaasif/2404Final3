//
//  Track.cpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include "Track.hpp"
#include "genericClass.hpp"
#include <string>
#include <vector>
#include <sstream>

using namespace std;
//add -t track_id albumID songID track_number
Track::Track(){}

Track::Track(int track_id, int albumID, int songID, int track_number){
    
    this->track_id=track_id;
    this->albumID=albumID;
    this->songID=songID;
    this->track_number=track_number;
}

//getters
int Track::getAlbumID(){
    return albumID;
}

Recording *Track::getRecordingPointer(){
    return ptr_rec;
}

void Track::setRecordingPtr(Recording *recordingPtr){
    ptr_rec = recordingPtr;
}


string Track::toString() const{
    return to_string(track_id) + " " + to_string(albumID) + " " + to_string(songID) + " " + to_string(track_number);
}
