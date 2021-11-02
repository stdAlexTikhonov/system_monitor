#include "format.h"

#include <string>

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function

string Format::Format(int value) {
  return value < 9 ? '0' + std::to_string(value) : std::to_string(value);
}

string Format::ElapsedTime(long seconds) {
  int hours, minutes, seconds_;
  minutes = seconds / 60;
  hours = minutes / 60;
  seconds_ = seconds % 60;
  return Format(hours) + ':' + Format(minutes % 60) + ':' + Format(seconds_);
}
