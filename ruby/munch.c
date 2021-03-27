#include <math.h>
#include <stdbool.h>

#include "../c/munch.h"

#include "extconf.h"
#include "ruby.h"


VALUE rb_is_munch(VALUE self, VALUE rb_i) {
  int i = NUM2INT(rb_i);
  return is_munch(i) ? Qtrue : Qfalse;
}

void Init_munch() {
  VALUE mod = rb_define_module("Munch");
  rb_define_method(mod, "is_munch", rb_is_munch, 1);
}
