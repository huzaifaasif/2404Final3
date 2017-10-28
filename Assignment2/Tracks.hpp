//
//  Tracks.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Tracks_hpp
#define Tracks_hpp

#include "Recording.hpp"
#include "Track.hpp"
#include <stdio.h>
#include <vector>
#include "Recordings.hpp"
#include "Song.hpp"

class Tracks{
public:
    Tracks();
    ~Tracks();
    
    void setTrackCollection(Recording *recording);
    void getData(string &input);

    class Track *getTrackInstance(int index);
    size_t sizeOfTrackCollection();
    
    //getters
    int getAlbumID(int index);
    int getSongID(int index);
    
    //setter
    void setSongPtr(Song *songPtr);
   // void tracksToRespectiveAlbum(class Recordings *recordings);
    
    void removeData(string input);
    void printOn(ostream &o) const;
    
    
private:
   // vector<Recording*> tracks_collection;
    vector<Track*> tracks_collection;
   
};
ostream & operator<<(ostream & out, const Tracks & tracks);
#endif /* Tracks_hpp */
