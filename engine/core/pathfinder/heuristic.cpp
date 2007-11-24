/***************************************************************************
 *   Copyright (C) 2005-2007 by the FIFE Team                              *
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

// Standard C++ library includes
#include <cmath>

// 3rd party library includes

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
#include "heuristic.h"

namespace FIFE {

	Heuristic* Heuristic::getHeuristic(const std::string& cellgridType) {
		if(cellgridType == "square") {
			return SquareGridHeuristic::instance();
		}

		if(cellgridType == "hexagonal") {
			return HexGridHeuristic::instance();
		}

		return 0;
	}

	SquareGridHeuristic::SquareGridHeuristic(void) {
	}

	SquareGridHeuristic::~SquareGridHeuristic(void) {
	}

	float SquareGridHeuristic::calculate(const ModelCoordinate& current, const ModelCoordinate& dest) {
		return (float)(abs(dest.x - current.x) + abs(dest.y - current.y));
	}

	HexGridHeuristic::HexGridHeuristic(void) {
	}

	HexGridHeuristic::~HexGridHeuristic(void) {
	}

	float HexGridHeuristic::calculate(const ModelCoordinate& current, const ModelCoordinate& dest) {
		float cost = (float)(((dest.x - current.x) * (dest.x - current.x)) +
					 ((dest.y - current.y) * (dest.y - current.y)) +
					 ((dest.x - current.x) * (dest.y - current.y)));
		return cost;
	}
}