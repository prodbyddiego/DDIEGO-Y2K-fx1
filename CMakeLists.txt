cmake_minimum_required(VERSION 3.22)
project(DDIEGO_Y2K_FX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED JUCE_DIR)
    message(FATAL_ERROR "JUCE_DIR is required")
endif()

add_subdirectory("${JUCE_DIR}" JUCE)

juce_add_plugin(DDIEGO_Y2K_FX
    COMPANY_NAME "DDIEGO"
    PLUGIN_MANUFACTURER_CODE DDie
    PLUGIN_CODE Y2Kx
    FORMATS VST3
    PRODUCT_NAME "DDIEGO Y2K FX"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    COPY_PLUGIN_AFTER_BUILD FALSE
)

target_sources(DDIEGO_Y2K_FX PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
    Source/GranularEngine.cpp
    Source/ChopperEngine.cpp
)

target_include_directories(DDIEGO_Y2K_FX PRIVATE Source)

target_compile_definitions(DDIEGO_Y2K_FX PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(DDIEGO_Y2K_FX PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_formats
    juce::juce_dsp
)
