/*
*   This file is part of Screen-Stuff
*   Copyright (C) 2019 VoltZ
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#include "gui.hpp"

#include "screens/test.hpp"

bool exiting = false;

int main() {
	// Init libs.
	Gui::initialize();
	Gui::setScreen(std::make_unique<TestScreen>());

	// Main loop.
	while (aptMainLoop() && !exiting)
	{
		hidScanInput();
		u32 hDown = hidKeysDown();
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, C2D_Color32(0, 0, 0, 255));
		C2D_TargetClear(bottom, C2D_Color32(0, 0, 0, 255));
		Gui::mainLoop(hDown);
		C3D_FrameEnd(0);
	}

	// Exit everything.
	Gui::deinitialize();
}