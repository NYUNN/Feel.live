#pragma once

#include "ofMain.h"
#include "ofxRipples.h"
#include "ofxBounce.h"
#include "ofxGUI.h"
#include "ofxXmlSettings.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed   (int key);
    void keyReleased  (int key);
    void mouseMoved   (int x, int y );
    void mouseDragged (int x, int y, int button);
    void mousePressed (int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void generateRip  (int x, int y, float x1, float y1);

    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    float w = ofGetWindowWidth();
    float h = ofGetWindowWidth()*0.08475;
    
    
    ofxRipples  red, blue;
    ofxBounce   bounce;
    ofxXmlSettings settings;

    
    bool bInfoText;
    bool bHide;
    bool bRipple;
    
    ofxFloatSlider rippleSizeX;
    ofxFloatSlider rippleSizeY;
    ofxFloatSlider rippleDistance;
    ofxFloatSlider rippleDamping;
    ofxFloatSlider ww;
    
    ofxToggle frameRate;
    ofxPanel gui;
    
    // COLORS
    int colorNum = 3;
    int hh;
    ofColor *colors;
    
    // ARRAYS
    vector <int> xpos;
    vector <int> ypos;
};
