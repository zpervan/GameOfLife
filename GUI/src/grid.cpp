#include "GUI/src/grid.h"

void Grid::SetGridSize(uint row, uint column) {
    if ((row < minimum_row_size_) || (column < minimum_column_size_)) {
        throw std::invalid_argument("Grid size is not valid! It should at least have 1 row and 3 columns!");
    }

    if ((row > maximum_size_) || (column > maximum_size_)) {
        throw std::invalid_argument(
                "Grid cell size is too small. Use row and column values which is smaller or equal to 300. ");
    }

    grid_size_ = GridSize{row, column};
}

std::vector<sf::RectangleShape> Grid::CreateGrid() {
    if ((grid_size_.row == 0) || (grid_size_.column == 0)) {
        throw std::invalid_argument("Grid size is not set, but it should be!");
    }

    CalculateGridCellSize();
    CalculateLineThickness();

    CalculateHorizontalGridStartPosition();
    CalculateVerticalGridStartPosition();

    CreateHorizontalGrid();
    CreateVerticalGrid();

    return grid_shapes_;
}

sf::RectangleShape Grid::UpdateCellState(bool cell_state, uint row, uint column) {
    sf::RectangleShape cell_state_shape;
    cell_state_shape.setSize({grid_cell_size_, grid_cell_size_});
    cell_state_shape.setPosition(CalculateCellStatePosition(row, column));
    if (cell_state == 0) cell_state_shape.setFillColor(sf::Color::Black);

    return cell_state_shape;
}

void Grid::CalculateGridCellSize() {
    while (IsGridLargerThanViewportScreen()) {
        grid_cell_size_ -= 0.1;
    }
}

void Grid::CalculateLineThickness() {
    const uint maximum_grid_size_value = grid_size_.row > grid_size_.column ? grid_size_.row : grid_size_.column;
    if (maximum_grid_size_value > 20) line_thickness_ = 1.0;
}

bool Grid::IsGridLargerThanViewportScreen() const {
    return ((grid_size_.row * grid_cell_size_) > Config::Viewport::SCREEN_SIZE.y) ||
           ((grid_size_.column * grid_cell_size_) > Config::Viewport::SCREEN_SIZE.x);
}

void Grid::CalculateHorizontalGridStartPosition() {
    float horizontal_half_grid_dimension{grid_cell_size_ * (static_cast<float>(grid_size_.column) / 2.0f)};
    horizontal_start_position_ = (Config::MainMenu::WIDTH + horizontal_center_point_) - horizontal_half_grid_dimension;
}

void Grid::CalculateVerticalGridStartPosition() {
    float vertical_half_grid_size{grid_cell_size_ * (static_cast<float>(grid_size_.row) / 2.0f)};
    vertical_start_position_ = (Config::MenuBar::VERTICAL_SIZE + vertical_center_point_) - vertical_half_grid_size;
}

void Grid::CreateHorizontalGrid() {
    const float line_width{(grid_cell_size_ * grid_size_.column) + line_thickness_};

    for (std::size_t row{0}; row <= grid_size_.row; row++) {
        sf::RectangleShape line;

        line.setSize({line_width, line_thickness_});
        line.setFillColor(sf::Color::Black);

        const float vertical_position{vertical_start_position_ + (grid_cell_size_ * row)};
        line.setPosition({horizontal_start_position_, vertical_position});

        grid_shapes_.emplace_back(std::move(line));
    }
}

void Grid::CreateVerticalGrid() {
    const float line_height{grid_cell_size_ * grid_size_.row};

    for (std::size_t column{0}; column <= grid_size_.column; column++) {
        sf::RectangleShape line;

        line.setSize({line_thickness_, line_height});
        line.setFillColor(sf::Color::Black);

        const float horizontal_position{horizontal_start_position_ + (grid_cell_size_ * column)};
        line.setPosition({horizontal_position, vertical_start_position_});

        grid_shapes_.emplace_back(std::move(line));
    }
}

sf::Vector2f Grid::CalculateCellStatePosition(uint row, uint column) const {
    const float vertical_position{vertical_start_position_ + (grid_cell_size_ * row)};
    const float horizontal_position{horizontal_start_position_ + (grid_cell_size_ * column)};

    return {horizontal_position, vertical_position};
}

