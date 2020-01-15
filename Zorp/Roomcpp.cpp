#include "Roomh.h"
#include "GameDefines.h"
#include "Powerup.h"
#include "Player.h"
#include "Food.h"
#include <iostream>

Room::Room() : m_type{ EMPTY }, m_mapPosition{ 0, 0 }, m_powerup{ nullptr }, m_enemy{ nullptr }, m_food{ nullptr }
{
}

Room::~Room()
{
}

void Room::setPosition(Point2D position)
{
	m_mapPosition = position;
}

void Room::setType(int type)
{
	m_type = type;
}

int Room::getType()
{
	return m_type;
}

void Room::draw()
{
	// find the console output position
	int outX = INDENT_X + (6 * m_mapPosition.x) + 1;
	int outY = MAP_Y + m_mapPosition.y;

	// jump to the correct location
	std::cout << CSI << outY << ";" << outX << "H";
	// draw the room
	switch (m_type) {
	case EMPTY:
		if (m_enemy != nullptr) {
			std::cout << "[ " << RED << "\x94" << RESET_COLOR << " ] ";
			break;
		}
		if (m_powerup != nullptr) {
			std::cout << "[ " << YELLOW << "$" << RESET_COLOR << " ] ";
			break;
		}
		if (m_food != nullptr) {
			std::cout << "[ " << WHITE << "\xcf" << RESET_COLOR << " ] ";
			break;
		}
		std::cout << "[ " << GREEN << "\xb0" << RESET_COLOR << " ] ";
		break;
	case ENTRANCE:
		std::cout << "[ " << WHITE << "\x9d" << RESET_COLOR << " ] ";
		break;
	case EXIT:
		std::cout << "[ " << WHITE << "\xFE" << RESET_COLOR << " ] ";
		break;
	}
}

void Room::drawDescription()
{
	// reset draw colors
	std::cout << RESET_COLOR;
	// jump to the correct location
	std::cout << CSI << ROOM_DESC_Y << ";" << 0 << "H";
	// Delete 4 lines and insert 4 empty lines
	std::cout << CSI << "4M" << CSI << "4L" << std::endl;

	// write description of current room
	switch (m_type) {
	case EMPTY:
		if (m_enemy != nullptr) {
			std::cout << INDENT << RED << "BEWARE." << RESET_COLOR << " An enemy is approaching." << std::endl;
			break;
		}
		if (m_powerup != nullptr) {
			std::cout << INDENT << "There appears to be some treasure here. Perhaps you should investigate futher." << std::endl;
			break;
		}
		if (m_food != nullptr) {
			std::cout << INDENT << "You smell a recently extinguished campfire, perhaps left by a previous traveller." << std::endl;
			break;
		}
		std::cout << INDENT << "You are in an empty meadow. There is nothing of note here." << std::endl;
		break;
	case ENTRANCE:
		std::cout << INDENT << "The entrance you used to enter this maze is blocked. There is no going back." << std::endl;
		break;
	case EXIT:
		std::cout << INDENT << "Despite all odds, you made it to the exit. Congratulations." << std::endl;
		break;
	}

}
