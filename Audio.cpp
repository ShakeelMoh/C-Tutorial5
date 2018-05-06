//Audio.cpp implementation file
#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Audio.h"


using namespace std;

//template<typename T>
Audio::Audio(int samples, int bitCounts, int channels, string soundFileName){
   samplesPerSecond = samples;
   bitCount = bitCounts;
   channel = channels;
   soundFile = soundFileName;
}
Audio::Audio(){
   samplesPerSecond = 0;
   bitCount = 0;
   channel = 0;
   soundFile = "";
}

//Get sample rate
int Audio::getSamplesPerSecond(){
   return samplesPerSecond;
}
//Get bit count 8 or 16
int Audio::getBitCount(){
   return bitCount;
}
//Get channel 1 = mono 2 = stereo
int Audio::getChannels(){
   return channel;
}
//Get audio file name
string Audio::getSoundFileName(){
   return soundFile;
}
