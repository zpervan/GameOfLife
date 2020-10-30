#ifndef GAMEOFLIFE_GUI_SRC_ASSETS_H_
#define GAMEOFLIFE_GUI_SRC_ASSETS_H_

#include <SFML/Graphics/Texture.hpp>
#include <memory>

/// @brief Contains all initialization and loading logic for assets used in the simulation.
/// @attention In order to save cache (stack) memory, all assets are located on the free store (heap).
class Assets {
public:
    /// @brief Initializes all asset objects on specified asset textures.
    static void Initialize();

    /// Getters
    static sf::Texture *GetPlayButton();

    static sf::Texture *GetPauseButton();

    static sf::Texture *GetStopButton();

    static sf::Texture *GetWhiteCell();

    static sf::Texture *GetBlackCell();

private:
    static std::unique_ptr<sf::Texture> LoadAssetsToTexture(const std::string &asset_name);

    inline static std::unique_ptr<sf::Texture> play_button_;
    inline static std::unique_ptr<sf::Texture> pause_button_;
    inline static std::unique_ptr<sf::Texture> stop_button_;
    inline static std::unique_ptr<sf::Texture> white_cell_;
    inline static std::unique_ptr<sf::Texture> black_cell_;
};

#endif //GAMEOFLIFE_GUI_SRC_ASSETS_H_
