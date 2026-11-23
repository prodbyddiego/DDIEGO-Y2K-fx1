#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class DDIEGOY2KFXAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit DDIEGOY2KFXAudioProcessorEditor(DDIEGOY2KFXAudioProcessor&);
    ~DDIEGOY2KFXAudioProcessorEditor() override = default;
    void paint(juce::Graphics&) override;
    void resized() override;
private:
    DDIEGOY2KFXAudioProcessor& processor;
    juce::TextButton granularButton{"GRANULARIZER"};
    juce::TextButton chopperButton{"CHOPPER"};
    juce::Slider amount;
    juce::Label title;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DDIEGOY2KFXAudioProcessorEditor)
};
