/*
  ==============================================================================

    MeterComponent.cpp
    Created: 8 Jun 2022 9:50:18am
    Author:  Gusarov Dmitry

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MeterComponent.h"

//==============================================================================
MeterComponent::MeterComponent (Synth1AudioProcessor& p) : audioProcessor (p)
{


}

MeterComponent::~MeterComponent()
{
}

void MeterComponent::paintOverChildren (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced (20, 35).translated (0, 10);
    auto leftMeter = bounds.removeFromTop (bounds.getHeight() / 2).reduced (0, 5);
    auto rightMeter = bounds.reduced (0, 5);
    
    g.setColour (juce::Colour::fromRGB (74, 232, 35));
    const std::atomic<float>& rms = audioProcessor.getRMS();
    auto rmsLevel = juce::jmap<float> (rms.load(), 0.0f, 1.0f, 0.1f, leftMeter.getWidth());
    
    g.fillRoundedRectangle (leftMeter.getX(), leftMeter.getY(), rmsLevel, leftMeter.getHeight(), 5);
    g.fillRoundedRectangle (rightMeter.getX(), rightMeter.getY(), rmsLevel, rightMeter.getHeight(), 5);
    
    g.setColour (juce::Colour::fromRGB (246, 87, 64).withAlpha (0.5f));
    const std::atomic<float>& peak = audioProcessor.getPeak();
    auto peakLevel = juce::jmap<float> (peak.load(), 0.0f, 1.0f, 0.1f, leftMeter.getWidth());
    
    g.fillRoundedRectangle (leftMeter.getX(), leftMeter.getY(), peakLevel, leftMeter.getHeight(), 5);
    g.fillRoundedRectangle (rightMeter.getX(), rightMeter.getY(), peakLevel, rightMeter.getHeight(), 5);
    
    g.setColour (juce::Colours::white);
    g.drawRoundedRectangle (leftMeter.toFloat(), 5, 2.0f);
    g.drawRoundedRectangle (rightMeter.toFloat(), 5, 2.0f);
}

void MeterComponent::resized()
{
   
}
