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
    
    generation = 0;
    pos = ofGetWindowSize() / 2.0;
}

void Enemy::update() {
    
}

void Enemy::draw() {

    drawWings();
}

void Enemy::branch2( float length ) {
    
    // Matt--this is copied and modified from Charlie's in-class example.
    
    //ofTranslate( 100, 0 );
    
    ofPushMatrix();
    ofLine( ofVec2f(0,0), ofVec2f(0, -length) );
    ofTranslate( 0, -length );
    
    generation++;
    
    float noise = ofNoise( generation, ofGetElapsedTimef() * 0.1 );
    
    if( length > 2 ){
        ofPushMatrix();{
            ofRotate( -( -10 + theta + noise * 10-5 ) );
            branch2( length * 0.666 );
        }ofPopMatrix();
        
        ofPushMatrix();{
            ofRotate( -( 50 + theta - noise * 10-5 ) );
            branch2( length * 0.666 );
        }ofPopMatrix();
    }
    
    ofPopMatrix();
    
    generation--;
}

void Enemy::branch3( float length ) {
    
    // Matt--this is copied and modified from Charlie's in-class example.
    
    //ofTranslate( 100, 0 );
    
    ofPushMatrix();
    ofLine( ofVec2f(0,0), ofVec2f(0, -length) );
    ofTranslate( 0, -length );
    
    generation++;
    
    float noise = ofNoise( generation, ofGetElapsedTimef() * 0.1 );
    
    if( length > 2 ){
        ofPushMatrix();{
            ofRotate( -10 + theta + noise * 10-5 );
            branch3( length * 0.666 );
        }ofPopMatrix();
        
        ofPushMatrix();{
            ofRotate( 50 + theta - noise * 10-5 );
            branch3( length * 0.666 );
        }ofPopMatrix();
    }
    
    ofPopMatrix();
    
    generation--;
}

void Enemy::drawWings() {
    
    // Matt--this is copied and modified from Charlie's in-class example.
    
    // Draw the wings.
    ofPushMatrix();{
        ofSetColor( 255, 0, 0 );
        ofTranslate( pos );
        ofRotate( -115+ofNoise(ofGetElapsedTimef()));
        branch2( 200 );
    }ofPopMatrix();
    ofPushMatrix();{
        ofSetColor( 255, 0, 0 );
        ofTranslate( pos );
        ofRotate( 115+ofNoise(ofGetElapsedTimef()) );
        branch3( 200 );
    }ofPopMatrix();
}