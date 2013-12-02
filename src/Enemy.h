//
//  Enemy.h
//  Space_Odyssey_2
//
//  Created by J. Matthew Griffis on 12/1/13.
//
//

#pragma once

#include "ofMain.h"

class Enemy {
public:
    Enemy();
    void setup();
    void update();
    void draw();
    void branch2( float length );
    void branch3( float length );
    void drawWings();
    
    ofVec2f pos;
    ofVec2f vel;
    int generation;
    float theta = 30;
};