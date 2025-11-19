#ifndef __CONTEXT__
#define __CONTEXT__

class Context {

public:
  Context();

  void setStarted();
  void setStopped();

  bool isStarted();  
  bool isStopped();
  void reset();

private:

  bool started; 
  bool stopped;
};

#endif
