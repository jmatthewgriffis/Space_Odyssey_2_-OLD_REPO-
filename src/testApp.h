#pragma once

/*
 
 A NOTE FROM MATT--
 
 M^2 Studios presents:
 
 SPACE ODYSSEY 2: MICHAEL KAHANE'S DEFECTION
 
 the follow-up to the award-winning* Space Odyssey, created by M^3 Studios** in two weeks across Spring 2013 for Major Studio 2.
 
 M^2 Studios is Mauricio Sanchez-Duque and Matt Griffis.
 
 * i.e. played obsessively by classmates)
 ** Mauricio Sanchez-Duque, Michael Kahane and Matt Griffis
 
 */

#include "ofMain.h"
#include "SpaceShip.h"

class testApp : public ofBaseApp{
<<<<<<< HEAD
<<<<<<< HEAD

	public:
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        SpaceShip ship1;
		
=======
=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //----------NEW STUFF STARTS HERE----------
    
    // Matt
    ofVec2f pos;
    //ofEasyCam cam;
    // For branching:
    void branch( float length );
    void branch2( float length );
    void branch3( float length );
    void drawWings();
    float theta = 30;
    int generation;
<<<<<<< HEAD
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
=======
>>>>>>> ab71cc0e191dde85b04f2c35cf37cd0dcbb682c6
};
