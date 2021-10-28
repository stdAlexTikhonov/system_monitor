#include "processor.h"

#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  prev_total_ = total_;
  prev_active_ = active_;

  total_ = LinuxParser::Jiffies();
  active_ = LinuxParser::ActiveJiffies();

  float work_over_period = float(active_) - float(prev_active_);
  float total_over_period = float(total_) - float(prev_total_);

  return work_over_period / total_over_period;
}
