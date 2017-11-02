//
//  particle.hpp
//  animationTest
//
//  Created by Youn ho Lee on 10/31/17.
//

#ifndef particle_hpp
#define particle_hpp

#include "ofMain.h"

class particle{
    
public:
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f frc;
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
    void resetLetterPos();
    void addForce(float x, float y, float z);
    void addDampingForce();
    void addRepulsionForce( float px, float py, float radius, float strength);
    void addAttractionForce( float px, float py, float radius, float strength);
    void addClockwiseForce( float px, float py, float radius, float strength);
    void addCounterClockwiseForce( float px, float py, float radius, float strength);
    void setInitialCondition(float px, float py, float pz, float vx, float vy, float vz);
    void update();
    void draw();

    float damping;
//    vector<string> words;
//    vector<string> letters;
    string selectedWord;
    int wordsNum;
    int lettersNum1;
    int lettersNum2;
    int lettersNum3;

    ofTrueTypeFont font;
    float fontSize;
    float angle;
    float angleSpeed;
    int opacity;
    
    bool setLetterPos;
};


#endif /* particle_hpp */
