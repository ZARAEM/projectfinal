#include "Menu.h"

void Menu::initialise() {
	m_game_state.next_scene_id = -1;
	m_number_of_enemies = 0;
}

void Menu::update(float delta_time) {}

void Menu::render(ShaderProgram* program) {
	GLuint texture_id = Utility::load_texture("assets/font1.png");

	Utility::draw_text(program, texture_id, "test", 0.3f, 0.0f, glm::vec3(-1.65f, 1.5, 0));
}