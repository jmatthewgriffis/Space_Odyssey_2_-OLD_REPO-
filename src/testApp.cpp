#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // Matt--maintenance
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofSetCircleResolution( 100 );
    ofEnableAlphaBlending();
    ofBackground( 0 );
    
<<<<<<< HEAD
<<<<<<< HEAD
    
    ship1.setup(ofVec2f( ofGetWindowWidth() / 2 , ofGetWindowHeight() / 2), 2, ofColor( ofColor( 20, 20, 200)));
    
=======
=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
    // Matt
    generation = 0;
    pos = ofGetWindowSize() / 2.0;
    //cam.setDistance(0);
<<<<<<< HEAD
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
}

//--------------------------------------------------------------
void testApp::update(){
    
<<<<<<< HEAD
<<<<<<< HEAD
    ship1.update();

=======
    pos.set( mouseX, mouseY );
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
=======
    pos.set( mouseX, mouseY );
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
}

//--------------------------------------------------------------
void testApp::draw(){
    
<<<<<<< HEAD
<<<<<<< HEAD
    ship1.draw();

=======
=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
    // Matt
    //cam.begin(); //
    //cam.setupPerspective();
    // Draw the galaxy.
    ofPushMatrix();{
        ofSetColor( 255 );
        ofTranslate( ofGetWindowWidth()/2, ofGetWindowHeight() );
        branch( 200 );
    }ofPopMatrix();
    
    drawWings();
    
    
    // Matt
    //cam.end();
<<<<<<< HEAD
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
<<<<<<< HEAD
<<<<<<< HEAD
    if( key == 'q' || key == 'Q'){
        
        ship1.rotateCCWise = true;
        
    }
    
    if( key == 'e' || key == 'E'){
        
        ship1.rotateCWise = true;
    }
    
    if ( key == 'w' || key == 'W'){
        
        ship1.fire = true;
    }
    
    

    
    
=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
<<<<<<< HEAD
<<<<<<< HEAD
    if( key == 'q' || key == 'Q'){
        
        ship1.rotateCCWise = false;
        
    }
    
    if( key == 'e' || key == 'E'){
        
        ship1.rotateCWise = false;
    }
    
    if ( key == 'w' || key == 'W'){
        
        ship1.fire = false;
    }
    
    

=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
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
<<<<<<< HEAD

//--------------------------------------------------------------
void testApp::drawWings() {
    
    // Draw the wings.
    ofPushMatrix();{
        ofSetColor( 255, 0, 0 );
        ofTranslate( pos );
        ofRotate( -115+ofNoise(ofGetElapsedTimef()));
        branch2( 75 );
    }ofPopMatrix();
    ofPushMatrix();{
        ofSetColor( 255, 0, 0 );
        ofTranslate( pos );
        ofRotate( 115+ofNoise(ofGetElapsedTimef()) );
        branch3( 75 );
    }ofPopMatrix();
    //ofRect( pos.x- 25, pos.y, 50, 100 );
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

//--------------------------------------------------------------
=======

//--------------------------------------------------------------
void testApp::drawWings() {
    
    // Draw the wings.
    ofPushMatrix();{
        ofSetColor( 255, 0, 0 );
        ofTranslate( pos );
        ofRotate( -115+ofNoise(ofGetElapsedTimef()));
        branch2( 75 );
    }ofPopMatrix();
    ofPushMatrix();{
        ofSetColor( 255, 0, 0 );
        ofTranslate( pos );
        ofRotate( 115+ofNoise(ofGetElapsedTimef()) );
        branch3( 75 );
    }ofPopMatrix();
    //ofRect( pos.x- 25, pos.y, 50, 100 );
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

//--------------------------------------------------------------
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
void testApp::branch2( float length ) {
    
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

//--------------------------------------------------------------
void testApp::branch3( float length ) {
    
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
