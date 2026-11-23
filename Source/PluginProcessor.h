#pragma once
#include <JuceHeader.h>
#include "GranularEngine.h"
#include "ChopperEngine.h"

class DDIEGOY2KFXAudioProcessor : public juce::AudioProcessor
{
public:
    DDIEGOY2KFXAudioProcessor();
    ~DDIEGOY2KFXAudioProcessor() override = default;
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }
    const juce::String getName() const override { return "DDIEGO Y2K FX"; }
    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}
    void getStateInformation(juce::MemoryBlock&) override {}
    void setStateInformation(const void*, int) override {}
private:
    GranularEngine granular;
    ChopperEngine chopper;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DDIEGOY2KFXAudioProcessor)
};

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter();
