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

#include <boost/bind.hpp>
#include "debugutils.h"
#include "luagui.h"
#include "video/animation.h"
#include "scriptbase.h"

namespace luaGui {
	Image::Image(lua_State *L) : gcn::AdvImage(lua_tostring(L, 1)) {
	}
	int Image::l_getWidth(lua_State *L) {
		lua_pushnumber(L, gcn::Image::getWidth());
		return 1;
	}
	int Image::l_getHeight(lua_State *L) {
		lua_pushnumber(L, gcn::Image::getHeight());
		return 1;
	}
	int Image::l_setAnimActive(lua_State *L) {
		setAnimActive(lua_toboolean(L, 1));
		return 0;
	}
  int Image::l_setAnimDirection(lua_State *L) {
		setAnimDirection(lua_toboolean(L, 1));
		return 0;
	}
	int Image::l_setAnimEndCallback(lua_State *L) {
		FIFE::Animation* a = getImageAsAnimation();
		if (!a)
			return 0;
		if (lua_isnil(L, 1))
			a->setOnEndCallback(NULL);
		else
			a->setOnEndCallback(boost::bind(&Image::animEndCallback, this));
		m_callbackName = "gui.anim_end.";
		m_callbackName.append(luaL_checkstring(L, 1));
		return 0;
	}
	void Image::animEndCallback() {
		FIFE::ScriptEngine::instance()->callFunction(m_callbackName.c_str());
	}
	const char Image::className[] = "Image";
#define method(class, name) {#name, &class::l_ ## name}

	Lunar<Image>::RegType Image::methods[] = {
		method(Image, getWidth),
		method(Image, getHeight),
		method(Image, setAnimActive),
		method(Image, setAnimDirection),
		method(Image, setAnimEndCallback),
		{0,0}
	};
}
/* vim: set noexpandtab: set shiftwidth=2: set tabstop=2: */