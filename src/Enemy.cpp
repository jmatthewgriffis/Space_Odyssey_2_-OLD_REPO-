//
//  Enemy.cpp
//  Space_Odyssey_2
//
//  Created by J. Matthew Griffis on 12/1/13.
//
//

#include "Enemy.h"

Enemy::Enemy() {
    
}

void Enemy::setup() {
    
    // Matt
    generation = 0;
    pos = ofGetWindowSize() / 2.0;
    //vel.set( 5, 5 );
    
}

void Enemy::update() {
    
    // Matt
    pos += vel;
}

void Enemy::draw() {

    // Matt
    drawWings();
}

void Enemy::branch( float length, float _ang1, float _ang2, float _mult, bool _trans ) {
    
    // Matt--this is copied and heavily modified from Charlie's in-class example.
    
    if ( _trans ) {
        ofTranslate( 100, 0 );
    }
    
    ofPushMatrix();
        ofLine( ofVec2f(0,0), ofVec2f(0, -length) );
        ofTranslate( 0, -length );
        
//        generation++;
    
        float noise = ofNoise(ofGetElapsedTimef() * 0.1 );
        
        if( length > 2 ){
            ofPushMatrix();{
                ofRotate( ( _ang1 + theta + noise * 10-5 ) * _mult );
                branch( length * 0.666, _ang1, _ang2, _mult, _trans );
            }ofPopMatrix();
            
            ofPushMatrix();{
                ofRotate( ( _ang2 + theta - noise * 10-5 ) * _mult );
                branch( length * 0.666, _ang1, _ang2, _mult, _trans );
            }ofPopMatrix();
        }
    
    ofPopMatrix();
    
//    generation--;
}

void Enemy::drawWings() {
    
    // Matt--this is copied and heavily modified from Charlie's in-class example.
    
    // Draw the wings.
    ofPushMatrix();{
        ofSetColor( 255, 0, 0 );
        ofTranslate( pos );
        ofRotate( -115+ofNoise(ofGetElapsedTimef()));
        branch( 150, -10, 50, -1 );
    }ofPopMatrix();
    ofPushMatrix();{
        ofSetColor( 255, 0, 0 );
        ofTranslate( pos );
        ofRotate( 115+ofNoise(ofGetElapsedTimef()) );
        branch( 150, -10, 50 );
    }ofPopMatrix();
}