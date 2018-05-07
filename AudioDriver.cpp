//Audio driver class
#include <string>
#include <sstream>
#include <iostream>
#include "Audio.h"

using namespace std;

int main (int argc, char *argv[]) {
   
   cout << "\nAudio Program!\n";
   
   string programName = "";
   int samplesPerSecond = 0; //44100
   int bitCount = 0; //8 bit or 16 bit
   int channels = 0; // 1 mono 2 stereo
   string channelType;
   string outputFileName = "";
   string option = ""; //-add/cut/radd/cat/v/rev/rms/norm
   
   float r1;
   float r2;
   
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
   if (channels == '1'){
      channelType = "mono";
   } else {
      channelType = "stereo";
   }
   outputFileName = argv[8];
   
   option = argv[9];
   
   if (option == "-cut" || option == "-radd" || option == "-v" || option == "-norm"){
      str.clear();
      str.str("");
      str << argv[10];
      str >> r1;
      
      str.clear();
      str.str("");
      str << argv[11];
      str >> r2;

      soundFile1 = argv[12];
      if (argc > 12){
         soundFile2 = argv[13];
      }
   } else {
      soundFile1 = argv[10];
   
      if (argc > 11){
         soundFile2 = argv[11];
      }
   }
   
   Audio a1(samplesPerSecond, bitCount, channels, soundFile1);
   
      
   //Print first audio file information
   cout << "Audio file 1\n " << endl;
   
   cout << "Samples: " << a1.getSamplesPerSecond() << endl;

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
   
      cout << "Samples: " << a2.getSamplesPerSecond() << endl;

      //Get bit count 8 or 16
      cout << "Bit count: " << a2.getBitCount() << endl;

      //Get channel 1 = mono 2 = stereo
      cout << "Channel: " << a2.getChannels() << endl;

      //Get audio file name   
      cout << "Audio file name: " << a2.getSoundFileName() << endl;
      Audio a3 = a1 + a2;
   
   }
   cout << "Output File: " << outputFileName << "_" << samplesPerSecond << "_" << bitCount << "_" << channelType << ".raw" << endl;
   
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