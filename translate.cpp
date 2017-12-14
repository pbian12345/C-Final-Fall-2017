#include "translate.h"

sf::Vector2f translate::domain_to_window(sf::Vector2f input, double dom_low, double dom_high){
    sf::Vector2f output(input.x, input.y);
    sf::Vector2f origin(dom_high * (SCREEN_WIDTH/(dom_high - dom_low)), 0.5 * SCREEN_HEIGHT);
    output.x = origin.x + (output.x * (SCREEN_WIDTH/(dom_high - dom_low)));
    output.y = SCREEN_HEIGHT - (origin.y + (output.y * (SCREEN_WIDTH/(dom_high - dom_low))));
    return output;
}
