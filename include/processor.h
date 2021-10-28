#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
                        // TODO: Declare any necessary private members
 private:
  long prev_active_ = 1, prev_total_ = 1;
  long active_ = 2, total_ = 2;
};

#endif