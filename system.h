#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "shunting_yard.h"
#include "random.h"
#include "translate.h"
#include "graph.h"

using namespace std;
class System
{
private:
    graph _graph_it;
    string _temp_fcn;
public:
    System();
    System(string temp);
    void Draw(sf::RenderWindow& widnow);
    void Input_fcn(std::string input);
    void Pan_right();
    void Pan_left();
    void Zoom_in();
    void Zoom_out();
    graph get_graph() const {return _graph_it;}
};

#endif // SYSTEM_H
