
#include "cinder/CinderImGui.h"
#include "GShape.h"

void GShape::drawBase()
{
	std::string labelId = std::to_string(mId);

	ImGui::TextDisabled("%-10s %d", "ID:", mId);

	ImGui::Text("%-10s", "Name:");
	ImGui::InputText(("##name" +labelId).c_str(), name, 32);

	ImGui::Text("%-10s", "Is Moving:");
	ImGui::Checkbox(("##moving" + labelId).c_str(), &isMoving);

	ImGui::Separator();

	ImGui::Text("%-10s", "Location:");
	ImGui::DragFloat2(("##pos" + labelId).c_str(), &location[0]);

	ImGui::Text("%-10s", "Color:");
	ImGui::ColorEdit3(("##col" + labelId).c_str(), &color[0]);

	ImGui::Text("%-10s", "Velocity:");
	ImGui::DragFloat2(("##vel" + labelId).c_str(), &velocity[0]);
}

// We use initializer list so we do not double initialize the class variables (like glm::vec2)
GShape::GShape(int id, glm::vec2 loc, ci::Color col, glm::vec2 vel)
	: mId(id), location(loc), color(col), velocity(vel)
{
	isMoving = true;
	std::snprintf(name, 32, "Shape %d", id);	
}

void GCircle::draw(ImDrawList* drawList)
{
	drawList->AddCircleFilled(ImVec2(location.x, location.y), 
		radius, 
		ImGui::ColorConvertFloat4ToU32(ImVec4(color.r, color.g, color.b, 1.f)), 32);
}

bool GCircle::isHovered(glm::vec2 point)
{
	if (glm::distance(location, point) < radius)
		return true;
	return false;
}

void GSquare::draw(ImDrawList* drawList)
{
	drawList->AddRectFilled(ImVec2(location.x - side / 2.f, location.y - side / 2.f), 
		ImVec2(location.x + side / 2.f, location.y + side / 2.f), 
		ImGui::ColorConvertFloat4ToU32(ImVec4(color.r, color.g, color.b, 1.f)));
}

bool GSquare::isHovered(glm::vec2 point)
{
	if (point.x > location.x - side / 2.f && point.x < location.x + side / 2.f &&
		point.y > location.y - side / 2.f && point.y < location.y + side / 2.f)
		return true;
	return false;
}

void GCircle::drawInfo()
{
	drawBase();
	ImGui::Text("Radius:");
	ImGui::DragFloat(("##rad" + std::to_string(mId)).c_str(), &radius);
}

void GCircle::moveShape(float width, float height)
{
	if (isMoving) {
		glm::vec2 newPos = location + velocity;

		if (newPos.x - radius < 0.f || newPos.x + radius > width)
			velocity.x = -velocity.x;

		if (newPos.y - radius < 0.f || newPos.y + radius > height)
			velocity.t = -velocity.y;

		location = location + velocity;
	}
}

void GSquare::drawInfo()
{
	drawBase();
	ImGui::Text("Side:");
	ImGui::DragFloat(("##side"+std::to_string(mId)).c_str(), &side);
}

void GSquare::moveShape(float width, float height)
{
	if (isMoving) {
		glm::vec2 newPos = location + velocity;

		if (newPos.x - side / 2.f < 0.0f || newPos.x + side / 2.f > width)
			velocity.x = -velocity.x;

		if (newPos.y - side / 2.f < 0.0f || newPos.y + side / 2.f > height)
			velocity.t = -velocity.y;

		location = location + velocity;
	}
}




