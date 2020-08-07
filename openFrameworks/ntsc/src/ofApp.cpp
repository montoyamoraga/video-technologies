#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetVerticalSync(true);
    
    originalVideo.load("testing.mov");
    originalVideo.setLoopState(OF_LOOP_NORMAL);
    originalVideo.play();
    
    // pause video for frame by frame
    originalVideo.setPaused(true);
    
    // retrieve pixels array
    ofPixels & pixels = originalVideo.getPixels();
    
    // retrieve original dimensions of video file
    originalWidth = pixels.getWidth();
    originalHeight = pixels.getHeight();
    originalChannels = pixels.getNumChannels();
    
    // adjust the ratio, and make video fit on canvas
    // TODO: center video on canvas
    if ( originalWidth / ofGetWidth() > originalHeight / ofGetHeight()) {
        newWidth = ofGetWidth();
        newRatio = newWidth / originalWidth;
        newHeight = originalHeight * newRatio;
    } else {
        newHeight = ofGetHeight();
        newRatio = newHeight / originalHeight;
        newWidth = originalWidth * newRatio;
    }
    
    // initialize variables for ntsc
    lineSizeX = originalWidth;
    lineSizeY = originalHeight / lineQuantity;
    
    modifiedPixels.allocate(originalWidth, originalHeight, OF_PIXELS_RGB);
    modifiedTexture.allocate(modifiedPixels);
    
    ofSetFrameRate(60);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // update video frame
    originalVideo.update();
    
    // wrap around
    if (originalVideo.getIsMovieDone()) {
        originalVideo.setFrame(0);
    }
    
    // retrieve pixels array
    ofPixels & pixels = originalVideo.getPixels();
    
    // pixels.size() is width * height * channels
    // make i jump on one of the channels
    for (size_t i = 0; i < pixels.size(); i = i + pixels.getNumChannels()) {
        // if pixel is in line, update
        
        if (i >= lineCurrent * originalChannels * originalWidth * lineSizeY && i < (lineCurrent + 1) * originalChannels * originalWidth * lineSizeY) {
            
            modifiedPixels[i + 0] = pixels[i + 0];
            modifiedPixels[i + 1] = pixels[i + 1];
            modifiedPixels[i + 2] = pixels[i + 2];

            
//            for (int channel = 0; i < originalChannels; i ++) {
//                modifiedPixels[i + channel] = pixels[i + channel];
//            }
            
            
        }
    }
    
    modifiedTexture.loadData(modifiedPixels);
    
    
    // update to next line
    lineCurrent = lineCurrent + 2;
    
    // check border condition
    if (lineCurrent >= lineQuantity) {
        // wrap around
        lineCurrent = lineCurrent % lineQuantity;
        
        // if even, change to odd, and viceversa
        lineCurrent = 1 - lineCurrent;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw video
//    originalVideo.draw(0, 0, newWidth, newHeight);
    
    modifiedTexture.draw(0, 0, newWidth, newHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
