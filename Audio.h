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
      vector<pair<int, int>> stereoSamples; //vector containing stereo samples
   public:
      Audio(int samples, int bitCounts, int channels, string soundFileName);
      Audio();
      int getSamplesPerSecond();
      int getBitCount();
      int getChannels();
      string getSoundFileName();
      string getRange();
      vector<int> getMonoSamples();
      vector<pair<int, int>> getStereoSamples();
      void setMonoSamples(vector<int> monoSamples);
      
      
      //-rev reverse mono samples method
      Audio reverseMonoSamples();
      //-cut cut audio samples over range
      Audio cutOverRange(int r1, int r2);//not used. ignore. specified as ^ operator
      //-radd add audio samples over range
      Audio addOVerRange(Audio & rhs, int r1, int r2);//not used. ignore
      //-radd add over range with pair
      Audio addOverRange(Audio & rhs, pair<int, int> addRange);
      //-norm normalise
      Audio normalise(pair<int, int> normVal, float currRMS);
      //Compute rms
      float computeRMS();
      
      //Overload operators
      
      //+ add
      Audio operator+(const Audio & rhs);
      //| concatenate
      Audio operator|(Audio & rhs);
      //^ cut operation
      Audio operator^(pair<int, int> cutRange);
      //* volume factor
      Audio operator*(pair<float, float> volFact);
};

namespace MHMSHA056{
   
   void createSoundFile(string stringOutFile, vector<int> samples);
   void createStereoSoundFile(string stringOutFile, vector<pair<int, int>> samples);

};