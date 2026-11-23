#include "ChopperEngine.h"
void ChopperEngine::prepare(double sr, int bs) { sampleRate = sr; blockSize = bs; }
void ChopperEngine::process(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midi)
{
    juce::ignoreUnused(buffer, midi, sampleRate, blockSize);
}
