#include "particle.hpp"
#include "ofMain.h"

//------------------------------------------------------------
particle::particle(){

    fontSize = ofRandom(30, 60);
    font.load("BEBAS___.ttf",fontSize, true, false, true);
    angle = ofRandom(-50, 50);
    angleSpeed = ofRandom(-0.5, 0.5);
    damping = ofRandom(0.02, 0.07);
    opacity = ofRandom(75, 255);

//    ofLog() << words.size();
}

//------------------------------------------------------------
void particle::resetForce(){
    frc.set(0,0, 0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y, float z){
    frc.x = frc.x + x;
    frc.y = frc.y + y;
    frc.z = frc.z + z;
}


//------------------------------------------------------------
void particle::addDampingForce(){
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
    frc.z = frc.z - vel.z * damping;
}

void particle::addRepulsionForce( float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x += diff.x * pct * strength;
        frc.y += diff.y * pct * strength;
    }
    
}

void particle::addAttractionForce( float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x -= diff.x * pct * strength;
        frc.y -= diff.y * pct * strength;
    }
    
}

void particle::addClockwiseForce( float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x -= diff.y * pct * strength;
        frc.y += diff.x * pct * strength;
    }
    
}

void particle::addCounterClockwiseForce( float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x += diff.y * pct * strength;
        frc.y -= diff.x * pct * strength;
    }
    
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float pz, float vx, float vy, float vz){
    pos.set(px, py, pz);
    vel.set(vx,vy, vz);
}

//------------------------------------------------------------
void particle::update(){
    vel = vel + frc;
    pos = pos + vel;
    angle = angle + angleSpeed;
}

//------------------------------------------------------------
void particle::draw(){
    
    ofPushMatrix();
    
    ofSetColor(255,255,255, opacity);
    ofTranslate(pos.x, pos.y, pos.z);
    ofRotate(angle, 0.15, 0.3, 0.5);
    
    float currentWordWidth = font.stringWidth(selectedWord);
    float currentWordHeigth = font.stringHeight(selectedWord);
    font.drawStringAsShapes(selectedWord, -currentWordWidth/2, -currentWordHeigth/2);

    ofPopMatrix();
}

