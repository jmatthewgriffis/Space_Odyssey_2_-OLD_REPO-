//
//  Enemy.h
//  Space_Odyssey_2
//
//  Created by J. Matthew Griffis on 12/1/13.
//
//

#pragma once
#include "ofMain.h"

// Note from Matt: I created the class and implemented all the branching code to draw the Metroid/Balrog. Mauricio is handling the behavior.

class Enemy {
public:
    
    // Matt
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