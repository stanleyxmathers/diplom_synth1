/*
  ==============================================================================

    AdsrData.h
    Created: 1 Jun 2022 2:26:15pm
    Author:  Gusarov Dmitry

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void update (const float attack, const float decay, const float sustain, const float release);
    
private:
    juce::ADSR::Parameters adsrParams;
};
