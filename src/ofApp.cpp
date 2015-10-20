#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate( 60 );
    ofBackground( 0 );
    
    
    // syphon
    dir.setup();
    client.setup();
    ofAddListener(dir.events.serverAnnounced, this, &ofApp::serverAnnounced);
    ofAddListener(dir.events.serverRetired, this, &ofApp::serverRetired);
    dirIdx = -1;

    
    mainOffSetXPos = (ofGetWidth() - (baseArch.fassadeCorner[0].x + baseArch.fassadeCorner[1].x)) * 0.5;
    mainOffSetYPos = (ofGetHeight() - (baseArch.fassadeCorner[0].y + baseArch.fassadeCorner[3].y)) * 0.5;
    
    baseArch.mainOffSetXPos = mainOffSetXPos;
    baseArch.mainOffSetYPos = mainOffSetYPos;
    
    
    font.setup("Vera.ttf", 1.0, 1024, true, 8, 1.0);
    font.addFont("VeraMono-Bold.ttf");
    
    nBandsToGet = 32 * 2;
    
    fft.fft.stream.setDeviceID(2);
    fft.setup();
    fft.fft.setup(16384 * 0.5);
    fft.setNumFFTBins(nBandsToGet);
    fft.setFFTpercentage(0.9);
    
    midiInput.setup();

    webCamHD.listDevices();
    webCamHD.setDeviceID(WEBCAM_ID);
    webCamHD.setup(WEBCAM_WIDTH, WEBCAM_HEIGHT);
    

    
    baseArch.inputFont( font );

    glungeWinter.inputBaseArch( baseArch );
    glungeWinter.setup();

    liveCamGlitch.inputBaseArch( baseArch );
    liveCamGlitch.inputMidiInput(midiInput);
    liveCamGlitch.inputWebCam( webCamHD );
    liveCamGlitch.setup();
    
    labyrinth.inputBaseArch( baseArch );
    labyrinth.setup();
    labyrinthOldNumParticle = 0;
    labyrinthOldType = 0;
    labyrinthChangeNum = false;
    
    calligraphy.inputBaseArch( baseArch );
    calligraphy.inputFFTP( fft );
    calligraphy.setup();

    pluto.setup();
    
    indiaTower.inputBaseArch( baseArch );
    indiaTower.inputFFTP( fft );
    indiaTower.setup();
    
    trierFlyingCam.setup();
    
    cubicMapFlyingCam.setup();
    
    moonCreator.setup();
    
    lineVideo.inputBaseArch( baseArch);
    lineVideo.setup();
    lineVideo.inputWebCam( webCamHD );

    movingObjects.inputBaseArch( baseArch );
    movingObjects.setup();
    
    droneAttack.inputBaseArch( baseArch );
    droneAttack.setup();

    webLiveCam.inputBaseArch( baseArch );
    webLiveCam.setup();
    
    nightVision.inputBaseArch( baseArch );
    nightVision.setup();
    
    speechVideoSynth.inputBaseArch( baseArch );
    speechVideoSynth.setup();
    
    fullScreen = false;
    
//    backFBO.allocate(1920, 1080);
//    backGlitch.setup(& backFBO);
//    
//    frontFBO.allocate(1920, 1080);
//    frontGlitch.setup(& frontFBO);

    mainFBO.allocate(1920, 1080);
    mainGlitch.setup(& mainFBO);

}


// syphon
//--------------------------------------------------------------
void ofApp::serverAnnounced(ofxSyphonServerDirectoryEventArgs &arg)
{
    for( auto& dir : arg.servers ){
        ofLogNotice("ofxSyphonServerDirectory Server Announced")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
    }
    dirIdx = 0;
}

//--------------------------------------------------------------
void ofApp::serverUpdated(ofxSyphonServerDirectoryEventArgs &arg)
{
    for( auto& dir : arg.servers ){
        ofLogNotice("ofxSyphonServerDirectory Server Updated")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
    }
    dirIdx = 0;
}

//--------------------------------------------------------------
void ofApp::serverRetired(ofxSyphonServerDirectoryEventArgs &arg)
{
    for( auto& dir : arg.servers ){
        ofLogNotice("ofxSyphonServerDirectory Server Retired")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
    }
    dirIdx = 0;
}



