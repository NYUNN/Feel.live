#include "blob.h"
#include "ofMain.h"

blob::blob(){
    
//    cout << "blob Setup";
    pos.set(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
    vel.set(ofRandom(-10,10),ofRandom(-10,10));
//    ofVec2f v1;
//    v1.set(2, 5);
//    vel = v1 * 3;
    cout << screenX << endl;
    cout << screenY << endl;

}

void blob::show(){


   // ofNoFill();
//    pos = ofVec2f(300, 300);
    ofPushMatrix();
    ofSetColor(color);
    ofTranslate(pos.x, pos.y);
    ofDrawEllipse(0, 0, r1, r2);
//    cout << pos.x << pos.y;
    ofPopMatrix();
    
}

void blob::update(){
    
    pos = pos + vel;
    
}
