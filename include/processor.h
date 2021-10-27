#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
                        // TODO: Declare any necessary private members
 private:
  long prev_active_ = 0, prev_total_ = 0;
  long active_ = 0, total_ = 0;
};

#endif