//--------------------------------------------------------------
void ofApp::update(){
    
    
    if (gui->FullScreen) {
        
        ofSetFullscreen(true);
        ofSetWindowPosition(2560, 0);
        ofSetWindowShape(1920, 1080);
        
    }
    
    
    
    
    webCamHD.update();
    midiInput.update();
    midiInput.drumPadOutput();
    
    if (gui->webcamOn) {
        webCamHD.close();
        webCamHD.setDeviceID(WEBCAM_ID);
        webCamHD.setup(WEBCAM_WIDTH, WEBCAM_HEIGHT);
    }
    
    if (gui->OnOff_LiveCamGlitch) {
        liveCamGlitch.update();
        
        if (gui->ResetShader) {
            webCamHD.close();
            webCamHD.setDeviceID(WEBCAM_ID);
            webCamHD.setup(WEBCAM_WIDTH, WEBCAM_HEIGHT);
            liveCamGlitch.inputBaseArch( baseArch );
            liveCamGlitch.inputMidiInput(midiInput);
            liveCamGlitch.inputWebCam( webCamHD );
            liveCamGlitch.glitchEffect.loadShader();
            liveCamGlitch.setup();
            liveCamGlitch.update();
            liveCamGlitch.draw();
        }

    }
    
    
    if (gui->OnOff_Labyrinth) {
        labyrinth.update();
        labyrinth.numParticles = gui->NumParticles;
        labyrinth.LineType = gui->LineType;
        labyrinth.speedFactor = gui->Speed;
        labyrinth.particlesizeFactor = gui->ParticleSize;
        labyrinth.particleC = gui->ParticleColor;
        labyrinth.pathC = gui->PathColor;
        labyrinth.connectionLineC = gui->ConnectionColor;
        
        if (((labyrinthOldNumParticle != gui->NumParticles) && !labyrinthChangeNum )||
            ((labyrinthOldType != gui->LineType) && !labyrinthChangeNum )){
            labyrinth.initParticles();
            labyrinthOldNumParticle = gui->NumParticles;
            labyrinthOldType = gui->LineType;
            labyrinthChangeNum = true;
        } else {
            labyrinthChangeNum = false;
        }
        
        if (gui->UpdateRandom) labyrinth.initParticles();
    }
    
    
    if (gui->OnOff_Calligraphy) {
        fft.update();
        calligraphy.update();
        calligraphy.fftValue = gui->fftSize;
    }

    if (gui->OnOff_Pluto) {
        pluto.update();
    }

    if (gui->OnOff_IndiaTower) {
        fft.update();
    }
    
    if (gui->OnOff_TrierFlyingCam) {
        trierFlyingCam.update();
    }

    if (gui->OnOff_CubicMapFlyingCam) {
        cubicMapFlyingCam.update();
    }
    
    if (gui->OnOff_MoonCreator) {
        moonCreator.update();
    }

    if (gui->OnOff_LineVideo) {
        lineVideo.update();
    }

    if (gui->OnOff_MovingObject) {
        movingObjects.update();
        
        movingObjects.colorRect = gui->ColorRect;
        movingObjects.colorText = gui->ColorText;
        
    }

    
    if (gui->OnOff_DroneAttack) {
        droneAttack.update();
        droneAttack.speedFactor = gui->DroneSpeedFactor;
        droneAttack.colorAttack = gui->AttackColor;
        droneAttack.colorEarth = gui->EarthColor;
        if (gui->LoadImage) {
            droneAttack.loadImage();
        }
    }
    

    if (gui->OnOff_WebLiveCam) {
        webLiveCam.update();
        webLiveCam.indexMovie = gui->IndexMovie;
        if (gui->LoadMovies) {
            webLiveCam.movieLoad();
        }
        if (gui->RandomPosition) {
            webLiveCam.randomWindowsPosition();
        }
    }
    
    

    if (gui->CanonView) {
        if (gui->OnOff_NightVision) {
            nightVision.update(client);
        }
    }
    
    
    // syphon
    if (gui->SyphonSearch) {
        if (dir.size() > 0) {
            dirIdx++;
            if(dirIdx > dir.size() - 1)
                dirIdx = 0;
            
            client.set(dir.getDescription(dirIdx));
            string serverName = client.getServerName();
            string appName = client.getApplicationName();
            
            if(serverName == ""){
                serverName = "null";
            }
            if(appName == ""){
                appName = "null";
            }
        }
    }
    
    
    
    if (gui->OnOFf_SpeechVideo) {
        speechVideoSynth.update();
        speechVideoSynth.indexMovie = gui->IndexSpeechMovie;
        
    }


    
    
    mainFBO.begin();
    ofClear(0, 0, 0, 0);
    ofPushMatrix();
    ofTranslate( mainOffSetXPos, mainOffSetYPos );
    if (gui->OnOff_Pluto) {
        pluto.draw();
    }
    
    if (gui->OnOff_LiveCamGlitch) {
        liveCamGlitch.draw();
    }
    
    if (gui->OnOFf_SpeechVideo) {
        speechVideoSynth.draw();
    }
    
    
    if (gui->OnOff_WebLiveCam) {
        webLiveCam.draw();
    }
    
    
    if (gui->CanonView) {
        if (gui->OnOff_NightVision) {
            nightVision.draw();
        }
    }
    
    
    if (gui->OnOff_LineVideo) {
        lineVideo.draw();
        lineVideo.drawStartPoints();
        lineVideo.drawLines();
        lineVideo.drawColorNumber();
    }
    
    if (gui->OnOff_TrierFlyingCam) {
        trierFlyingCam.draw();
    }
    
    if (gui->OnOff_CubicMapFlyingCam) {
        cubicMapFlyingCam.draw();
    }
    
    
    if (gui->OnOff_MoonCreator) {
        moonCreator.draw();
    }
    
    
    
    if (gui->OnOff_DroneAttack) {
        if (gui->DrawEarthTexture) {
            droneAttack.drawEarthTexture();
        }
        if (gui->DrawEarth) {
            droneAttack.drawEarth();
        }
        if (gui->DrawAttack) {
            droneAttack.drawAttackPosition();
        }
    }
    
    
    
    if (gui->OnOff_Calligraphy) {
        calligraphy.draw();
    }
    
    
    if (gui->OnOff_GlungeWinter) {
        glungeWinter.drawBackTexture();
        glungeWinter.drawBack();
    }
    
    
    if (gui->OnOff_Labyrinth) {
        labyrinth.draw();
    }
    
    drawBaseArch();


    if (gui->OnOff_Windows) {
        ofColor _c = gui->color_Windows;
        baseArch.drawWindows( _c );
    }
    
    if (gui->OnOff_GlungeWinter) {
        glungeWinter.drawFront();
    }
    
    
    if (gui->OnOff_IndiaTower) {
        indiaTower.drawingRectColumn();
        indiaTower.drawingNumber();
        indiaTower.drawingBeziel();
    }
    
    if (gui->OnOff_MovingObject) {
        movingObjects.draw();
    }

    ofPopMatrix();
    mainFBO.end();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofPushMatrix();
    
    ofTranslate( mainOffSetXPos, mainOffSetYPos );
    mainFBO.draw(0, 0);


    
    ofPushMatrix();
    ofTranslate( -mainOffSetXPos, -mainOffSetYPos );
    mainGlitch.generateFx();
    mainFBO.draw(0, 0);
    ofPopMatrix();

    
    
    baseArch.drawEdgeCover( ofColor(0) );

    ofPopMatrix();
    

}


