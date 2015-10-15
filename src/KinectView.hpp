//
//  KinectView.hpp
//  NightVisionKinect
//
//  Created by jeonghopark on 14/10/15.
//
//

#pragma once

#ifndef KinectView_hpp
#define KinectView_hpp

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"

#include "BaseArch.h"


class KinectView : public ofBaseApp {
    
    public :
    
    KinectView();
    ~KinectView();
    
    void setup();
    void update();
    void draw();
    void exit();
    
    void drawNightVision();
    void drawPointCloud();

    void inputBaseArch(BaseArch &);

    BaseArch * baseArchData;
    
    ofxKinect kinect;

#ifdef USE_TWO_KINECTS
    ofxKinect kinect2;
#endif
    
    ofxCvColorImage colorImg;
    
    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
    
    ofxCvContourFinder contourFinder;

    
    bool bThreshWithOpenCV;
    bool bDrawPointCloud;
    
    int nearThreshold;
    int farThreshold;
    
    int angle;
    
    // used for viewing the point cloud
    ofEasyCam easyCam;
    
    ofxCvGrayscaleImage contrastKinect;

};


#endif /* KinectView_hpp */
