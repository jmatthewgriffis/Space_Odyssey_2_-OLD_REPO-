#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    { // Matt
        killFrameRate = false; // Turn on the enemy and background, watch the framerate drop.
        // Maintenance
        ofSetVerticalSync( true );
        ofSetFrameRate( 60 );
        ofSetCircleResolution( 100 );
        ofEnableAlphaBlending();
        ofBackground( 0 );
        //ofHideCursor(); // Doesn't work.
        CGDisplayHideCursor(NULL); // But this does.
        generation = 0;
        //cam.setDistance(0);
        metroid.setup();
    }
    
    
    { // Mauricio
        ship1.setup(ofVec2f( ofGetWindowWidth() / 2 , ofGetWindowHeight() / 2), 2, ofColor( ofColor( 20, 20, 200)));
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    { // Mauricio
        ship1.update();
    }
    
    
    { // Matt
        metroid.update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    { // Matt
        //cam.begin(); //
        //cam.setupPerspective();
        if ( killFrameRate ) drawGalaxy();
        if ( killFrameRate ) metroid.draw();
    }
    
    { // Mauricio
        ship1.draw();
    }
    
    { // Matt
        //cam.end();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    { // Mauricio
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
    
    { // Matt
        if ( key == '1' ) {
            killFrameRate = !killFrameRate;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    { // Mauricio
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
void testApp::branch( float length, float _ang1, float _ang2, float _mult, bool _trans ) {
    
    // Matt--this is copied and modified from Charlie's in-class example.
    
    { // Matt
        ofTranslate( 100, 0 );
        
        ofPushMatrix();
        ofLine( ofVec2f(0,0), ofVec2f(0, -length) );
        ofTranslate( 0, -length );
        
        generation++;
        
        float noise = ofNoise( generation, ofGetElapsedTimef() * 0.1 );
        
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
        
        generation--;
    }
}

//--------------------------------------------------------------
void testApp::drawGalaxy() {
    
    { // Matt
        // Draw the galaxy.
        ofPushMatrix();{
            ofSetColor( 255 );
            ofTranslate( ofGetWindowWidth()/2, ofGetWindowHeight() );
            branch( 200, -45, 45, 1, true );
        }ofPopMatrix();
    }
}