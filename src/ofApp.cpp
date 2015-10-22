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
    
    fft.fft.stream.setDeviceID(3);
    fft.setVolumeRange(0);
    fft.setup();
    fft.fft.setup(16384 * 0.25);
    fft.setNumFFTBins(nBandsToGet);
    fft.setFFTpercentage(0.9);
    
    midiInput.setup();
    
    mainImgDirectGlitch.allocate(640, 480, OF_IMAGE_COLOR);
    bMainDirectglitch = false;
    qualityMain = OF_IMAGE_QUALITY_WORST;


    webCamHD.listDevices();
    webCamHD.setDeviceID(WEBCAM_ID);
    webCamHD.setup(WEBCAM_WIDTH, WEBCAM_HEIGHT);
    
    leapMotion.open();

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

    pluto.inputBaseArch( baseArch );
    pluto.setup();
    
    indiaTower.inputBaseArch( baseArch );
    indiaTower.inputFFTP( fft );
    indiaTower.setup();
    
    trierFlyingCam.inputBaseArch( baseArch );
    trierFlyingCam.inputLeapMotion( leapMotion );
    trierFlyingCam.setup();
    
    
    cubicMapFlyingCam.inputBaseArch( baseArch );
    cubicMapFlyingCam.inputLeapMotion( leapMotion );
    cubicMapFlyingCam.setup();
    

    moonCreator.inputBaseArch( baseArch );
    moonCreator.inputFFTP( fft );
    moonCreator.inputBaseArch( baseArch );
    moonCreator.setup();
    
    
    lineVideo.inputBaseArch( baseArch);
    lineVideo.setup();
    lineVideo.inputWebCam( webCamHD );

    
    movingObjects.inputBaseArch( baseArch );
    movingObjects.inputFont( font );
    movingObjects.setup();
    
    
    droneAttack.inputBaseArch( baseArch );
    droneAttack.inputFFTP( fft );
    droneAttack.inputFont( font );
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

    
    ofSetEscapeQuitsApp(false);

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
    
    gui->OnOff_GlungeWinter = sceneSelect[0];
    gui->OnOff_LiveCamGlitch = sceneSelect[1];
    gui->OnOff_Labyrinth = sceneSelect[2];
    gui->OnOff_Calligraphy = sceneSelect[3];
    gui->OnOff_Pluto = sceneSelect[4];
    gui->OnOff_IndiaTower= sceneSelect[5];
    gui->OnOff_TrierFlyingCam= sceneSelect[6];
    gui->OnOff_CubicMapFlyingCam= sceneSelect[7];
    gui->OnOff_MoonCreator= sceneSelect[8];
    gui->OnOff_LineVideo= sceneSelect[9];
    gui->OnOff_MovingObject= sceneSelect[10];
    gui->OnOff_DroneAttack= sceneSelect[11];
    gui->OnOff_WebLiveCam= sceneSelect[12];
    
    gui->OnOff_Windows = BaseArchSelect[0];
    gui->OnOff_Frames = BaseArchSelect[1];
    gui->OnOff_Lines = BaseArchSelect[2];
    gui->OnOff_Points = BaseArchSelect[3];
    gui->OnOff_Cross = BaseArchSelect[4];
    gui->OnOff_Numbers = BaseArchSelect[5];
    
    if (gui->FullScreen) {
        ofSetFullscreen(true);
        ofSetWindowPosition(2560, 0);
        ofSetWindowShape(1920, 1080);
    }
    
    
    
    webCamHD.update();
