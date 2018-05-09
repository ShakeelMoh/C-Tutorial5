//Audio driver class
#include <string>
#include <sstream>
#include <iostream>
#include <utility>
#include "Audio.h"

using namespace std;

int main (int argc, char *argv[]) {
   cout << argc;
   cout << "\nAudio Program!\n";
   
   string programName = "";
   int samplesPerSecond = 0; //44100
   int bitCount = 0; //8 bit or 16 bit
   int channels = 0; // 1 mono 2 stereo
   string channelType;
   string outputFileName = "";
   string option = ""; //-add/cut/radd/cat/v/rev/rms/norm
   pair<float, float> volFact;
   
   int r1 = 0;
   int r2 = 0;
   
   float v1 = 0.0f;
   float v2 = 0.0f;
   
   string soundFile1 = "";
   string soundFile2 = "";
   
   programName = argv[0];
   
   stringstream str(argv[2]); //samples to int
   str >> samplesPerSecond;
   
   str.clear();
   str.str("");
   str << argv[4];
   str >> bitCount; //bitcount to int 8/16
   
   str.clear();
   str.str("");
   str << argv[6];
   str >> channels; //channel to int mono or stereo
   if (channels == 1){
      channelType = "mono";
   } else {
      channelType = "stereo";
   }
   outputFileName = argv[8];
   
   option = argv[9];
   if (option == "-cut" || option == "-radd" || option == "-v" || option == "-norm"){
      str.clear();
      str.str("");
      if (option == "-v"){
         str << argv[10];
         str >> v1;
      } else {
         str << argv[10];
         str >> r1;
      }
      
      
      str.clear();
      str.str("");
      if (option == "-v"){
         str << argv[11];
         str >> v2;
         volFact = make_pair(v1,v2); 
         //pair<float, float> volFact (v1, v2);//initialize pair
      } else {
         str << argv[11];
         str >> r2;
      }
      

      soundFile1 = argv[12];
      if (argc > 12){//always causing seg faults
         soundFile2 = argv[13];
      }
   } else {
      soundFile1 = argv[10];
    
      if (argc > 11){
         cout << "!!!!!!!!!!!!!!!!!!!!!";
         soundFile2 = argv[11];
      }
   }
   
   Audio a1(samplesPerSecond, bitCount, channels, soundFile1);
   
      
   //Print first audio file information
   cout << "Audio file 1\n " << endl;
   
   cout << "Sample rate: " << a1.getSamplesPerSecond() << endl;

   //Get bit count 8 or 16
   cout << "Bit count: " << a1.getBitCount() << endl;

   //Get channel 1 = mono 2 = stereo
   cout << "Channel: " << a1.getChannels() << endl;

   //Get audio file name   
   cout << "Audio file name: " << a1.getSoundFileName() << endl;
   
   
   
   if (soundFile2 != ""){
      Audio a2(samplesPerSecond, bitCount, channels, soundFile2);

   
      //Print second audio file information
      cout << "\nAudio file 2\n " << endl;
   
      cout << "Sample rate: " << a2.getSamplesPerSecond() << endl;

      //Get bit count 8 or 16
      cout << "Bit count: " << a2.getBitCount() << endl;

      //Get channel 1 = mono 2 = stereo
      cout << "Channel: " << a2.getChannels() << endl;

      //Get audio file name   
      cout << "Audio file name: " << a2.getSoundFileName() << endl;
      
      if (option == "-add"){
         Audio a3 = a1 + a2;
         
         string formattedOutputName = outputFileName + '_' + to_string(samplesPerSecond) + '_' + to_string(bitCount) + '_' + channelType + ".raw";
         cout << "\n\nOutput File: " << formattedOutputName << "\n";
         MHMSHA056::createSoundFile(formattedOutputName, a3.getMonoSamples());

      }
      if (option == "-cat"){
         Audio a3 = a1 | a2;
         
         string formattedOutputName = outputFileName + '_' + to_string(samplesPerSecond) + '_' + to_string(bitCount) + '_' + channelType + ".raw";
         cout << "\n\nOutput File: " << formattedOutputName << "\n";
         MHMSHA056::createSoundFile(formattedOutputName, a3.getMonoSamples());
      }
      if (option == "-radd"){
         cout << "Ranged add over: " << r1 << " and " << r2 << "\n";
         Audio a3 = a1.addOVerRange(a2, r1, r2);
         string formattedOutputName = outputFileName + '_' + to_string(samplesPerSecond) + '_' + to_string(bitCount) + '_' + channelType + ".raw";
         cout << "\n\nOutput File: " << formattedOutputName << "\n";
         MHMSHA056::createSoundFile(formattedOutputName, a3.getMonoSamples());
      }
      if (option == "-v"){
         cout << "Change volume factor to: " << v1 << "/" << v2;
         Audio a3 = a1 * volFact;
         string formattedOutputName = outputFileName + '_' + to_string(samplesPerSecond) + '_' + to_string(bitCount) + '_' + channelType + ".raw";
         cout << "\n\nOutput File: " << formattedOutputName << "\n";
         MHMSHA056::createSoundFile(formattedOutputName, a3.getMonoSamples());
         

      }
      
   
   } else {
      //If only one sound file
      
      //Reverse samples
      if (option == "-rev"){
         cout << "Reversing audio sample\n";
         Audio a3 = a1.reverseMonoSamples();
         
         string formattedOutputName = outputFileName + '_' + to_string(samplesPerSecond) + '_' + to_string(bitCount) + '_' + channelType + ".raw";
         cout << "\n\nOutput File: " << formattedOutputName << "\n";
         MHMSHA056::createSoundFile(formattedOutputName, a3.getMonoSamples());
      }
      //Cut out samples over range
      if (option == "-cut"){
         cout << "Cutting audio sample between: " << r1 << "s and " << r2 << "s\n"; 
         Audio a3 = a1.cutOverRange(r1, r2);
         
         string formattedOutputName = outputFileName + '_' + to_string(samplesPerSecond) + '_' + to_string(bitCount) + '_' + channelType + ".raw";
         cout << "\n\nOutput File: " << formattedOutputName << "\n";
         MHMSHA056::createSoundFile(formattedOutputName, a3.getMonoSamples());
      }
   
      
   }
   
   
   /*
   cout << "Program name: " << programName << endl;
   cout << "Samples: " << samplesPerSecond << endl;
   cout << "Bit count: " << bitCount << endl;
   cout << "Channels: " << channels << endl;
   cout << "Output File: " << outputFileName << "_" << samplesPerSecond << "_" << bitCount << "_" << channelType << ".raw" << endl;
   cout << "Option: " << option << endl;
   cout << "Sound file 1: " << soundFile1 << endl;
   cout << "Sound file 2: " << soundFile2 << endl;
   */


  

   
   return 0;
   
}