//Audio.h template file
#include <string>

using namespace std;

//template<typename T>
class Audio {

   private:
      string soundFile = "";
      int samplesPerSecond = 0; //44100
      int bitCount = 0; //8 bit or 16 bit
      int channel = 0; // 1 mono 2 stereo

   public:
      Audio(int samples, int bitCounts, int channels, string soundFileName);
      Audio();
      int getSamplesPerSecond();
      int getBitCount();
      int getChannels();
      string getSoundFileName();
      string getRange();
   

};