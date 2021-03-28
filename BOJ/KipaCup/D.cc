#include "solution.h"

bool locked = false;

void init() {
	// TODO: put any initialization here...
}

bool pick(int value) {
  if (locked) return locked = false;
  if (value > 200) {
    return locked = true;
  }
	return false;
}
