/*
  ==============================================================================

    GenericControllableItemUI.h
    Created: 13 May 2017 3:31:56pm
    Author:  Ben

  ==============================================================================
*/

#pragma once
#include "BaseItemEditor.h"

class GenericControllableItemEditor :
	public BaseItemEditor
{
public:
	GenericControllableItemEditor(GenericControllableItem * gci, bool isRoot);
	~GenericControllableItemEditor();

	std::unique_ptr<ControllableEditor> controllableEditor;
	
	void paint(juce::Graphics& g) override;
	void resizedInternalHeaderItemInternal(juce::Rectangle<int>& r) override;
	void resetAndBuild() override;

	void mouseDown(const juce::MouseEvent& e) override;
	void mouseDrag(const juce::MouseEvent &e) override;

	virtual void setDragDetails(juce::var& details) override;

	void childBoundsChanged(juce::Component* c) override;
};
