#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void add(ofPoint l);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
};

class leaf {
public:
    leaf();
    void setup();
    void update();
    
    void draw();
    ofPoint loc;
   
    
    ofColor color;
    ofFbo fbo;
private:
    
    float sTime;	// start time
    float sWeight;      // scale weight
    float fallSpeed;	// how fast to fall
    float fallWiggle;   // back and forth
    float a;
    
    
    float dScale;
    float dScaleX;	// delta scales
    float dScaleY;
    float dScaleZ;
    float rX;		// rotate angles
    float rY;
    float rZ;
    
    float aX;		// rotate angles
    float aY;
    float aZ;
    
    float vX;		// rotate angles
    float vY;
    float vZ;
    
    float  color1;
    float color2;
    float color3;
    

};

