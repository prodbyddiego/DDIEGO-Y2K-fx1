#pragma once
#include <JuceHeader.h>
class GranularEngine {
public:
    void prepare(double sr, int bs);
    void process(juce::AudioBuffer<float>& buffer);
private:
    double sampleRate = 44100.0;
    int blockSize = 512;
    float amount = 0.0f;
    juce::Random random;
};
