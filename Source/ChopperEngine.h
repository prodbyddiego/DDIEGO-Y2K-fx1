#pragma once
#include <JuceHeader.h>
class ChopperEngine {
public:
    void prepare(double sr, int bs);
    void process(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midi);
private:
    double sampleRate = 44100.0;
    int blockSize = 512;
};
