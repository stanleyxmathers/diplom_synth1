/*
  ==============================================================================

    SynthSound.h
    Created: 4 Feb 2022 11:28:33am
    Author:  Gusarov Dmitry

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber) override { return true; }
    bool appliesToChannel (int midiChannel) override { return true; }
    
};
