//
//  MidiInput.cpp
//  exampleInput_MIDIClass
//
//  Created by jeonghopark on 27/09/15.
//
//

#include "MidiInput.hpp"


//--------------------------------------------------------------
void MidiInput::setup() {
    
    midiIn.listPorts();
    
    midiIn.openPort("IAC Driver Bus 1");
    midiInDrumPad.openPort("MIDI4x4 Midi In 2");
    midiInKaosPad.openPort("KP3 PAD");
    midiInPadKontrol.openPort("padKONTROL PORT B");
    
    midiIn.ignoreTypes(false, false, false);
    midiInDrumPad.ignoreTypes(false, false, false);
    midiInKaosPad.ignoreTypes(false, false, false);
    midiInPadKontrol.ignoreTypes(false, false, false);
    
    midiIn.addListener(this);
    midiInDrumPad.addListener(this);
    midiInKaosPad.addListener(this);
    midiInPadKontrol.addListener(this);
    
    midiIn.setVerbose(true);
    midiInDrumPad.setVerbose(true);
    midiInKaosPad.setVerbose(true);
    midiInPadKontrol.setVerbose(true);
    

    for (int i=0; i<8; i++) {
        drumPad[i] = false;
    }

    _oldOn = false;

    for (int i=0; i<13; i++) {
        sceneSelect[i] = false;
    }
    
}



//--------------------------------------------------------------
void MidiInput::update(){

    
}


//--------------------------------------------------------------
void MidiInput::kaosPadMessage(ofxMidiMessage& msg){
    

    if ( (int)msg.bytes[0] == 176 ) {
        
        if ((int)msg.bytes[1]==12){
            indiaControl.x = (int)msg.bytes[2];
        }
        
        if ((int)msg.bytes[1]==13){
            indiaControl.y = (int)msg.bytes[2];
        }

    }

}


//--------------------------------------------------------------
void MidiInput::drumPadMessage(ofxMidiMessage& msg){

    int _torelance = 5;
    
    if ( ((int)msg.bytes[0] == 153)) {

        for (int i=0; i<8; i++) {
            if ((int)msg.bytes[1] == (127-i)) {
                if ((int)msg.bytes[2] > _torelance) {
                    drumPad[i] = true;
                } else {
                    drumPad[i] = false;
                }
            }
            
        }
        
    }

}


//--------------------------------------------------------------
void MidiInput::draw(){
    
    ofSetColor(0);
    
    // draw the last recieved message contents to the screen
    text << "Received: " << ofxMidiMessage::getStatusString(midiMessage.status);
    ofDrawBitmapString(text.str(), 20, 20);
    text.str(""); // clear
    
    text << "channel: " << midiMessage.channel;
    ofDrawBitmapString(text.str(), 20, 34);
    text.str(""); // clear
    
    text << "pitch: " << midiMessage.pitch;
    ofDrawBitmapString(text.str(), 20, 48);
    text.str(""); // clear
    ofDrawRectangle(20, 58, ofMap(midiMessage.pitch, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "velocity: " << midiMessage.velocity;
    ofDrawBitmapString(text.str(), 20, 96);
    text.str(""); // clear
    ofDrawRectangle(20, 105, ofMap(midiMessage.velocity, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "control: " << midiMessage.control;
    ofDrawBitmapString(text.str(), 20, 144);
    text.str(""); // clear
    ofDrawRectangle(20, 154, ofMap(midiMessage.control, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "value: " << midiMessage.value;
    ofDrawBitmapString(text.str(), 20, 192);
    text.str(""); // clear
    if(midiMessage.status == MIDI_PITCH_BEND) {
        ofDrawRectangle(20, 202, ofMap(midiMessage.value, 0, MIDI_MAX_BEND, 0, ofGetWidth()-40), 20);
    }
    else {
        ofDrawRectangle(20, 202, ofMap(midiMessage.value, 0, 127, 0, ofGetWidth()-40), 20);
    }
    
    
    // bar Index
    ofDrawBitmapString(num32thNotes % 4 + 1, 20, 260);

}


//--------------------------------------------------------------
void MidiInput::exit() {
    
//    midiIn.closePort();
//    midiIn.removeListener(this);
    
}

//--------------------------------------------------------------
void MidiInput::newMidiMessage(ofxMidiMessage& msg) {
    
    // make a copy of the latest message
    midiMessage = msg;
    
    int tempoDenominator = 4;
    int tempoNumerator = 4;
    int ticksPerqNote = 48;
    
    int _ticksPerqNote = (int) 24.0 * 4.0/tempoDenominator;
    ticksPerBar = tempoNumerator * ticksPerqNote;
    ticks32thNotePerBar = (int) ticksPerBar/8.0;
    ticksPer32thNote = (int) ticksPerqNote/8.0;
    
    
    if(msg.status == 248){
        
        tempoTicks += 1;
        ticksfor32thNote +=1;
        
        if(ticksfor32thNote % ticksPer32thNote == 0 ) {
            // if(num32thNotes % 2 == 0) midiOut.sendNoteOff(1, 62, 0);
            // else  midiOut.sendNoteOn(1, 62, 127);
            num32thNotes  += 1;
        }
        
        if(tempoTicks % _ticksPerqNote == 0 ) {
            tempoqNotes += 1;
            tempoTicks = 0;
            if (tempoqNotes % (tempoNumerator + 1) == 0 ) {
                tempoBars += 1;
                tempoqNotes = 1;
                num32thNotes = 0;
                ticksfor32thNote = 0;
            }
        }
        
    }
    
    if(msg.status == MIDI_START) {
        
        //ticks = 0;
        //qNotes = 0;
        //bars = 0;
        tempoTicks = 0;
        tempoqNotes = 1;
        tempoBars = 1;
        isPlaying = false;
        num32thNotes = 0;
        ticksfor32thNote = 0;
        
        isPlaying = true;
        
    };
    
    // Input !!!
    if(msg.portNum == midiInKaosPad.getPort()) {
        kaosPadMessage(msg);
    } else if (msg.portNum == midiInDrumPad.getPort()) {
        drumPadMessage(msg);
    }

    
    
}