//    midiInput.update();
//    midiInput.drumPadOutput();
    
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

    if (gui->Return) {
        pluto.returnValue();
    }
    
    if (gui->OnOff_Pluto) {
        pluto.update();
        pluto.speedRatio = gui->SpeedRatioMoon;
    }

    if (gui->OnOff_IndiaTower) {
        fft.update();
    }
    
    if (gui->OnOff_TrierFlyingCam) {
        trierFlyingCam.update();
        trierFlyingCam.buildingColor = gui->TrierBuildColor;
        trierFlyingCam.roadColor = gui->TrierRoadColor;
        trierFlyingCam.movingColor = gui->TrierMovingColor;
    }

    if (gui->OnOff_CubicMapFlyingCam) {
        cubicMapFlyingCam.update();
        cubicMapFlyingCam.buildingColor = gui->BuildColor;
        cubicMapFlyingCam.buildingSideColor = gui->BuildSideColor;
        cubicMapFlyingCam.roadColor = gui->RoadColor;
        cubicMapFlyingCam.movingColor = gui->MovingColor;
    }
    
    if (gui->OnOff_MoonCreator) {
        fft.update();
        moonCreator.update();
    }

    if (gui->OnOff_LineVideo) {
        lineVideo.update();
        lineVideo.controlPointRandom = gui->ControlRandom;
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


    
    // draw FBO
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
    
    
    if (gui->CanonView) {
        if (gui->OnOff_NightVision) {
            nightVision.draw();
        }
    }

    
    if (gui->OnOff_WebLiveCam) {
        webLiveCam.draw();
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
        moonCreator.creatorDraw();
        moonCreator.drawLines();
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
        glungeWinter.verticalColor = gui->VerticalColor;
        glungeWinter.horizonColor = gui->HorizonColor;
        glungeWinter.drawBackTexture();
        glungeWinter.drawBack();
    }
    
    
    if (gui->OnOff_Labyrinth) {
        labyrinth.draw();
    }
    
    
    drawBaseArch();


    if ( (gui->OnOff_Windows) || midiInput.drumPad[0] ) {
        ofColor _c = gui->color_Windows;
        baseArch.drawWindows( _c );
    }
    
    if (gui->OnOff_GlungeWinter) {
        if (gui->verticalOnOff) {
            glungeWinter.drawFrontVertical();
        }
        if (gui->horizonOnOff) {
            glungeWinter.drawFrontHorizon();
        }
    }
    
    
    if (gui->OnOff_IndiaTower) {
        indiaTower.drawingRectColumn();
        indiaTower.drawingNumber();
        indiaTower.drawingBeziel();
    }
    
    if (gui->OnOff_MovingObject) {
        movingObjects.draw();
        if (gui->RandomTextOnOff) {
            movingObjects.drawRandomText();
            movingObjects.colorRandomText = gui->ColorRandomText;
        }
    }

    ofPopMatrix();
    mainFBO.end();
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofPushMatrix();
    
    ofTranslate( mainOffSetXPos, mainOffSetYPos );
//    mainFBO.draw(0, 0);
    
    ofPushMatrix();
    ofTranslate( -mainOffSetXPos, -mainOffSetYPos );
    mainGlitch.generateFx();
    mainFBO.draw(0, 0);
    ofPopMatrix();
    
    baseArch.drawEdgeCover( ofColor(0) );

    
    
    ofEnableAlphaBlending();
    
    if (bMainDirectglitch) {
        float _w = baseArch.fassadeCorner[1].x - baseArch.fassadeCorner[0].x;
        float _h = baseArch.fassadeCorner[2].y - baseArch.fassadeCorner[0].y;
        float _x = baseArch.fassadeCorner[0].x;
        float _y = baseArch.fassadeCorner[0].y;
        
        ofPixels _p;
        _p.allocate(640, 480, 3);
        mainFBO.readToPixels(_p);
        mainGlitchPixel(_p);
        mainImgDirectGlitch.draw(_x, _y, _w, _h);
    }
    
    ofDisableAlphaBlending();

    ofPopMatrix();

}


//--------------------------------------------------------------
void ofApp::drawBaseArch(){
    
    ofEnableAlphaBlending();
    
    ofPushStyle();
        
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    if ( (gui->OnOff_Frames) || midiInput.drumPad[1] )
    {
        ofColor _c = gui->color_Frames;
        baseArch.guideFrames( _c );
    }
    
    if ( (gui->OnOff_Lines) || midiInput.drumPad[2] )
    {
        ofColor _c = gui->color_Lines;
        baseArch.guideLines( _c );
    }
    
    if ( (gui->OnOff_Points) || midiInput.drumPad[3] )
    {
        ofColor _c = gui->color_Points;
        baseArch.guidePoints( _c );
    }
    
    if ( (gui->OnOff_Cross) || midiInput.drumPad[4] )
    {
        ofColor _c = gui->color_Cross;
        baseArch.guideCrossPoints( _c );
    }
    
    if ( (gui->OnOff_Numbers) || midiInput.drumPad[5] )
    {
        ofColor _c = gui->color_Numbers;
        baseArch.drawPointNumber( _c );
    }
    
    if ( (gui->OnOff_RandomW) || ( midiInput.drumPad[6] )) {
        ofColor _c = gui->color_RandomW;
        baseArch.drawRandomWindows( _c );
    }
 
    if ( (gui->OnOff_RandomW) || ( midiInput.drumPad[7] )) {
        ofColor _c = gui->color_RandomW;
        baseArch.drawWindowNumber( _c );
    }
    
    
//    ofDisableBlendMode();
    
    
    ofPopStyle();
    
    ofDisableAlphaBlending();
    

}



