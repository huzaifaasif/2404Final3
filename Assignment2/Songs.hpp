//
//  Songs.hpp
//  Assignment2
//
//  Created by Huzaifa Asif on 2017-10-19.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef Songs_hpp
#define Songs_hpp

#include <stdio.h>
#include <vector>
#include "Song.hpp"
#include "Songs.hpp"
#include "Track.hpp"
#include "Tracks.hpp"

//storing collection of Song objects
class Songs{
public:
    Songs();
    ~Songs();
    
    Song *findByID(int anID);   //unnecessary FOR NOW
    void add(Song * aSong);
    void remove(Song & aSong);
    
    void getData(string &input);
    void printOn(ostream & out) const;
    
    void tracksToRespectiveSongs(Tracks *tracks, int count);
    
    //remove data
    void removeData(string input);
    
private:
    
    vector<Song*> collection;   //pointer to Song object
    vector<Song*>::iterator findPosition(Song & aSong);
};

ostream & operator<<(ostream & out, const Songs & Songs);
#endif /* Songs_hpp */
