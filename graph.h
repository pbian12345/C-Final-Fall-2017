#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "rpn.h"
#include "shunting_yard.h"
#include "constants.h"
#include "translate.h"

class graph
{
private:
    double _domain_low;
    double _domain_high;
    double _range_low;
    double _range_high;
    queue<token*> _function;
public:
    graph();
    graph(string temp);
    void set_function(string fcn_input);
    void set_domain(double nlow, double nhigh);
    double get_dom_low() const {return _domain_low;}
    double get_dom_high() const {return _domain_high;}
    void Draw(sf::RenderWindow& window);
};

#endif // GRAPH_H
