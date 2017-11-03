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
    int h3 = 180;
    
//    ofAppGlutWindow window;
//    ofSetupOpenGL(&window, w1,h1, OF_FULLSCREEN);            // <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    
    // Multi-display mode
    ofGLFWWindowSettings settings;
    settings.width = w1;
    settings.height = h1;
    settings.windowMode = OF_FULLSCREEN;
    settings.multiMonitorFullScreen = true;
    ofCreateWindow(settings);
    
    ofRunApp( new ofApp());

}
