/***************************************************************************
 *   Copyright (C) 2005-2006 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

#ifndef LUASCRIPT_OBJECT_H
#define LUASCRIPT_OBJECT_H

// from the example at: http://lua-users.org/wiki/CppObjectBinding

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include "lunar.h"

namespace FIFE {

	class Object;
	class Object_LuaScript {
		public:
			static const char className[];
			static Lunar<Object_LuaScript>::RegType methods[];

			Object_LuaScript(Object *obj);
			~Object_LuaScript();
			int getPosition(lua_State *L);
			int setPosition(lua_State *L);
			int getTypeName(lua_State *L);
		private:
			Object *m_object;
	};
}
#endif
/* vim: set noexpandtab: set shiftwidth=2: set tabstop=2: */