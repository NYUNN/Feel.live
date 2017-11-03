#include "ofApp.h"
#include "ofxRipples.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // GRAPHIC SETTING
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    
    // BOOLEAN SETTING
    bInfoText = true;
    bRipple = true;
    bVideo = false;
    isPlayed = false;
    
    
    // GUI
    gui.setup();
    gui.add(rippleSizeX.setup("sizeX", 20, 1, 100));
    gui.add(rippleSizeY.setup("sizeY", 20, 1, 100));
    gui.add(rippleDistance.setup("distance", 2, 1, 10));
    gui.add(rippleDamping.setup("damping", 0.995, 0.900, 0.999));
    gui.add(screenWidth.setup("screenWidth", 1280, 1280, 11560));
    gui.loadFromFile("settings.xml");
    screenHeight = screenWidth*0.08475;
    ofSetWindowShape(screenWidth, screenHeight);
    
    // Initial position
//    for (int i = 0; i < colorNum ;i++){
//        xpos.push_back(-10);
//        ypos.push_back(-10);
//    }
    
    
    rip.allocate(screenWidth, screenHeight);
    
    
    // socketIO part
    isConnected = false;
        address = "http://67.205.153.66:9999";
//    address = "http://localhost:9999";
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
    colors[1].r = 248;
    colors[1].g = 198;
    colors[1].b = 51;
    
    // trust
    colors[2].r = 178;
    colors[2].g = 187;
    colors[2].b = 58;
    
    // fear
    colors[3].r = 10;
    colors[3].g = 108;
    colors[3].b = 67;
    
    // surprise
    colors[4].r = 6;
    colors[4].g = 128;
    colors[4].b = 157;
    
    // sadness
    colors[5].r = 118;
    colors[5].g = 59;
    colors[5].b = 12;
    
    // disgust
    colors[6].r = 145;
    colors[6].g = 30;
    colors[6].b = 71;
    
    // anger
    colors[7].r = 186;
    colors[7].g = 39;
    colors[7].b = 58;
    
    // anticipation
    colors[8].r = 216;
    colors[8].g = 97;
    colors[8].b = 43;
    // TEXT PARTICLE
    
    // keycode init
    textParticleOn = false;
    rainForce = false;
    
    // particle init
    wordNum = 700;
    letterNum = 3000;
    velocityValue = 20;
    
    words = {"sad", "mad", "scared", "peaceful", "powerful", "confused", "rejected", "helpless", "submissive", "insecure","anxious", "excited", "sensuous", "energetic", "cheerful" "creative", "hopeful", "aware", "proud", "respected", "appreciated", "important", "faithful", "nurturing", "trusting", "loving", "intimate", "thoughtful", "content", "tired", "bored", "lonely", "depressed", "ashamed", "guilty", "hurt", "hostile", "angry", "selfish", "hateful", "critical"};
    
    letters = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
    
    for (int i = 0; i < wordNum; i++){
        particle myParticle;
        myParticle.setLetterPos = false;
        myParticle.selectedWord = words[ofRandom(words.size())];
        float vx = ofRandom(-velocityValue*14, velocityValue*18);
        float vy = ofRandom(-velocityValue*6,velocityValue*6);
        float vz = ofRandom(velocityValue*7,velocityValue*10);
        myParticle.setInitialCondition(ofGetWindowSize()[0]/2,ofGetWindowHeight()/2, -7000, vx, vy, vz);
        particles.push_back(myParticle);
    }
    
    for (int i = 0; i < letterNum; i++){
        particle myParticle;
        myParticle.setLetterPos = false;
        myParticle.selectedWord = letters[ofRandom(letters.size())];
        float vx = ofRandom(-velocityValue*14, velocityValue*18);
        float vy = ofRandom(-velocityValue*6,velocityValue*6);
        float vz = ofRandom(velocityValue*7,velocityValue*10);
        myParticle.setInitialCondition(ofGetWindowSize()[0]/2,ofGetWindowHeight()/2, -7000, vx, vy, vz);
        particles.push_back(myParticle);
    }
    
    // VIDEO
    
    vid_calm.setPixelFormat(OF_PIXELS_UYVY);
    //setPixelFormat() has to be called before loading a movie...
    
    vid_calm.setLoopState(OF_LOOP_NORMAL);
    vid_calm.load("1102.mov");
    
    // SOUND
    sound1.load("sound1.wav");
    sound2.load("sound2.wav");
    
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
    int ranSize = ofRandom(-10.0, 10.0);
    
    if(bRipple){
        rip.begin();
        ofFill();
        //ofSetColor(255,0,0);
        // ofDrawEllipse(xpos[0], ypos[0], rippleSizeX, rippleSizeY);
        
        for (int i = 0; i < blobs.size() ; i++){
            //            ofSetColor(colors[i+1]);
            //ofDrawEllipse(xpos[i], ypos[i], rippleSizeX+ranSize, rippleSizeY+ranSize);
            //            blob myBlob;
            blobs[i].update();
            blobs[i].show();
        }
        
        rip.end();
        rip.update();
    }
    // VIDEO PLAY
    if(bVideo){
        vid_calm.update();
    }
    
    // big bang
    if(textParticleOn){
        for (int i = 0; i < particles.size(); i++){
            particles[i].resetForce();
            particles[i].addDampingForce();
            //particles[i].addRepulsionForce(mouseX, mouseY, 500, 1);
            //particles[i].addAttractionForce(mouseX, mouseY, 500, 2);
            //particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.1);
            //particles[i].addClockwiseForce(mouseX, mouseY, 200, 5);
            particles[i].update();
        }
    }
    
    // make it rain
    if(rainForce) {
        for (int i = 0; i < particles.size(); i++){
            particles[i].resetForce();
            particles[i].addForce(-0.03,0.02, 0.02);
            //particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 2);
            particles[i].update();
        }
    }
    
    // VIDEO AND SOUND
    vid_calm.update();
    //    ofSoundUpdate();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    if(bRipple){
