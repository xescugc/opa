#include "glob.h"
#include "stdio.h"
#include "fnmatch.h"


opa_value *opa_glob_match(opa_value *p, opa_value *d, opa_value *m)
{
  opa_string_t *ps = opa_cast_string(p);
  opa_string_t *ds = opa_cast_string(d);
  opa_string_t *ms = opa_cast_string(m);

  int r = fnmatch(ps->v, ms->v, 0);

  if (r == 0)
  {
    return opa_boolean(true);
  }
  return opa_boolean(false);
}
