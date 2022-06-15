/*
  ==============================================================================

    AdsrData.cpp
    Created: 1 Jun 2022 2:26:15pm
    Author: Gusarov Dmitry

  ==============================================================================
*/

#include "AdsrData.h"

void AdsrData::update (const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;
    
    setParameters (adsrParams);
}
