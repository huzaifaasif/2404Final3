//
//  Recording.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-24.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Recording_hpp
#define Recording_hpp

#include <stdio.h>
#include <string>
#include "Track.hpp"
#include <vector>
////add -r album_id title producer year

using namespace std;

class Recording{
public:
    Recording(int albumID, string title, string artist, string producer, int year);
    ~Recording();
    
    string toString() const;
    
    int getAlbumID();
    
    
    //getter
    class Track *getTrackPointer(int index);
    
    
    //setter
    void addTrackPtr(class Track *Track);
    Track *createNewPtr();
    
    
private:
    string title, artist, producer;
    int year, albumID;
    class Track *ptr_track;
    
    vector<Track*> trackPtrCollection;
    //Track *ptr;
};

#endif /* Recording_hpp */
