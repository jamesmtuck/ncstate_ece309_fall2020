#include <fstream>
#include <string>

using namespace std;

class Logger {
private:
    std::ofstream of; // just a made up object
public:
    Logger(std::string filename="log.txt")
      :of(filename,std::ofstream::out)
    {}
  void log(std::string msg) { of << msg << std::endl; }
    ~Logger() { of.close(); }
};

int main()
{
  Logger log;

  log.log("Hi!");
  
  return 0;
}
