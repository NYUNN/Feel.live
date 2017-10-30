#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    // Full resolution
    int w1 = 11520;
    int h1 = 1080;
    
    // Middle resolution
    int w2 = 7680;
    int h2 = 720;
    
    // Only macbook
    int w3 = 1920;
    int h3 = 162;
    
    ofAppGlutWindow window;
    ofSetupOpenGL(&window, w3,h3, OF_WINDOW);			// <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    
    // Multi-display mode
//    ofGLFWWindowSettings settings;
//    settings.width = w3;
//    settings.height = h3;
//    settings.windowMode = OF_FULLSCREEN;
//    settings.multiMonitorFullScreen = true;
//    ofCreateWindow(settings);
    
    ofRunApp( new testApp());

}
