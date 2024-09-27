#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderImGui.h"

#include "GShape.h"

using namespace ci;
using namespace ci::app;

// We'll create a new Cinder Application by deriving from the App class.
class BasicApp : public App {
public:
	// Cinder will call 'mouseDrag' when the user moves the mouse while holding one of its buttons.
	// See also: mouseMove, mouseDown, mouseUp and mouseWheel.
	void mouseDrag(MouseEvent event) override;

	// Cinder will call 'keyDown' when the user presses a key on the keyboard.
	// See also: keyUp.
	void keyDown(KeyEvent event) override;

	// Override the Setup function so we can initialize ImGUI
	void setup() override;

	// Override the Update data function
	void update() override;

	// Cinder will call 'draw' each time the contents of the window need to be redrawn.
	void draw() override;

private:
	// This will maintain a list of points which we will draw line segments between
	std::vector<vec2> mPoints;

	// Bool for toggling Play/Pause state
	bool mIsPlaying = true;

	// Left Window Hovered
	bool mLeftWindowHovered = false;

	// Vector of shapes to be drawn
	std::vector <std::unique_ptr<GShape>> mShapes;

	// Maximum Speed of created shapes
	float mMaxSpeed = 1.0f;

	int mSelectedShape = -1;
	int mHoveredShape = -1;
	ImVec2 lastMousePos;

	// Handle for generating Shape IDs
	static inline int mLastId = 0;
	static inline int next_id() { return mLastId++; }
private:
	// Create a random shape
	void createRandomShape();
};
