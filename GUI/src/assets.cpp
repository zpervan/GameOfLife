#include "GUI/src/assets.h"

#include "ThirdParty/fmt/include/fmt/core.h"
#include <cassert>

void Assets::Initialize() {
    play_button_ = LoadAsset("play_button.png");
    pause_button_ = LoadAsset("pause_button.png");
    stop_button_ = LoadAsset("stop_button.png");
    white_cell_ = LoadAsset("white_cell.png");
    black_cell_ = LoadAsset("black_cell.png");
}

std::unique_ptr<sf::Texture> Assets::LoadAsset(const std::string &asset_name) {
    auto asset_object{std::make_unique<sf::Texture>()};

    const std::string asset_path{fmt::format("Assets/{}", asset_name)};
    assert(asset_object->loadFromFile(asset_path) && fmt::format("Asset {} does not exist!", asset_name).c_str());

    return asset_object;
}

sf::Texture *Assets::GetPlayButton() {
    return play_button_.get();
}

sf::Texture *Assets::GetPauseButton() {
    return pause_button_.get();
}

sf::Texture *Assets::GetStopButton() {
    return stop_button_.get();
}

sf::Texture *Assets::GetWhiteCell() {
    return white_cell_.get();
}

sf::Texture *Assets::GetBlackCell() {
    return black_cell_.get();
}

