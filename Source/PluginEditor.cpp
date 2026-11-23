#include "PluginEditor.h"

DDIEGOY2KFXAudioProcessorEditor::DDIEGOY2KFXAudioProcessorEditor(DDIEGOY2KFXAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    setSize(820, 520);
    title.setText("DDIEGO Y2K FX", juce::dontSendNotification);
    title.setFont(juce::Font(30.0f, juce::Font::bold));
    title.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(title);
    addAndMakeVisible(granularButton);
    addAndMakeVisible(chopperButton);
    amount.setRange(0.0, 1.0, 0.001);
    amount.setValue(0.0);
    amount.setTextValueSuffix("  AMOUNT");
    addAndMakeVisible(amount);
}
void DDIEGOY2KFXAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff17122b));
    auto r = getLocalBounds().reduced(18);
    g.setColour(juce::Colour(0xffff4fd8));
    g.drawRoundedRectangle(r.toFloat(), 18.0f, 3.0f);
    g.setColour(juce::Colour(0xff30275a));
    g.fillRoundedRectangle(r.toFloat().reduced(8).withHeight(330), 12.0f);
    g.setColour(juce::Colours::white.withAlpha(0.25f));
    g.drawRect(r.reduced(20).withHeight(230), 2);
    g.setColour(juce::Colours::white);
    g.setFont(14.0f);
    g.drawText("DRAG AUDIO HERE", r.reduced(30).withHeight(230),
               juce::Justification::centred, false);
}
void DDIEGOY2KFXAudioProcessorEditor::resized()
{
    auto r = getLocalBounds().reduced(35);
    title.setBounds(r.removeFromTop(55));
    auto buttons = r.removeFromTop(50);
    granularButton.setBounds(buttons.removeFromLeft(190).reduced(4));
    chopperButton.setBounds(buttons.removeFromLeft(150).reduced(4));
    amount.setBounds(r.removeFromBottom(90).reduced(10));
}