//        for (int i = 0; i < blobs.size() ; i++){
//            //            ofSetColor(colors[i+1]);
//            //ofDrawEllipse(xpos[i], ypos[i], rippleSizeX+ranSize, rippleSizeY+ranSize);
//            //            blob myBlob;
//            blobs[i].show();
//        ofDrawRectangle(0, <#float y#>, <#float z#>, <#float w#>, <#float h#>)
        rip.draw(0,0, screenWidth, screenHeight);
        rip.distance = rippleDistance;
        rip.damping = rippleDamping;
        
        
    }
    
    if(bVideo == true){
        vid_calm.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    }
    
    if(!bHide) {
        gui.draw();
        
        stringstream ss;
        ss << "Framerate: " << ofToString(ofGetFrameRate(),0) << "\n";
        ofDrawBitmapString(ss.str().c_str(), 250, 20);
    }
    
    if(textParticleOn){
        ofBackground(0);
        ofSetColor(255);
        ofDrawBitmapString(ofGetFrameRate(), 50, 10);
        
        //        cam.begin();
        if(!rainForce) {
            
            for (int i = 0; i < wordNum; i++){
                particles[i].draw();
            }
        }
        
        if(rainForce) {
            for (int i = wordNum; i < letterNum+wordNum; i++){
                particles[i].draw();
            }
        }
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
    if ( key == 'r') {
        rainForce = !rainForce;
    }
    if ( key == 't') {
        textParticleOn = !textParticleOn;
        bRipple = !bRipple;
        bVideo = false;
        
        vid_calm.stop();
        sound1.stop();
        sound2.play();
        
    }
    if ( key == 'v') {
        bVideo = true;
        bRipple = false;
        vid_calm.play();
        sound1.play();
        vid_calm.setVolume(0.0);
        
    }
    if(key == 's') {
        gui.saveToFile("settings.xml");
    }
    if(key == 'l') {
        gui.loadFromFile("settings.xml");
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
    
    if (gotData){
        //        xpos[0] = ofRandom(0, screenWidth);
        //        ypos[0] = ofRandom(0, screenHeight);
        blob myBlob;
        myBlob.r1 = rippleSizeX;
        myBlob.r2 = rippleSizeY;
        myBlob.color = colors[gotData];
        myBlob.screenX = screenWidth;
        myBlob.screenY = screenHeight;
        blobs.push_back(myBlob);
        
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
