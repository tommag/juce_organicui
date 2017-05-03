/*
  ==============================================================================

    AppUpdater.h
    Created: 8 Apr 2017 4:26:46pm
    Author:  Ben

  ==============================================================================
*/

#ifndef APPUPDATER_H_INCLUDED
#define APPUPDATER_H_INCLUDED

#include "juce_core\juce_core.h"

class AppUpdater
{
public:
	juce_DeclareSingleton(AppUpdater, true);

	void checkForUpdates();
};


#endif  // APPUPDATER_H_INCLUDED
