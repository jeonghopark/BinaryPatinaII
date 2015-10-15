//
//  MidiInput.hpp
//  exampleInput_MIDIClass
//
//  Created by jeonghopark on 27/09/15.
//
//

#ifndef MidiInput_hpp
#define MidiInput_hpp

#pragma once

#include "ofMain.h"

#include "ofxMidi.h"

class MidiInput : public ofxMidiListener {

public:
    
    ofxMidiIn midiIn;
    ofxMidiIn midiInDrumPad;
    ofxMidiIn midiInKaosPad;
    ofxMidiMessage midiMessage;
    
    
    void setup();
    void update();
    void draw();
    void exit();

    vector<bool> drumPadOutput();
    vector<bool> drumPad;
    
    void newMidiMessage(ofxMidiMessage& eventArgs);
    
    stringstream text;
    
    
    int barIndex;
    
    int tempoDenominator;
    float ticksPerBar;
    int tempoNumerator;
    int ticksPerqNote;
    int ticks32thNotePerBar;
    int ticksPer32thNote;
    int tempoTicks;
    int ticksfor32thNote;
    int num32thNotes;
    int tempoqNotes;
    int tempoBars;
    bool isPlaying;
    
    
    
};

#endif /* MidiInput_hpp */
