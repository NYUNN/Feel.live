#include "ofApp.h"
#include "ofxRipples.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Graphic setting
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofSetWindowShape(w, h);
    
    bInfoText = true;
    bRipple = false;
    
    red.allocate(w, h);
    blue.allocate(w, h);
    
    // GUI
    gui.setup();
    gui.add(rippleSizeX.setup("sizeX", 20, 10, 100));
    gui.add(rippleSizeY.setup("sizeY", 20, 10, 100));
    gui.add(rippleDistance.setup("distance", 2, 1, 10));
    gui.add(rippleDamping.setup("damping", 0.995, 0.900, 0.999));
    gui.add(frameRate.setup("frameRate", true));
    
    // Initial position
    for (int i = 0; i < colorNum ;i++){
        xpos.push_back(-10);
        ypos.push_back(-10);
    }
    
    
    // socketIO part
    isConnected = false;
    address = "http://67.205.153.66:9999";
    status = "not connected";
    socketIO.setup(address);
    /*
     * You can also pass a query parameter at connection if needed.
     */
    // std::map<std::string,std::string> query;
    // query["token"] = "hello";
    // socketIO.setup(address, query);
    
    ofAddListener(socketIO.notifyEvent, this, &ofApp::gotEvent);
    ofAddListener(socketIO.connectionEvent, this, &ofApp::onConnection);
 

    // set color list
    colors = new ofColor[9];
    
    // initial value
    colors[0].r = 255;
    colors[0].g = 255;
    colors[0].b = 255;
    colors[0].a = 150;
    
    
    // joy
    colors[1].r = 255;
    colors[1].g = 238;
    colors[1].b = 51;
    
    // trust
    colors[2].r = 153;
    colors[2].g = 255;
    colors[2].b = 51;
    
    // fear
    colors[3].r = 55;
    colors[3].g = 255;
    colors[3].b = 187;
    
    // surprise
    colors[4].r = 51;
    colors[4].g = 221;
    colors[4].b = 255;
    
    // sadness
    colors[5].r = 85;
    colors[5].g = 51;
    colors[5].b = 255;
    
    // disgust
    colors[6].r = 221;
    colors[6].g = 51;
    colors[6].b = 255;
    
    // anger
    colors[7].r = 255;
    colors[7].g = 51;
    colors[7].b = 85;
    
    // anticipation
    colors[8].r = 255;
    colors[8].g = 152;
    colors[8].b = 51;
    
}

void ofApp::onConnection () {
    isConnected = true;
    bindEvents();
}

void ofApp::bindEvents () {
    std::string serverEventName = "server-event";
    socketIO.bindEvent(serverEvent, serverEventName);
    ofAddListener(serverEvent, this, &ofApp::onServerEvent);
    //
    //    std::string pingEventName = "pingy";
    //    socketIO.bindEvent(pingEvent, pingEventName);
    //    ofAddListener(pingEvent, this, &ofApp::onPingEvent);
    //
    //    std::string nspingEventName = "nsping";
    //    socketIO.bindEvent(nspingEvent, nspingEventName, "nsp");
    //    ofAddListener(nspingEvent, this, &ofApp::onNSPingEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    red.begin();
    ofFill();
    //ofSetColor(255,0,0);
   // ofDrawEllipse(xpos[0], ypos[0], rippleSizeX, rippleSizeY);
    
    for (int i = 0; i < colorNum ; i++){
        ofSetColor(colors[i+1]);
        ofDrawEllipse(xpos[i], ypos[i], rippleSizeX, rippleSizeY);
    }

    red.end();
    red.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofBackground(0); // no change
    red.draw(0,0, w, h);
    red.distance = rippleDistance;
    red.damping = rippleDamping;
    
    if(!bHide) {
        gui.draw();
        
        stringstream ss;
        ss << "Framerate: " << ofToString(ofGetFrameRate(),0) << "\n";
        ofDrawBitmapString(ss.str().c_str(), 250, 20);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f' :
            ofToggleFullscreen();
            break;
    }
    
    if(key == 'h'){ // hide gui
        bHide = !bHide;
    }
  
    if (key == 'q'){ // quit
        for (int i = 0; i < colorNum ;i++){
            xpos[i] = -10;
            ypos[i] = -10;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::gotEvent(string& name) {
    status = name;
}

//--------------------------------------------------------------
void ofApp::onServerEvent (ofxSocketIOData& data) {
    
    int gotData = data.getIntValue("intData");
    cout << gotData << endl;
    
    if (gotData == 1){
        xpos[0] = ofRandom(0, w);
        ypos[0] = ofRandom(0, h);
    } else if (gotData == 2){
        xpos[1] = ofRandom(0, w);
        ypos[1] = ofRandom(0, h);
    } else if (gotData == 3){
        xpos[2] = ofRandom(0, w);
        ypos[2] = ofRandom(0, h);
    } else if (gotData == 4){
        xpos[3] = ofRandom(0, w);
        ypos[3] = ofRandom(0, h);
    } else if (gotData == 5){
        xpos[4] = ofRandom(0, w);
        ypos[4] = ofRandom(0, h);
    } else if (gotData == 6){
        xpos[5] = ofRandom(0, w);
        ypos[5] = ofRandom(0, h);
    } else if (gotData == 7){
        xpos[6] = ofRandom(0, w);
        ypos[6] = ofRandom(0, h);
    } else if (gotData == 8){
        xpos[7] = ofRandom(0, w);
        ypos[7] = ofRandom(0, h);
    }
    
    //    ofLogNotice("ofxSocketIO", data.getStringValue("stringData"));
    //    ofLogNotice("ofxSocketIO", ofToString(data.getIntValue("intData")));
    //    ofLogNotice("ofxSocketIO", ofToString(data.getFloatValue("floatData")));
    //    ofLogNotice("ofxSocketIO", ofToString(data.getBoolValue("boolData")));
    //
    //    ofxSocketIOData nested = data.getNestedValue("nested");
    //    ofLogNotice("ofxSocketIO", ofToString(nested.getStringValue("hello")));
    
    
}

void ofApp::onPingEvent (ofxSocketIOData& data) {
    ofLogNotice("got ping");
    
    //    std::string pong = "pongy";
    //    std::string param = "foo";
    //    socketIO.emit(pong, param);
    /*
     * You can also emit without param
     */
    // socketIO.emit(pong);
}

void ofApp::onNSPingEvent (ofxSocketIOData& data) {
    //    ofLogNotice("ofxSocketIO", "nsping");
    //    std::string pong = "nspong";
    //    std::string param = "foo";
    //    std::string nsp = "nsp";
    //    socketIO.emit(pong, param, nsp);
}
