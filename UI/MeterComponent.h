/*
  ==============================================================================

    MeterComponent.h
    Created: 8 Jun 2022 9:50:18am
    Author:  Gusarov Dmitry

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"
#include "CustomComponent.h"

//==============================================================================
/*
*/
class MeterComponent  : public CustomComponent
{
public:
    MeterComponent (Synth1AudioProcessor& p);
    ~MeterComponent() override;

    void paintOverChildren (juce::Graphics& g) override;
    void resized() override;

private:
    Synth1AudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MeterComponent)
};
