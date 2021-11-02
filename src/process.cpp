#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  enum CPUStates { utime = 0, stime, cutime, cstime, starttime };

  long uptime = LinuxParser::UpTime();
  vector<long> active_jiffies = LinuxParser::ActiveJiffies(pid_);

  long total_time =
      active_jiffies[CPUStates::utime] + active_jiffies[CPUStates::stime] +
      active_jiffies[CPUStates::cutime] + active_jiffies[CPUStates::cstime];

  float seconds =
      uptime - (active_jiffies[CPUStates::starttime] / sysconf(_SC_CLK_TCK));

  float cpu_usage = ((total_time / sysconf(_SC_CLK_TCK)) / seconds);
  cpu_usage_ = cpu_usage;

  return cpu_usage;
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
  return this->cpu_usage_ > a.cpu_usage_;
}