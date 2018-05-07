//Audio.cpp implementation file
#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <iterator>
#include "Audio.h"


using namespace std;

//template<typename T>
Audio::Audio(int samples, int bitCounts, int channels, string soundFileName){
   samplesPerSecond = samples;
   bitCount = bitCounts;
   channel = channels;
   soundFile = soundFileName;
   
   
   //Create vector of samples for mono 8 bits
   //vector<int> monoSamples;
   
   //Read in file
   ifstream inFile(soundFileName, ios_base::binary);
   
   inFile.seekg(0, inFile.end);
   int length = inFile.tellg();
   inFile.seekg(0, ios::beg);
   cout << "\n\nCreating audio file...\n";
   cout << "\nLenght of file " << soundFile << " is: " << length << " bytes\n\n";
   
   //Number of samples = fileSize/sizeof(intN_t) * channels
   int numberOfSamples = length/(sizeof(int8_t)) * channel;
   cout << "Number of samples: " << numberOfSamples << "\n";
   cout << "Length of audio clip: " << numberOfSamples/samplesPerSecond << " seconds\n";
   
   //Create 1D array to store samples for mono audio
   int* sampleData = new int[numberOfSamples];
   
   //Read in file
   for (int i = 0; i < numberOfSamples; i++){
      inFile.read((char*) &sampleData[i], 1);
   }
   inFile.close();
   
   //Create vector with samples in
   vector<int> monoSamples1(sampleData, sampleData + numberOfSamples);
   monoSamples = monoSamples1;
   
   /*
   cout << "CHECKING AUDIO FILE" << endl;
   for (int i = 0; i < 10; ++i){
      cout << monoSamples[i] << "\n";
   }
   */
   
   MHMSHA056::createSoundFile("OUTPUT.raw", monoSamples);



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

vector<int> Audio::getMonoSamples(){
   return monoSamples;
}

//Overload operator + method
Audio Audio::operator+(const Audio & rhs){
   cout << "Adding two audio files";
   Audio result = *this;
   
   for (int i = 0; i < monoSamples.size(); ++i){
      result.monoSamples[i] += rhs.monoSamples[i];
   }
   
   MHMSHA056::createSoundFile("SOMETHING", result.getMonoSamples());
   return result;
   
   
}

void MHMSHA056::createSoundFile(string stringOutFile, vector<int> samples){
   cout << "Creating sound file: " << stringOutFile;
   
   ofstream pFile (stringOutFile + ".raw", ios::binary);
   
   int* sampleData = new int[samples.size()];
   
   for (int i = 0; i < samples.size(); ++i){
      sampleData[i] = samples[i];
   }
   
   for (int j = 0; j < samples.size(); j++){
      pFile.write((char*)& sampleData[j], 1);
   }
   
   pFile.close();
}
