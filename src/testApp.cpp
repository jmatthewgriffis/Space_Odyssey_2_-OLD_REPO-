#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    // Matt--maintenance
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofSetCircleResolution( 100 );
    ofBackground( 0 );
    
    // Matt
    generation = 0;
    pos = ofGetWindowSize() / 2.0;
    //cam.setDistance(0);
}

//--------------------------------------------------------------
void testApp::branch( float length ) {
    
    // Matt--this is copied and modified from Charlie's in-class example.
    
//    ofPushMatrix();
    
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
        
//    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    // Matt
    //cam.begin(); //
    //cam.setupPerspective();
    
    ofPushMatrix();{
        ofTranslate( ofGetWindowWidth()/2, ofGetWindowHeight() );
        branch( 200 );
    }ofPopMatrix();
    
    
    // Matt
    //cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
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
