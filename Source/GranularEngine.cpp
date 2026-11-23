#include "GranularEngine.h"
void GranularEngine::prepare(double sr, int bs) { sampleRate = sr; blockSize = bs; }
void GranularEngine::process(juce::AudioBuffer<float>& buffer)
{
    juce::ignoreUnused(sampleRate, blockSize);
    if (amount <= 0.001f) return;
    const int stride = juce::jmax(1, (int)(12.0f - amount * 11.0f));
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* x = buffer.getWritePointer(ch);
        for (int i = 0; i < buffer.getNumSamples(); i += stride)
        {
            const int end = juce::jmin(buffer.getNumSamples(), i + stride);
            const float gain = 0.96f + 0.08f * random.nextFloat() * amount;
            for (int j=i; j<end; ++j) x[j] *= gain;
        }
    }
}
