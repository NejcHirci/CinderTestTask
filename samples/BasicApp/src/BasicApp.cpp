#include "BasicApp.h"

void prepareSettings( BasicApp::Settings* settings )
{
	settings->setMultiTouchEnabled( false );
}

void BasicApp::mouseDrag( MouseEvent event )
{
	// Store the current mouse position in the list.
	mPoints.push_back( event.getPos() );
}

void BasicApp::keyDown( KeyEvent event )
{
	if( event.getChar() == 'f' ) {
		// Toggle full screen when the user presses the 'f' key.
		setFullScreen( ! isFullScreen() );
	}
	else if( event.getCode() == KeyEvent::KEY_SPACE ) {
		// Clear the list of points when the user presses the space bar.
		mPoints.clear();
	}
	else if( event.getCode() == KeyEvent::KEY_ESCAPE ) {
		// Exit full screen, or quit the application, when the user presses the ESC key.
		if( isFullScreen() )
			setFullScreen( false );
		else
			quit();
	}
}

void BasicApp::setup()
{
	// Initialize ImGUI
	ImGui::Initialize();
}

void BasicApp::update()
{
	// Reset the hovered shape because use is internal to update function
	mHoveredShape = -1;
	lastMousePos = ImGui::GetMousePos();

	// Start a new ImGUI frame
	ImGuiWindowFlags window_flags = 0;
	window_flags |= ImGuiWindowFlags_MenuBar;
	window_flags |= ImGuiWindowFlags_NoTitleBar;
	window_flags |= ImGuiWindowFlags_NoCollapse;
	window_flags |= ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoResize;
	window_flags |= ImGuiWindowFlags_NoDecoration;

	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(getWindowWidth(), getWindowHeight()));

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0,0));

	if (!ImGui::Begin("Playground", nullptr, window_flags))
	{
		ImGui::End();
		return;
	}

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			bool OpenPrevious = false;
			ImGui::MenuItem("Open previous", NULL, &OpenPrevious);
			ImGui::EndMenu();
		}

		if (ImGui::Button(mIsPlaying ? "Pause" : "Play"))
			mIsPlaying = !mIsPlaying;
		
		ImGui::EndMenuBar();
	}


	ImGuiWindowFlags child_flags = 0;
	child_flags |= ImGuiWindowFlags_NoTitleBar;
	child_flags |= ImGuiWindowFlags_NoCollapse;
	child_flags |= ImGuiWindowFlags_NoMove;
	child_flags |= ImGuiWindowFlags_NoResize;
	child_flags |= ImGuiWindowFlags_NoDecoration;


	if (ImGui::BeginChild(2, ImVec2(ImGui::GetWindowWidth() * 0.75f, ImGui::GetWindowHeight())))
	{
		// Render shapes
		auto drawList = ImGui::GetWindowDrawList();
		for (int i = 0; i < mShapes.size(); i++)
		{
			// Update the shape position
			if (mIsPlaying)
			{
				mShapes[i]->moveShape(ImGui::GetWindowWidth(), ImGui::GetWindowHeight());
			}

			mShapes[i]->draw(drawList);
			if (mShapes[i]->isHovered(lastMousePos))
				mHoveredShape = i;
		}
		ImGui::EndChild();
	}

	if (ImGui::IsItemClicked(ImGuiMouseButton_Left))
	{
		mSelectedShape = mHoveredShape;
		if (mSelectedShape < 0)
			createRandomShape();

	}
	else if (ImGui::IsItemClicked(ImGuiMouseButton_Right))
	{
		mSelectedShape = mHoveredShape;
		if (mSelectedShape >= 0)
			ImGui::OpenPopup("Shape_Context_Menu");
	}

	// Define the popup used for any of the shape items
	if (ImGui::BeginPopup("Shape_Context_Menu"))
	{
		if (ImGui::Selectable("Remove this shape"))
		{
			mShapes.erase(mShapes.begin() + mSelectedShape);
			mSelectedShape = -1;
			ImGui::CloseCurrentPopup();
		}
		if (mSelectedShape >= 0 && ImGui::Selectable(mShapes[mSelectedShape]->isMoving ? "Stop" : "Play"))
		{
			mShapes[mSelectedShape]->isMoving = !mShapes[mSelectedShape]->isMoving;
		}
		ImGui::EndPopup();
	}

	ImGui::SameLine();

	if (ImGui::BeginChild(3, ImVec2(getWindowWidth() * 0.25f, ImGui::GetWindowHeight())))
	{

		if (mShapes.size() > 0)
		{
			ImGui::ListBoxHeader("", ImVec2(-FLT_MIN, ImGui::GetWindowHeight() * 0.25f));

			for (int i = 0; i < mShapes.size(); i++)
			{
				bool is_selected = (mSelectedShape == i);
				if (ImGui::Selectable(mShapes[i]->name, is_selected))
					mSelectedShape = i;
			}

			ImGui::ListBoxFooter();
		}

		if (mSelectedShape >= 0)
		{
			ImGui::TextWrapped("Shape Info", "");
			ImGui::Separator();
			mShapes[mSelectedShape]->drawInfo();
		} 
		else
		{
			ImGui::TextDisabled("Select an object");
		}

		ImGui::EndChild();
	}

	ImGui::PopStyleVar();

	// End the Playground window
	ImGui::End();
}

void BasicApp::draw()
{
	// Clear the contents of the window. This call will clear
	// both the color and depth buffers. 
	gl::clear( Color::gray( 0.1f ) );

	// Set the current draw color to orange by setting values for
	// red, green and blue directly. Values range from 0 to 1.
	// See also: gl::ScopedColor
	gl::color( 1.0f, 0.0f, 0.0f );

	// We're going to draw a line through all the points in the list
	// using a few convenience functions: 'begin' will tell OpenGL to
	// start constructing a line strip, 'vertex' will add a point to the
	// line strip and 'end' will execute the draw calls on the GPU.
	gl::begin( GL_LINE_STRIP );
	for( const vec2 &point : mPoints ) {
		gl::vertex( point );
	}
	gl::end();
}

void BasicApp::createRandomShape()
{

	float r = static_cast<float>(rand()) / RAND_MAX;
	float g = static_cast<float>(rand()) / RAND_MAX;
	float b = static_cast<float>(rand()) / RAND_MAX;
	float velX =   static_cast<float>(rand()) / RAND_MAX - 0.5f * mMaxSpeed;
	float velY = -(static_cast<float>(rand()) / RAND_MAX - 0.5f) * mMaxSpeed; 

	if (rand() % 2 > 0)
	{
		GCircle circle {
			BasicApp::next_id(),
			lastMousePos,
			Color(r, g, b),
			vec2(velX, 1.0f),
			static_cast<float>(rand()) / RAND_MAX * 100.0f + 5
		};
		mShapes.push_back(std::make_unique<GCircle>(circle));
	}
	else
	{
		GSquare square{
			BasicApp::next_id(),
			lastMousePos,
			Color(r, g, b),
			vec2(velX, 1.0f),
			static_cast<float>(rand() % 200 + 5)
		};
		mShapes.push_back(std::make_unique<GSquare>(square));
	}
}

// This line tells Cinder to actually create and run the application.
CINDER_APP( BasicApp, RendererGl, prepareSettings )
