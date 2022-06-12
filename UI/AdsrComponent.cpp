/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 1 Jun 2022 2:25:42pm
    Author:  Gusarov Dmitry

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent (juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId)
: attack ("Attack", attackId, apvts, sliderWidth, sliderHeight, juce::Slider::SliderStyle::LinearVertical)
, decay ("Delay", decayId, apvts, sliderWidth, sliderHeight, juce::Slider::SliderStyle::LinearVertical)
, sustain ("Sustain", sustainId, apvts, sliderWidth, sliderHeight, juce::Slider::SliderStyle::LinearVertical)
, release ("Release", releaseId, apvts, sliderWidth, sliderHeight, juce::Slider::SliderStyle::LinearVertical)
{
    addAndMakeVisible (attack);
    addAndMakeVisible (decay);
    addAndMakeVisible (sustain);
    addAndMakeVisible (release);
}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::resized()
{
    const auto startX = 15;
    const auto startY = 55;
    const auto width = sliderWidth;
    const auto height = sliderHeight + 20;
    
    attack.setBounds (startX, startY, width, height);
    decay.setBounds (attack.getRight(), startY, width, height);
    sustain.setBounds (decay.getRight(), startY, width, height);
    release.setBounds (sustain.getRight(), startY, width, height);
}
