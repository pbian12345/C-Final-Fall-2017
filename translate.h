#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "graph.h"

class translate
{
public:
    static sf::Vector2f domain_to_window(sf::Vector2f input, double dom_low, double dom_high);
};

#endif // TRANSLATE_H
