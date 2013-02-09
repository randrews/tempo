/*
  ltaglib - a TagLib wrapper for Lua.
  Copyright (c) 2013 Ross Andrews

  This file is part of ltaglib.

  ltaglib is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  ltaglib is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with ltaglib.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <tag.h>
#include <fileref.h>
#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

extern "C" {
    int luaopen_ltaglib(lua_State*);
}
