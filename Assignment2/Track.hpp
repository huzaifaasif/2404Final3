//
//  Track.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Track_hpp
#define Track_hpp

//contains mp3 files of Song objects
//add -t track_id albumID songID track_number

#include <stdio.h>
#include <string>
#include "Recording.hpp"

using namespace std;

class Track{
public:
    Track();
    Track(int track_id, int albumID, int songID, int track_number);
    
    string toString() const;
    
    //getters
    int getAlbumID();
    class Recording *getRecordingPointer();
    
    //setter
    void setRecordingPtr(class Recording *recordingPtr);
    
private:
    int track_id, albumID, songID, track_number;
    
     class Recording *ptr_rec;
};

#endif /* Track_hpp */
