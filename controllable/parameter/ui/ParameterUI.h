/*
  ==============================================================================

    ParameterUI.h
    Created: 8 Mar 2016 3:48:44pm
    Author:  bkupe

  ==============================================================================
*/

#pragma once

class ParameterUI :
	public ControllableUI,
	public Parameter::AsyncListener
{
public:
	ParameterUI(Parameter* parameter);
	virtual ~ParameterUI();

	WeakReference<Parameter> parameter;

	bool showEditWindowOnDoubleClick;
	bool showValue;

	bool useCustomBGColor;
	Colour customBGColor;
	bool useCustomFGColor;
	Colour customFGColor;

	static std::function<void(ParameterUI*)> customShowEditRangeWindowFunction;

	virtual void showEditWindowInternal() override;
	virtual Component* getEditValueComponent();

	void showEditRangeWindow();
	virtual void showEditRangeWindowInternal();

	void paintOverChildren(Graphics &g) override;

	virtual void addPopupMenuItems(PopupMenu * p) override;
	virtual void addPopupMenuItemsInternal(PopupMenu *) {}
	virtual void handleMenuSelectedID(int id) override;

	virtual void mouseDoubleClick(const MouseEvent &e) override;

	virtual bool isInteractable() override;

	//focus
	static int currentFocusOrderIndex;
	static void setNextFocusOrder(Component * focusComponent);

	class ValueEditCalloutComponent :
		public Component,
		public Label::Listener
	{
	public:
		ValueEditCalloutComponent(WeakReference<Parameter> pui);
		~ValueEditCalloutComponent();
		
		WeakReference<Parameter> p;
		OwnedArray<Label> labels;

		void resized() override;
		void paint(Graphics& g) override;
		void labelTextChanged(Label* l) override;
		void editorHidden(Label* l, TextEditor&) override;
		void parentHierarchyChanged() override;
	};

protected:

    // helper to spot wrong deletion order
    bool shouldBailOut();

    // here we are bound to only one parameter so no need to pass parameter*
    // for general behaviour see AsyncListener
    virtual void valueChanged(const var & ){};
	virtual void rangeChanged(Parameter * ){};
	virtual void controlModeChanged(Parameter*) {};

	virtual void newMessage(const Parameter::ParameterEvent &e) override;;
};

