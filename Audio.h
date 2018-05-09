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
      void setMonoSamples(vector<int> monoSamples);
      
      //-rev reverse mono samples method
      Audio reverseMonoSamples();
      //-cut cut audio samples over range
      Audio cutOverRange(int r1, int r2);
      //-radd add audio samples over range
      Audio addOVerRange(Audio & rhs, int r1, int r2);
      //Overload operators
      
      //+ add
      Audio operator+(const Audio & rhs);
      //| concatenate
      Audio operator|(Audio & rhs);

};

namespace MHMSHA056{
   
   void createSoundFile(string stringOutFile, vector<int> samples);
   
};