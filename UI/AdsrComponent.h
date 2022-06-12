/*
  ==============================================================================

    AdsrComponent.h
    Created: 1 Jun 2022 2:25:42pm
    Author:  Gusarov Dmitry

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomComponent.h"

//==============================================================================
/*
*/
class AdsrComponent : public CustomComponent
{
public:
    AdsrComponent (juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId);
    ~AdsrComponent() override;

    void resized() override;

private:
    SliderWithLabel attack;
    SliderWithLabel decay;
    SliderWithLabel sustain;
    SliderWithLabel release;
    
    static constexpr int sliderWidth = 50;
    static constexpr int sliderHeight = 260;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
