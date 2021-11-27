#include "../Headers/model.h"
#include "../Headers/passage.h"
#include "../Headers/door.h"
#include "../Headers/none.h"
#include "../Headers/floor.h"
#include "../Headers/vwall.h"
#include "../Headers/hwall.h"
#include "../Headers/textview.h"
#include "../Headers/shade.h"

using std::make_unique;
using std::make_pair;

Model::Model() :
m_player{nullptr},
m_move{true},
m_view{make_unique<TextView>()},
m_entities{},
m_tiles{}
{}

Entity *Model::generateCharacter(Utility::Race race, Utility::Loc l)
{
    switch(race)
    {
        case Utility::Race::Shade:
            m_entities.push_back(make_unique<Shade>());
            break;
        // TODO: Cases for other races
        default:
            break;
    }

    Entity *character = m_entities.back().get();

    if (l == NEEDS_RANDOM)
    {
        // TODO: Random character location in a chamber
        // update 'l' with new random location.
    }

    int indice = l.first + l.second * BOARD_WIDTH;
    m_state[indice].second = character;
    return character;
}

Entity *Model::generatePlayer(Utility::Race race)
{
    // Temporarily assign a specified location until random works.
    m_player = generateCharacter(race, Utility::Loc(15, 15));

    return m_player;
}

Tile *Model::generateTile(Utility::Terrain t)
{
    switch(t)
    {
        case Utility::Terrain::Floor:
            m_tiles.push_back(make_unique<Floor>());
            break;
        case Utility::Terrain::Passage:
            m_tiles.push_back(make_unique<Passage>());
            break;
        case Utility::Terrain::Door:
            m_tiles.push_back(make_unique<Door>());
            break;
        case Utility::Terrain::HWall:
            m_tiles.push_back(make_unique<HWall>());
            break;
        case Utility::Terrain::VWall:
            m_tiles.push_back(make_unique<VWall>());
            break;
        case Utility::Terrain::None:
            m_tiles.push_back(make_unique<None>());
            break;
        default:
            break;
    }
    Tile *tile = m_tiles.back().get();
    m_state.push_back(make_pair(tile, nullptr));
    return tile;
}

void Model::generateLayout(vector<Utility::Terrain> layout)
{
    for (auto t : layout) generateTile(t);
}

bool Model::playerMove(Utility::Direction d)
{
    // Move and update state.
    return false;
}

bool Model::playerUse(Utility::Direction d)
{
    // Use and update state.
    return false;
}

bool Model::playerAttack(Utility::Direction d)
{
    // Attack and update state.
    return false;
}

void Model::restart()
{}

void Model::quit()
{}

void Model::render()
{
    m_view->render(m_state);
}