//--------------------------------------------------------------
void ofApp::mainGlitchPixel(ofPixels _p) {
    
    string compressedFilename = "compressed.jpg";
    
    _p.setImageType(OF_IMAGE_COLOR);
    unsigned char * _c = _p.getData();
    
    float coin = ofRandom(100);
    if (coin > 95) {
        _c = _p.getData() + (int)ofRandom(100);
    }
    
    mainImgDirectGlitch.setImageType(OF_IMAGE_COLOR);
    mainImgDirectGlitch.setFromPixels(_c, (int)ofRandom(10, 640), (int)ofRandom(10, 480), OF_IMAGE_COLOR);
    mainImgDirectGlitch.save(compressedFilename, qualityMain);
    
    ofBuffer fileGlitchBuffer = ofBufferFromFile(compressedFilename);
    int fileSize = fileGlitchBuffer.size();
    char * buffer = fileGlitchBuffer.getData();
    
    int whichByte = (int) ofRandom(fileSize);
    int whichBit = ofRandom(16);
    
    char bitMask;
    if ( whichBit > 4 ) {
        bitMask = 1 << whichBit;
    } else {
        bitMask = 7 << whichBit;
    }
    
    buffer[whichByte] |= bitMask;
    
    ofBufferToFile(compressedFilename, fileGlitchBuffer);
    mainImgDirectGlitch.load(compressedFilename);
    
    //    float coin = ofRandom(100);
    //    if (coin > 95) {
    //        reset();
    //    }
    
}






//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 49) mainGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
    if (key == 50) mainGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
    if (key == 51) mainGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
    if (key == 52) mainGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
    if (key == 53) mainGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
//    if (key == '6') backGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
    if (key == 54) mainGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
    if (key == 55) mainGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
    if (key == 56) mainGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
    if (key == 57) mainGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);
    
    if (key == 48) mainGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 223) mainGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
    if (key == 112) mainGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
    if (key == 111) mainGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
    if (key == 105) mainGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
    if (key == 117) mainGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
    if (key == 252) mainGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
    
    if (key == 43) bMainDirectglitch = true;
    
    
    liveCamGlitch.keyPressed(key);


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == 127 || key == 49) mainGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == 127 || key == 50) mainGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == 127 || key == 51) mainGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == 127 || key == 52) mainGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == 127 || key == 53) mainGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
//    if (key == '6') backGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    if (key == 127 || key == 54) mainGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == 127 || key == 55) mainGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == 127 || key == 56) mainGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == 127 || key == 57) mainGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
    
    if (key == 127 || key == 48) mainGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 127 || key == 223) mainGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    if (key == 127 || key == 112) mainGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    if (key == 127 || key == 111) mainGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    if (key == 127 || key == 105) mainGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    if (key == 127 || key == 117) mainGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    if (key == 127 || key == 252) mainGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);

    if (key == 127 || key == 43) bMainDirectglitch = false;


    
    
    liveCamGlitch.keyReleased(key);

    baseArch.keyInteraction(key);
    
    labyrinth.keyReleased(key);
    
    webLiveCam.keyReleased(key);

    if (key == 248) {
        baseArch.setupDefault();
    }
    
//    if (key == ' ') {
//        indiaTower.setup();
//        pluto.loadImages();
//        webLiveCam.movieLoad();
//    }
    
    if (key == 'f') {
        fullScreen = !fullScreen;
        ofSetFullscreen(fullScreen);
    }
    
    if (key == 362) {
        trierFlyingCam.returnBase();
        cubicMapFlyingCam.returnBase();
        moonCreator.returnBase();
        droneAttack.returnBase();
    }

    cout << key << endl;
    
    if (key == 161) sceneSelect[0] = !sceneSelect[0];
    if (key == 8220) sceneSelect[1] = !sceneSelect[1];
    if (key == 182) sceneSelect[2] = !sceneSelect[2];
    if (key == 162) sceneSelect[3] = !sceneSelect[3];
    if (key == 91) sceneSelect[4] = !sceneSelect[4];
    if (key == 93) sceneSelect[5] = !sceneSelect[5];
    if (key == 124) sceneSelect[6] = !sceneSelect[6];
    if (key == 123) sceneSelect[7] = !sceneSelect[7];
    if (key == 125) sceneSelect[8] = !sceneSelect[8];
    if (key == 8800) sceneSelect[9] = !sceneSelect[9];
    if (key == 171) sceneSelect[10] = !sceneSelect[10];
    if (key == 8721) sceneSelect[11] = !sceneSelect[11];
    if (key == 8364) sceneSelect[12] = !sceneSelect[12];

    
    if (key == 229) BaseArchSelect[0] = !BaseArchSelect[0];
    if (key == 8218) BaseArchSelect[1] = !BaseArchSelect[1];
    if (key == 8706) BaseArchSelect[2] = !BaseArchSelect[2];
    if (key == 402) BaseArchSelect[3] = !BaseArchSelect[3];
    if (key == 169) BaseArchSelect[4] = !BaseArchSelect[4];
    if (key == 170) BaseArchSelect[5] = !BaseArchSelect[5];
    
    
    
    
    
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


