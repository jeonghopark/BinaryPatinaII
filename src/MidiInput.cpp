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
    midiInDrumPad.openPort("E-MU Xmidi 2x2 Midi In 2");
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
    
    drumPad.resize(8);

    for (int i=0; i<drumPad.size(); i++) {
        drumPad[i] = false;
    }

    _oldOn = false;

    for (int i=0; i<13; i++) {
        sceneSelect[i] = false;
    }
    
}



//--------------------------------------------------------------
void MidiInput::update(){
    
    
    padKONTROL();
    
    kaosPad();
    
    
}



//--------------------------------------------------------------
void MidiInput::padKONTROL(){
    
    if (midiMessage.portName == "padKONTROL PORT B") {
        
        if (midiMessage.channel == 1) {
            
            for (int i=0; i<13; i++) {
                
                if (midiMessage.control == (48 + i)) {
                    
                    if ((midiMessage.value > 64)) {
                        sceneSelect[i] = true;
                    } else if ((midiMessage.value < 64)) {
                        sceneSelect[i] = false;
                    }
                    
                    
                }

            
            }
            
        }
        
    }

}


//--------------------------------------------------------------
void MidiInput::kaosPad(){
    
    if (midiMessage.portName == "KP3 PAD") {
        
        if (midiMessage.channel == 1) {
            
            if (midiMessage.control == 12) {

            }

            if (midiMessage.control == 13) {

            }
            
        }
        
    }
    
}


//--------------------------------------------------------------
vector<bool> MidiInput::drumPadOutput(){
    
    int _torelance = 10;
    if (midiMessage.channel == 10) {

        for (int i=0; i<drumPad.size(); i++) {
            drumPad[i] = false;
        }

        if (midiMessage.pitch == 49) {
            if (midiMessage.velocity > _torelance) {
                drumPad[0] = true;
            } else {
                drumPad[0] = false;
            }
        }

        if (midiMessage.pitch == 59) {
            if (midiMessage.velocity > _torelance) {
                drumPad[1] = true;
            } else {
                drumPad[1] = false;
            }
        }

        if (midiMessage.pitch == 51) {
            if (midiMessage.velocity > _torelance) {
                drumPad[2] = true;
            } else {
                drumPad[2] = false;
            }
        }

        if (midiMessage.pitch == 52) {
            if (midiMessage.velocity > _torelance) {
                drumPad[3] = true;
            } else {
                drumPad[3] = false;
            }
        }

        if (midiMessage.pitch == 50) {
            if (midiMessage.velocity > _torelance) {
                drumPad[4] = true;
            } else {
                drumPad[4] = false;
            }
        }

        if (midiMessage.pitch == 48) {
            if (midiMessage.velocity > _torelance) {
                drumPad[5] = true;
            } else {
                drumPad[5] = false;
            }
        }

        if (midiMessage.pitch == 45) {
            if (midiMessage.velocity > _torelance) {
                drumPad[6] = true;
            } else {
                drumPad[6] = false;
            }
        }

        if (midiMessage.pitch == 41) {
            if (midiMessage.velocity > _torelance) {
                drumPad[7] = true;
            } else {
                drumPad[7] = false;
            }
        }

    }
    

    return drumPad;
    
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
    
    midiIn.closePort();
    midiIn.removeListener(this);
    
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
    
    
    
    
}
