/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"

void GuiApp::setup(){
	
    parameters.setName("parameters");
    parameters.add(FrameRate.set("FrameRate", ""));
    parameters.add(windowsAlpha.set("WindowsAlpha", 255, 0, 255));
    parameters.add(audioInputOnOff.set("AuioOnOff", false));
	gui.setup(parameters);
	ofBackground(30);
	ofSetVerticalSync(false);
    
}

void GuiApp::update(){

    FrameRate = ofToString( ofGetFrameRate(), 2 );

}

void GuiApp::draw(){

    gui.draw();
    
}
