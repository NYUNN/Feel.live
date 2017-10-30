#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "ofxSocketIO.h"
#include "ofxSocketIOData.h"
#include "ofxRipples.h"
#include "ofxBounce.h"
#include "ofxGUI.h"
#include "ofxFX.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    void gotEvent(std::string& name);
    void onServerEvent(ofxSocketIOData& data);
    void onPingEvent(ofxSocketIOData& data);
    void onNSPingEvent(ofxSocketIOData& data);
    
    ofxSocketIO socketIO;
    
    bool isConnected;
    void onConnection();
    void bindEvents();
    ofEvent<ofxSocketIOData&> serverEvent;
    ofEvent<ofxSocketIOData&> pingEvent;
    ofEvent<ofxSocketIOData&> nspingEvent;
    
    std::string address;
    std::string status;
    
    ofVideoGrabber vidGrabber;
    int camWidth;
    int camHeight;
    
    ofColor *colors;
    ofColor selectedColor;
    int selectedEmotion;
    
    // Graphic Side @YUN
    float w = ofGetWindowWidth();
    float h = ofGetWindowHeight();
    
    ofxRipples  red, blue;
    ofxBounce   bounce;
    
    bool bInfoText;
    bool bHide;
    bool bRipple;
    
    ofxFloatSlider rippleSizeX;
    ofxFloatSlider rippleSizeY;
    ofxFloatSlider rippleDistance;
    ofxFloatSlider rippleDamping;
    
    ofxToggle frameRate;
    ofxPanel gui;
    
    int colorNum = 8;
    
    // ARRAYS
    vector <int> xpos;
    vector <int> ypos;
    
};