//--------------------------------------------------------------
void ofApp::drawBaseArch(){
    
    ofEnableAlphaBlending();
    
    ofPushStyle();
    
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    if (gui->OnOff_Frames) {
        ofColor _c = gui->color_Frames;
        baseArch.guideFrames( _c );
    }
    
    if (gui->OnOff_Lines) {
        ofColor _c = gui->color_Lines;
        baseArch.guideLines( _c );
    }
    
    if (gui->OnOff_Points) {
        ofColor _c = gui->color_Points;
        baseArch.guidePoints( _c );
    }
    
    if (gui->OnOff_Cross) {
        ofColor _c = gui->color_Cross;
        baseArch.guideCrossPoints( _c );
    }
    
    if (gui->OnOff_Numbers) {
        ofColor _c = gui->color_Numbers;
        baseArch.drawPointNumber( _c );
    }
    
//    ofDisableBlendMode();
    
    
    ofPopStyle();
    
    ofDisableAlphaBlending();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    liveCamGlitch.keyPressed(key);
    if (key == '1') mainGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
    if (key == '2') mainGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
    if (key == '3') mainGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
    if (key == '4') mainGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
    if (key == '5') mainGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
//    if (key == '6') backGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
    if (key == '7') mainGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
    if (key == '8') mainGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
    if (key == '9') mainGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
    if (key == '0') mainGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);
    
    if (key == 'q') mainGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 'w') mainGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
    if (key == 'e') mainGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
    if (key == 'r') mainGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
    if (key == 't') mainGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
    if (key == 'y') mainGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
    if (key == 'u') mainGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == '1') mainGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == '1') mainGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == '2') mainGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == '3') mainGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == '4') mainGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == '5') mainGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
//    if (key == '6') backGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    if (key == '7') mainGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == '8') mainGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == '9') mainGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == '0') mainGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
    
    if (key == 'q') mainGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 'w') mainGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    if (key == 'e') mainGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    if (key == 'r') mainGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    if (key == 't') mainGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    if (key == 'y') mainGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    if (key == 'u') mainGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);



    
    
    liveCamGlitch.keyReleased(key);

    baseArch.keyInteraction(key);
    
    labyrinth.keyReleased(key);
    
    webLiveCam.keyReleased(key);

    if (key == 'o') {
        baseArch.setupDefault();
    }
    
    if (key == ' ') {
        indiaTower.setup();
        pluto.loadImages();
        webLiveCam.movieLoad();
    }
    
    if (key == 'f') {
        fullScreen = !fullScreen;
        ofSetFullscreen(fullScreen);
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
    mainOffSetXPos = (ofGetWidth() - (baseArch.fassadeCorner[0].x + baseArch.fassadeCorner[1].x)) * 0.5;
    mainOffSetYPos = (ofGetHeight() - (baseArch.fassadeCorner[0].y + baseArch.fassadeCorner[3].y)) * 0.5;
    baseArch.mainOffSetXPos = mainOffSetXPos;
    baseArch.mainOffSetYPos = mainOffSetYPos;
    
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}


