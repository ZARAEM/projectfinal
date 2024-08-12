#include "LevelA.h"
#include "Utility.h"

#define LEVEL_WIDTH 16
#define LEVEL_HEIGHT 16

constexpr char SPRITESHEET_FILEPATH[] = "assets/characters.png";

unsigned int LEVELA_DATA[] =
{
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
};

LevelA::~LevelA()
{
    delete [] m_game_state.enemies;
    delete    m_game_state.player;
    delete    m_game_state.map;
    Mix_FreeMusic(m_game_state.bgm);
}

void LevelA::initialise()
{
    m_game_state.next_scene_id = -1;
    
    GLuint dungeon_texture_id = Utility::load_texture("assets/tileset.png");

    m_game_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, LEVELA_DATA, dungeon_texture_id, 0.8f, 10, 10);
    
    // Code from main.cpp's initialise()
    // Existing
    int player_walking_animation[4][4] =
    {
        { 0, 1, 0, 1 },  // for George to move to the left,
        { 0, 1, 0, 1 }, // for George to move to the right,
        { 0, 1, 0, 1 }, // for George to move upwards,
        { 0, 1, 0, 1 }   // for George to move downwards
    };

    glm::vec3 acceleration = glm::vec3(0.0f, -4.81f, 0.0f);
    
    GLuint player_texture_id = Utility::load_texture(SPRITESHEET_FILEPATH);
    
    m_game_state.player = new Entity(
        player_texture_id,         // texture id
        1.0f,                      // speed
        acceleration,              // acceleration
        0.0f,                      // jumping power
        player_walking_animation,  // animation index sets
        0.0f,                      // animation time
        2,                         // animation frame amount
        0,                         // current animation index
        7,                         // animation column amount
        2,                         // animation row amount
        0.2f,                      // width
        0.2f,                      // height
        PLAYER
    );
    m_game_state.player->set_acceleration(glm::vec3(0.0f, 0.0f, 0.0f));
    m_game_state.player->set_speed(1.0f);
    m_game_state.player->set_position(glm::vec3(0.0f, 0.0f, 0.0f));
    
    /**
     BGM and SFX
     */
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    
    m_game_state.bgm = Mix_LoadMUS("assets/bgm.wav");
    Mix_PlayMusic(m_game_state.bgm, -1);
    Mix_VolumeMusic(1.0f);
}

void LevelA::update(float delta_time)
{
    //m_game_state.player->update(delta_time, m_game_state.player, m_game_state.enemies, ENEMY_COUNT, m_game_state.map);
    
    //if (m_game_state.player->get_position().y < -10.0f) m_game_state.next_scene_id = 1;
}

void LevelA::render(ShaderProgram *program)
{
    m_game_state.map->render(program);
    m_game_state.player->render(program);
}
