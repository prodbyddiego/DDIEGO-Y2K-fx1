#include "PluginProcessor.h"
#include "PluginEditor.h"

DDIEGOY2KFXAudioProcessor::DDIEGOY2KFXAudioProcessor()
    : AudioProcessor(BusesProperties()
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)) {}

void DDIEGOY2KFXAudioProcessor::prepareToPlay(double sr, int bs)
{
    granular.prepare(sr, bs);
    chopper.prepare(sr, bs);
}
void DDIEGOY2KFXAudioProcessor::releaseResources() {}

bool DDIEGOY2KFXAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    auto main = layouts.getMainOutputChannelSet();
    return main == juce::AudioChannelSet::mono() || main == juce::AudioChannelSet::stereo();
}

void DDIEGOY2KFXAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midi)
{
    juce::ScopedNoDenormals noDenormals;
    granular.process(buffer);
    chopper.process(buffer, midi);
}

juce::AudioProcessorEditor* DDIEGOY2KFXAudioProcessor::createEditor()
{
    return new DDIEGOY2KFXAudioProcessorEditor(*this);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DDIEGOY2KFXAudioProcessor();
}
