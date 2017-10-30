 #include "ofApp.h"
#include "ofxRipples.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    //    cout << ofGetWindowWidth();
    //    cout << ofGetWindowHeight();
    
  
    bInfoText = true;
    bRipple = false;
    bHide = false;
    
    
   

   // float distance = settings.getValue("settings:distance", 0);
    
    // GUI
    gui.setup();
    gui.add(rippleSizeX.setup("sizeX", 20, 10, 100));
    gui.add(rippleSizeY.setup("sizeY", 20, 10, 100));
    gui.add(rippleDistance.setup("distance", 2, 0, 10));
    gui.add(rippleDamping.setup("damping", 0.995, 0.900, 0.999));
    gui.add(frameRate.setup("frameRate", true));
    gui.add(ww.setup("ScreenSizeX", 1920, 1920, 11520));
    gui.loadFromFile("settings.xml");

    hh = ww*0.08475;
    ofSetWindowShape(ww, hh);
    red.allocate(ww, hh);
    cout << hh;
    
    
    //settings.loadFile("settings.xml");

    // Xml Setting

    
  
  
    
    
    
    for (int i = 0; i < colorNum ;i++){
        xpos.push_back(-10);
        ypos.push_back(-10);
//    xpos.push_back(10);
//    ypos.push_back(10);
    }
    
    //rips.push_back(red);
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
        red.begin();
        ofFill();
        //ofSetColor(ofNoise( ofGetFrameNum() ) * 255 * 5, 255);
        ofSetColor(255,0,0);
        ofDrawEllipse(xpos[0], ypos[0], rippleSizeX, rippleSizeY);
    
        ofSetColor(0,0,255);
        ofDrawEllipse(xpos[1], ypos[1], rippleSizeX, rippleSizeY);
    
        ofSetColor(0,255,0);
        ofDrawEllipse(xpos[2], ypos[2], rippleSizeX, rippleSizeY);

        red.end();
        red.update();

    
//    blue.begin();
//    ofFill();
//    //ofSetColor(ofNoise( ofGetFrameNum() ) * 255 * 5, 255);
//    ofSetColor(0,0,255);
//    ofDrawEllipse(xpos[1], ypos[1], rippleSizeX, rippleSizeY);
//    blue.end();
//    blue.update();
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(0); // no change
    
    red.draw(0, hh*3/5, ww, hh*2/5);
    
    red.distance = rippleDistance;
    red.damping = rippleDamping;
    
//    blue.draw(0);
//    blue.distance = rippleDistance;
//    blue.damping = rippleDamping;
    
    if(!bHide) {
        gui.draw();
        
        stringstream ss;
        ss << "Framerate: " << ofToString(ofGetFrameRate(),0) << "\n";
        ofDrawBitmapString(ss.str().c_str(), 250, 20);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'h'){ // hide gui
        bHide = !bHide;
    } else if (key == 'r'){
        xpos[0] = ofRandom(0, ww);
        ypos[0] = hh/2 + ofRandom(0, hh*2/5);
    } else if (key == 'b'){
        xpos[1] = ofRandom(0, ww);
        ypos[1] = hh/2 + ofRandom(0, hh*2/5);
    } else if (key == 'g'){
        xpos[2] = ofRandom(0, ww);
        ypos[2] = hh/2 + ofRandom(0, hh*2/5);
    } else if (key == 'q'){ // quit
        for (int i = 0; i < colorNum ;i++){
            xpos[i] = -10;
            ypos[i] = -10;
        }
    }
    if (key == '1') {
        red.distance = 0;
        cout << "1";
    }
    
    if(key == 's') {
        gui.saveToFile("settings.xml");
    }
    if(key == 'l') {
        gui.loadFromFile("settings.xml");
    }
}

void testApp::generateRip(int x, int y, float x1, float y1){
  
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
//    red.damping = ofMap(y, 1, ofGetHeight(), 0.9, 0.999, false);
//    rippleDistance = ofMap(x, 1, ofGetWidth(), 1.0, 10.0, false);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
