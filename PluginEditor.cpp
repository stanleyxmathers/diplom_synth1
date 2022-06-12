/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Synth1AudioProcessorEditor::Synth1AudioProcessorEditor (Synth1AudioProcessor& p)
: AudioProcessorEditor (&p)
, audioProcessor (p)
, osc1 (audioProcessor.apvts, "OSC1", "OSC1GAIN", "OSC1PITCH", "OSC1FMFREQ", "OSC1FMDEPTH")
, osc2 (audioProcessor.apvts, "OSC2", "OSC2GAIN", "OSC2PITCH", "OSC2FMFREQ", "OSC2FMDEPTH")
, filter (audioProcessor.apvts, "FILTERTYPE", "FILTERCUTOFF", "FILTERRESONANCE")
, adsr (audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE")
, lfo1 (audioProcessor.apvts, "LFO1FREQ", "LFO1DEPTH")
, filterAdsr (audioProcessor.apvts, "FILTERATTACK", "FILTERDECAY", "FILTERSUSTAIN", "FILTERRELEASE")
, reverb (audioProcessor.apvts, "REVERBSIZE", "REVERBDAMPING", "REVERBWIDTH", "REVERBDRY", "REVERBWET", "REVERBFREEZE")
, meter (audioProcessor)
{

    
    addAndMakeVisible (osc1);
    addAndMakeVisible (osc2);
    addAndMakeVisible (filter);
    addAndMakeVisible (adsr);
    addAndMakeVisible (lfo1);
    addAndMakeVisible (filterAdsr);
    addAndMakeVisible (reverb);
    addAndMakeVisible (meter);
    addAndMakeVisible (logo);
    
    osc1.setName ("OSC 1");
    osc2.setName ("OSC 2");
    filter.setName ("Filter");
    lfo1.setName ("Filter LFO");
    filterAdsr.setName ("Filter ADSR");
    adsr.setName ("ADSR");
    meter.setName ("Signal Meter");
    
    auto oscColour = juce::Colour::fromRGB (67, 214, 247);
    auto filterColour = juce::Colour::fromRGB (156, 35, 232);
    
    osc1.setBoundsColour (oscColour);
    osc2.setBoundsColour (oscColour);
    
    filterAdsr.setBoundsColour (filterColour);
    filter.setBoundsColour (filterColour);
    lfo1.setBoundsColour (filterColour);
        
    
    startTimerHz (30);
    setSize (1080, 520);
}

Synth1AudioProcessorEditor::~Synth1AudioProcessorEditor()
{
    stopTimer();
}

//==============================================================================
void Synth1AudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void Synth1AudioProcessorEditor::resized()
{
    const auto oscWidth = 420;
    const auto oscHeight = 180;
    osc1.setBounds (0, 0, oscWidth, oscHeight);
    osc2.setBounds (0, osc1.getBottom(), oscWidth, oscHeight);
    filter.setBounds (osc1.getRight(), 0, 180, 200);
    lfo1.setBounds (osc2.getRight(), filter.getBottom(), 180, 160);
    filterAdsr.setBounds (filter.getRight(), 0, 230, 360);
    adsr.setBounds (filterAdsr.getRight(), 0, 230, 360);
    reverb.setBounds (0, osc2.getBottom(), oscWidth, 150);
    meter.setBounds (reverb.getRight(), osc2.getBottom(), filterAdsr.getWidth() + lfo1.getWidth(), 150);
    logo.setBounds (meter.getRight(), osc2.getBottom() + 30, 250, 100);
}

void Synth1AudioProcessorEditor::timerCallback()
{
    repaint();
}



