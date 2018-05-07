//Audio.h template file
#include <string>
#include <vector>

using namespace std;

//template<typename T>
class Audio {

   private:
      string soundFile = "";
      int samplesPerSecond = 0; //44100
      int bitCount = 0; //8 bit or 16 bit
      int channel = 0; // 1 mono 2 stereo
      vector<int> monoSamples; //vector containing mono samples
      
   public:
      Audio(int samples, int bitCounts, int channels, string soundFileName);
      Audio();
      int getSamplesPerSecond();
      int getBitCount();
      int getChannels();
      string getSoundFileName();
      string getRange();
      vector<int> getMonoSamples();
      
      //Overload operators
      
      //+
      Audio operator+(const Audio & rhs);

};

namespace MHMSHA056{
   
   void createSoundFile(string stringOutFile, vector<int> samples);
   
};