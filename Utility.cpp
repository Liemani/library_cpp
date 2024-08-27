#include "Utility.hpp"

#include <cstdlib>  // abort()
#include <cstdio> // perror()

void pabortif(bool expression) {
  if (expression) {
    perror("");
    abort();
  }
}
