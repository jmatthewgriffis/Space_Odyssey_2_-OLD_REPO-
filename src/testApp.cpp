#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // Matt--maintenance
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofSetCircleResolution( 100 );
    ofEnableAlphaBlending();
    ofBackground( 0 );
    //ofHideCursor(); // Doesn't work.
    CGDisplayHideCursor(NULL); // But this does.
    
    // Mauricio
    ship1.setup(ofVec2f( ofGetWindowWidth() / 2 , ofGetWindowHeight() / 2), 2, ofColor( ofColor( 20, 20, 200)));
    
    // Matt
    generation = 0;
    //cam.setDistance(0);
    metroid.setup();
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Mauricio
    ship1.update();
    
    // Matt
    metroid.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Mauricio
    //ship1.draw();

    // Matt
    //cam.begin(); //
    //cam.setupPerspective();
    // Draw the galaxy.
    ofPushMatrix();{
        ofSetColor( 255 );
        ofTranslate( ofGetWindowWidth()/2, ofGetWindowHeight() );
        branch( 200 );
    }ofPopMatrix();
    
    
    // Matt
    metroid.draw();
    //cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // Mauricio
    if( key == 'q' || key == 'Q'){
        
        ship1.rotateCCWise = true;
        
    }
    
    if( key == 'e' || key == 'E'){
        
        ship1.rotateCWise = true;
    }
    
    if ( key == 'w' || key == 'W'){
        
        ship1.fire = true;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    // Mauricio
    if( key == 'q' || key == 'Q'){
        
        ship1.rotateCCWise = false;
        
    }
    
    if( key == 'e' || key == 'E'){
        
        ship1.rotateCWise = false;
    }
    
    if ( key == 'w' || key == 'W'){
        
        ship1.fire = false;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void testApp::branch( float length ) {
    
    // Matt--this is copied and modified from Charlie's in-class example.
    
    ofTranslate( 100, 0 );
    
    ofPushMatrix();
    ofLine( ofVec2f(0,0), ofVec2f(0, -length) );
    ofTranslate( 0, -length );
    
    generation++;
    
    float noise = ofNoise( generation, ofGetElapsedTimef() * 0.1 );
    
    if( length > 2 ){
        ofPushMatrix();{
            ofRotate( -45 + theta + noise * 10-5 );
            branch( length * 0.666 );
        }ofPopMatrix();
        
        ofPushMatrix();{
            ofRotate( 45 + theta - noise * 10-5 );
            branch( length * 0.666 );
        }ofPopMatrix();
    }
    
    ofPopMatrix();
    
    generation--;
}
