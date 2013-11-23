//
//  SpaceShip.cpp
//  Space_Odyssey_2
//
//  Created by Mauricio Sanchez Duque on 11/22/13.
//
//

#include "SpaceShip.h"


void SpaceShip::setup(ofVec2f _pos, float _vel, ofColor _colorPlayer/*, ofImage _spaceImage*/){
    
    pos = _pos;
    vel = _vel;
    colorPlayer = _colorPlayer;
    /*spaceImage = _spaceImage;*/
    spaceShipSize = 50;
    rotAngle = 0;
    size = 150;
    inc = 20;
    rotAngleInc = 1 * 0.15;
    
    
}


void SpaceShip::update(){
    
    //We check the propeller drawn at a point on the ellipse's circumference based on the angle, so to rotate we change the angle
    if( rotateCCWise == true){
        
        rotAngle += rotAngleInc;
    }
    
    if ( rotateCWise == true){
        
        rotAngle -= rotAngleInc;
    }
    
    //If the angle has reached its limit we reset it
    if( rotAngle > 2 * PI){
        
        rotAngle = 0;
    }
    
    if( rotAngle < 0 ){
        
        rotAngle = 2 * PI;
    }
    
    //This determines the 8 different angles at which
    if ((rotAngle < (PI/inc) || rotAngle > (PI*2)-(PI/inc)) ||
        (rotAngle < PI+(PI/inc) && rotAngle > PI-(PI/inc)) ||
        (rotAngle < (PI/2+PI/inc) && rotAngle > (PI/2-PI/inc)) ||
        (rotAngle < (3*PI/2+PI/inc) && rotAngle > (3*PI/2-PI/inc))){
        notAngled = false;
        
    }else{
        notAngled = false;
    }
    
    //If accelerating we change the velocity
    if( addToSpeed == true){
        
        if ( vel <= 4 * velModifier){
            
            velModifier += ( 0.25 * 1/60);
        }
    } else {
        
        velModifier = 0.75;
    }
    
    //Here we check the motion
    if( fire == true){
        
        //Move straight up
        if( rotAngle < (PI/inc) || rotAngle > ( PI * 2) - (PI / inc) ){
            
            pos.y -= vel;
            
        }
        
        //Move straight down
        if( rotAngle < PI + (PI/inc) && rotAngle > PI -( PI / inc) ) {
            
            pos.y += vel;
            
        }
        
        //Move straight left
        if( rotAngle < ( PI/2 + PI/inc) && rotAngle > (PI/2 -PI/inc)){
            
            pos.x -= vel;
        }
        
        //Move straight right
        if( rotAngle < ( 3 * PI/ 2 + PI/inc) && rotAngle > (3 * PI /2 - PI/ inc)){
            
            pos.x += vel;
        }
        
        
        if ( notAngled == false){
            
            if( rotAngle < PI / 2){
                
                pos.y -= vel;
                pos.x -= vel;
                
            }else if( rotAngle >= PI /2 && rotAngle < PI){
                
                pos.y += vel;
                pos.x -= vel;
                
            }else if( rotAngle >= PI && rotAngle < 3 * PI / 2){
                
                pos.y += vel;
                pos.x += vel;
                
            }else if( rotAngle >= 3 * PI / 2 && rotAngle < 2 * PI){
                
                pos.y -= vel;
                pos.x += vel;
                
            }
        }else {
            
            addToSpeed = false;
        }
        
    }
    
}


void SpaceShip::draw(){
    
    
    ofSetColor( colorPlayer);
    ofPushMatrix();{
      //        ofTranslate( pos.x, pos.y);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofEllipse( pos.x, pos.y, size, size);
        ofPushMatrix();{
            
            ofTranslate( pos.x, pos.y);

            ofSetColor( 255);
            ofRect( sin(rotAngle) * 50, cos( rotAngle) * 50, 50, 50);            
            
        }ofPopMatrix();
        
        
    }ofPopMatrix();
    
    
    
}