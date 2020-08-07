#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    // variables for video playing
    ofVideoPlayer originalVideo;
    int originalWidth;
    int originalHeight;
    int originalChannels;
    float newRatio;
    float newWidth;
    float newHeight;
    
    // variables for ntsc simulation
    int lineQuantity = 64;
    int lineCurrent = 0;
    float lineSizeX = 0;
    float lineSizeY = 0;
    
    ofPixels modifiedPixels;
    ofTexture modifiedTexture;
};
