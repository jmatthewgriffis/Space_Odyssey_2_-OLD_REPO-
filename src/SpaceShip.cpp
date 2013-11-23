//
//  SpaceShip.cpp
//  Space_Odyssey_2
//
//  Created by Mauricio Sanchez Duque on 11/22/13.
//
//

#include "SpaceShip.h"

SpaceShip::SpaceShip( ofVec2f _pos, ofVec2f _vel, ofColor _colorPlayer, ofImage _spaceImage){
    
    pos = _pos;
    vel = _vel;
    colorPlayer = _colorPlayer;
    spaceImage = _spaceImage;
    spaceShipSize = 50;
    rotAngle = 0;
    
}


void SpaceShip::update(){
    
    
}


void SpaceShip::draw(){
    
    
    ofPushMatrix();{
        
        ofTranslate( pos.x, pos.y);
        ofEllipse( 0, 0, size, size);
        
        ofPushMatrix();{
            
            ofTranslate( pos.x, pos.y);
            ofRect( sin(rotAngle) * 50, cos( angle) * 50, 50, 50);
            
            
        }ofPopMatrix();
        
        
    }ofPopMatrix();
    
    
    
}