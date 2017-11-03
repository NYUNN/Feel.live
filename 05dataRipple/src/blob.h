//
//  blob.h
//  05dataRipple
//
//  Created by ChoiYunho on 02/11/2017.
//
//

#ifndef blob_h
#define blob_h

#include "ofMain.h"
//#include "ofEvents.h"


class blob{
    
public:
    ofVec2f pos;
    ofVec2f vel;
    
//    float x, y;
//    float r;
    float posx;
    float posy;
    
    float r1;
    float r2;
    
    ofColor color;
    
    float screenX;
    float screenY;
    
    blob();
    virtual ~blob(){};

    
    void show();
    void update();
};

#endif /* blob_h */
