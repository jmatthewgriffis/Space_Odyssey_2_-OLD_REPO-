#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    // Matt--maintenance
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofSetCircleResolution( 100 );
    ofBackground( 0 );
    
    
    ship1.setup(ofVec2f( ofGetWindowWidth() / 2 , ofGetWindowHeight() / 2), 2, ofColor( ofColor( 20, 20, 200)));
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    ship1.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ship1.draw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
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
