//
//  Recordings.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Recordings_hpp
#define Recordings_hpp

#include <stdio.h>
#include "Recording.hpp"
#include "Tracks.hpp"
#include <vector>

class Recordings{
public:
    Recordings();
    ~Recordings();
    
    void getData(string &input, class Tracks &tracks);
    void populatingTrack(Tracks &tracks, Recording &recording);
    
    void recordingsToRespectiveTrack(Tracks *track_ptr);
    
    //getters
    int getRecordingCollection(int index);
    int getRecordingAlbumID(int i);
    Recording *getRecordingInstance(int i);
    
    //setter
    void setRecordingPtr(Recording *recording);
    
    void printOn(ostream &o) const;
    
private:
    vector<Recording*> recordings_collection;
};

ostream & operator<<(ostream & out, const Recordings &recordings);

#endif /* Recordings_hpp */
