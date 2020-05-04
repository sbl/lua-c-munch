#include <math.h>
#include <stdbool.h>

#include "lua/lauxlib.h"
#include "lua/lua.h"
#include "lua/lualib.h"

static int pwr[10] = {1,    1,     4,      27,       256,
                      3125, 46656, 823543, 16777216, 387420489};

// the exposed function
static int _is_munch(lua_State* l) {
  int i = luaL_checkinteger(l, 1);

  bool result = false;
  int sum = 0;
  for (int n = i; n > 0; n /= 10) {
    int dig = n % 10;
    sum += pwr[dig];
  }
  if (sum == i) {
    result = true;
  }

  lua_pushboolean(l, result);

  return 1;
}

static const struct luaL_Reg mulib[] = {
    {"is_munch", _is_munch},
    {NULL, NULL},
};

int luaopen_mu(lua_State* l) {
  luaL_newlib(l, mulib);
  return 1;
}
