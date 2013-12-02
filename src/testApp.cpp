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
        
        float offset = 100;
        for ( int i = 0; i < 4; i++ ) {
            SpaceShip tmp;
            tmp.setup( ofVec2f( offset, offset ), ofColor( ofColor( 20, 20, 200 ) ) );
            shipList.push_back( tmp );
        }
        // Individual pos
        shipList[ 1 ].pos.set( ofGetWindowWidth() - offset, offset );
        shipList[ 2 ].pos.set( offset, ofGetWindowHeight() - offset );
        shipList[ 3 ].pos.set( ofGetWindowWidth() - offset, ofGetWindowHeight() - offset );
        // Individual color
        shipList[ 1 ].colorPlayer = ofColor( 200, 20, 20 );
        shipList[ 2 ].colorPlayer = ofColor( 100, 80, 20 );
        shipList[ 3 ].colorPlayer = ofColor( 0, 255, 20 );
    }
    
    
    { // Mauricio
        //ship1.setup(ofVec2f( ofGetWindowWidth() / 2 , ofGetWindowHeight() / 2), 2, ofColor( ofColor( 20, 20, 200)));
        //        enemyFbo.allocate( 0 , 0 );
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    { // Mauricio
        //ship1.update();
    }
    
    
    { // Matt
        metroid.update();
        
        for ( int i = 0; i < shipList.size(); i++ ) {
            shipList[ i ].update();
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    {//Mauricio
        //    enemyFbo.begin();
        //        ofSetColor(255, 255, 255);
        //        ofClear(255, 255, 255, 0);
        { // Matt
            //cam.begin(); //
            //cam.setupPerspective();
            if ( killFrameRate ) drawGalaxy();
            if ( killFrameRate ) metroid.draw();
        }
        //    enemyFbo.end();
        enemyFbo.draw( ofGetWindowWidth() , ofGetWindowHeight());
    }
    
    { // Mauricio
        //ship1.draw();
    }
    
    { // Matt
        for ( int i = 0; i < shipList.size(); i++ ) {
            shipList[ i ].draw();
        }
        //cam.end();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    /*
     // Matt says: didn't use a Switch in Processing.
     { // Mauricio
     if( key == 'q' || key == 'Q'){
     
     //ship1.rotateCCWise = true;
     shipList[ 0 ].rotateCCWise = true; // Matt
     }
     
     if( key == 'e' || key == 'E'){
     
     //ship1.rotateCWise = true;
     shipList[ 0 ].rotateCWise = true; // Matt
     }
     
     if ( key == 'w' || key == 'W'){
     
     //ship1.fire = true;
     shipList[ 0 ].fire = true; // Matt
     }
     }
     */
    
    { // Matt
        
        switch( key ) {
                
                // Player controls
                
                // Player One
            case 'q':
            case 'Q':
                shipList[ 0 ].rotateCCWise = true;
                break;
                
            case 'e':
            case 'E':
                shipList[ 0 ].rotateCWise = true;
                break;
                
            case 'w':
            case 'W':
                shipList[ 0 ].fire = true;
                break;
                
                // Player Two
            case 'j':
            case 'J':
                shipList[ 1 ].rotateCCWise = true;
                break;
                
            case 'l':
            case 'L':
                shipList[ 1 ].rotateCWise = true;
                break;
                
            case 'k':
            case 'K':
                shipList[ 1 ].fire = true;
                break;
                
                // Player Three
            case 'v':
            case 'V':
                shipList[ 2 ].rotateCCWise = true;
                break;
                
            case 'n':
            case 'N':
                shipList[ 2 ].rotateCWise = true;
                break;
                
            case 'b':
            case 'B':
                shipList[ 2 ].fire = true;
                break;
                
                // Player Four
            case OF_KEY_LEFT:
                shipList[ 3 ].rotateCCWise = true;
                break;
                
            case OF_KEY_RIGHT:
                shipList[ 3 ].rotateCWise = true;
                break;
                
            case OF_KEY_DOWN:
                shipList[ 3 ].fire = true;
                break;
                
            { // Debug
                
                // Turn the galaxy and enemy on and off.
            case '1':
                killFrameRate = !killFrameRate;
                break;
                
                // Reset
            case 'r':
            case 'R':
                shipList.clear();
                setup();
                
            } // End debug.
        }
    } // End Matt
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    /*
     { // Mauricio
     if( key == 'q' || key == 'Q'){
     
     //ship1.rotateCCWise = false;
     shipList[ 0 ].rotateCCWise = false; // Matt
     
     }
     
     if( key == 'e' || key == 'E'){
     
     //ship1.rotateCWise = false;
     shipList[ 0 ].rotateCWise = false; // Matt
     }
     
     if ( key == 'w' || key == 'W'){
     
     //ship1.fire = false;
     shipList[ 0 ].fire = false; // Matt
     }
     }
     */
    
    { // Matt
        
        switch( key ) {
                
                // Player controls
                
                // Player One
            case 'q':
            case 'Q':
                shipList[ 0 ].rotateCCWise = false;
                break;
                
            case 'e':
            case 'E':
                shipList[ 0 ].rotateCWise = false;
                break;
                
            case 'w':
            case 'W':
                shipList[ 0 ].fire = false;
                break;
                
                // Player Two
            case 'j':
            case 'J':
                shipList[ 1 ].rotateCCWise = false;
                break;
                
            case 'l':
            case 'L':
                shipList[ 1 ].rotateCWise = false;
                break;
                
            case 'k':
            case 'K':
                shipList[ 1 ].fire = false;
                break;
                
                // Player Three
            case 'v':
            case 'V':
                shipList[ 2 ].rotateCCWise = false;
                break;
                
            case 'n':
            case 'N':
                shipList[ 2 ].rotateCWise = false;
                break;
                
            case 'b':
            case 'B':
                shipList[ 2 ].fire = false;
                break;
                
                // Player Four
            case OF_KEY_LEFT:
                shipList[ 3 ].rotateCCWise = false;
                break;
                
            case OF_KEY_RIGHT:
                shipList[ 3 ].rotateCWise = false;
                break;
                
            case OF_KEY_DOWN:
                shipList[ 3 ].fire = false;
                break;
        } // End Matt
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