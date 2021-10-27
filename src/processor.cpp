#include "processor.h"

#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  prev_total_ = total_;
  prev_active_ = active_;

  total_ = LinuxParser::Jiffies();
  active_ = LinuxParser::ActiveJiffies();

  long work_over_period = active_ - prev_active_;
  long total_over_period = total_ - prev_total_;

  return active_ / total_;
}
