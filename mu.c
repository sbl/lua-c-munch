#include <math.h>
#include <stdbool.h>

#include "lua/lauxlib.h"
#include "lua/lua.h"
#include "lua/lualib.h"

// the exposed function
static int _is_munch(lua_State* l) {
  int i = luaL_checkinteger(l, 1);

  bool result = false;
  int sum = 0;
  for (int n = i; n > 0; n /= 10) {
    int dig = n % 10;
    sum += pow(dig, dig);
  }
  if (sum == i) {
    result = true;
  }

  lua_pushboolean(l, result);

  return 1;
}

static const struct luaL_Reg mulib[] = {
    {"munch", _is_munch},
    {NULL, NULL},
};

int luaopen_mu(lua_State* l) {
  luaL_newlib(l, mulib);
  return 1;
}
