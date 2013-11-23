//
//  SpaceShip.h
//  Space_Odyssey_2
//
//  Created by Mauricio Sanchez Duque on 11/22/13.
//
//

//Mauricio: I'm going to start migrating the base code from processing make sure that it works in our spaceships and include some new physics.


#pragma once
#include "ofMain.h"

class SpaceShip {
    
    public:
    
    SpaceShip(ofVec2f _pos, ofVec2f _vel, ofColor _colorPlayer, ofImage _spaceImage);
    void draw();
    void update();
    
    
    //These are unique to the players
    ofVec2f pos, vel;
    ofColor colorPlayer;
    ofImage spaceImage;
    
    //Universal Variables
    float spaceShipSize;
    float rotAngle;
        
        
};
