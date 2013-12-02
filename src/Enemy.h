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
    void branch( float length, float _ang1, float _ang2, float _mult = 1, bool _trans = false );
    void drawWings();
    
    ofVec2f pos;
    ofVec2f vel;
    int generation;
    float theta = 30;
};