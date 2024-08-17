#include "Schedule.hpp"

#include <sched.h>
#include <cassert>

void setSchedulePriorityMax() {
  struct sched_param schedulerParameter;
  const int schedulerPriorityMax = sched_get_priority_max(SCHED_FIFO);
  assert(schedulerPriorityMax != -1);
  schedulerParameter.sched_priority = schedulerPriorityMax;
  assert(sched_setscheduler(0, SCHED_FIFO, &schedulerParameter) != -1);
}
