#include "Timespec.hpp"

#include <time.h>

#define nsec_per_sec 1000000000

void operator+=(struct timespec& timespec, long nsec) {
  timespec.tv_nsec += nsec;
  if (timespec.tv_nsec >= nsec_per_sec) {
    timespec.tv_nsec -= nsec_per_sec;
    ++timespec.tv_sec;
  }
}

void operator+=(struct timespec& lhs, const struct timespec& rhs) {
  lhs.tv_sec += rhs.tv_sec;
  lhs.tv_nsec += rhs.tv_nsec;
  if (lhs.tv_nsec >= nsec_per_sec) {
    lhs.tv_nsec -= nsec_per_sec;
    ++lhs.tv_sec;
  }
}

void operator-=(struct timespec& lhs, const struct timespec& rhs) {
  lhs.tv_sec -= rhs.tv_sec;
  lhs.tv_nsec -= rhs.tv_nsec;
  if (lhs.tv_nsec < 0) {
    --lhs.tv_sec;
    lhs.tv_nsec += nsec_per_sec;
  }
}

bool operator>(const struct timespec& lhs, const struct timespec& rhs) {
  if (lhs.tv_sec > rhs.tv_sec) {
    return true;
  } else if (lhs.tv_sec == rhs.tv_sec) {
    if (lhs.tv_nsec > rhs.tv_nsec) {
      return true;
    }
  }

  return false;
}

bool operator<(const struct timespec& lhs, const struct timespec& rhs) {
  return rhs > lhs;
}

bool operator<=(const struct timespec& lhs, const struct timespec& rhs) {
  return !(lhs > rhs);
}
