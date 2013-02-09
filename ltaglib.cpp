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

#include "ltaglib.h"

int read(lua_State *lua){
    const char* fname = luaL_checkstring(lua, 1);
    TagLib::FileRef f(fname);
    lua_newtable(lua);

    lua_pushstring(lua, "title");
    lua_pushstring(lua, f.tag()->title().toCString(true));
    lua_settable(lua, -3);

    lua_pushstring(lua, "artist");
    lua_pushstring(lua, f.tag()->artist().toCString(true));
    lua_settable(lua, -3);

    lua_pushstring(lua, "album");
    lua_pushstring(lua, f.tag()->album().toCString(true));
    lua_settable(lua, -3);

    lua_pushstring(lua, "comment");
    lua_pushstring(lua, f.tag()->comment().toCString(true));
    lua_settable(lua, -3);

    lua_pushstring(lua, "genre");
    lua_pushstring(lua, f.tag()->genre().toCString(true));
    lua_settable(lua, -3);

    lua_pushstring(lua, "year");
    lua_pushinteger(lua, f.tag()->year());
    lua_settable(lua, -3);

    lua_pushstring(lua, "track");
    lua_pushinteger(lua, f.tag()->track());
    lua_settable(lua, -3);

    return 1;
}

int luaopen_ltaglib(lua_State *lua){
    luaL_Reg ltaglib[] = {
        {"read", read},
        {NULL, NULL}
    };

    luaL_openlib(lua, "ltaglib", ltaglib, 0);
    return 0;
}
