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

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>

C3D_RenderTarget* top;
C3D_RenderTarget* bottom;

std::stack<std::unique_ptr<Screen>> screens;

	// Initialize all that stuff.
Result Gui::initialize() {
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();

		// Create screens.
	top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
	return 0;
}

	// Deinit libs.
Result Gui::deinitialize() {
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}

// Screen Stuff.

// Mainloop the GUI.
void Gui::mainLoop(u32 hDown) {
	screens.top()->Draw();
	screens.top()->Logic(hDown);
}

// Set the current Screen.
void Gui::setScreen(std::unique_ptr<Screen> screen)
{
	screens.push(std::move(screen));
}

// Go a Screen back.
void Gui::screenBack()
{
	screens.pop();
}