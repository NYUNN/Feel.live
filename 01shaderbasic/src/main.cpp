#include "ofMain.h"
#include "ofApp.h"

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
    
    
    // ofAppGlutWindow window;
    // ofSetupOpenGL(&window, 7680,720,OF_WINDOW);			// <-------- setup the GL context
	// can be OF_WINDOW or OF_FULLSCREEN
    
    // Shader context
    ofGLFWWindowSettings settings;
    settings.setGLVersion(3, 2); //we define the OpenGL version we want to use
    settings.width = w3;
    settings.height = h3;
    ofCreateWindow(settings);
   
    // this kicks off the running of my app
    ofRunApp(new ofApp());

}
