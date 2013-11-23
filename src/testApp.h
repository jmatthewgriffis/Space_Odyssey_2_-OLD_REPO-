#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

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
    
    /*
     M^2 Studios presents:
     
     Space Odyssey 2
     
     the follow-up to the award-winning* Space Odyssey, created by M^3 Studios** in two weeks across Spring 2013 for Major Studio 2.
     
     M^2 Studios is Mauricio Sanchez-Duque and Matt Griffis.
     
     * i.e. played obsessively by classmates)
     ** Mauricio Sanchez-Duque, Michael Kahane and Matt Griffis
     
     */
		
};
