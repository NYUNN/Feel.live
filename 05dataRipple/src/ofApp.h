#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "ofxSocketIO.h"
#include "ofxSocketIOData.h"
#include "ofxRipples.h"
#include "ofxGUI.h"
#include "ofxFX.h"
#include "particle.hpp"
#include "ofxXmlSettings.h"
#include "blob.h"





class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    // socketIO part
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
    
    // Video part
    ofVideoGrabber vidGrabber;
    int camWidth;
    int camHeight;
    
    ofColor *colors;
    ofColor selectedColor;
    int selectedEmotion;
    
    // Graphic Side @YUN
    int screenHeight;
    ofxIntSlider screenWidth;

    
    ofxRipples  rip;
    
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
    
    // BLOB ARRAYS
    vector <int> xpos;
    vector <int> ypos;
    vector <blob> blobs;
    
    // TEXT PARTICLE
    vector <particle> particles;
    vector <string> words;
    vector <string> letters;
    
    int wordNum;
    int letterNum;
    
    float velocityValue;
    ofEasyCam cam;
    
    bool rainForce;
    bool textParticleOn;
    
    // VIDEO PLAYER
    ofAVFoundationPlayer vid_calm;

    bool bVideo;
    bool isPlayed;
    
    // SOUND PLAYER
    ofSoundPlayer  sound1;
    ofSoundPlayer  sound2;
    
    // Title & url part
    ofTrueTypeFont url;
    bool urlShow;
};
