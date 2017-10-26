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

class Tracks{
public:
    Tracks();
    ~Tracks();
    
    void setTrackCollection(Recording *recording);
    void getData(string &input);

    Track *getTrackInstance(int index);
    
    void tracksToRespectiveAlbum(class Recordings *recordings);
    
    void printOn(ostream &o) const;
    
    
private:
   // vector<Recording*> tracks_collection;
    vector<Track*> tracks_collection;
   
};
ostream & operator<<(ostream & out, const Tracks & tracks);
#endif /* Tracks_hpp */
