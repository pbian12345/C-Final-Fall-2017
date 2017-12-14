#include "graph.h"

graph::graph(){
    _domain_high = 10;
    _domain_low = -10;
    _range_high = 5;
    _range_low = -5;
}

graph::graph(string temp)
{
    _domain_high = 10;
    _domain_low = -10;
    _range_high = 5;
    _range_low = -5;
    set_function(temp);
}
void graph::set_function(string fcn_input){
    shunting_yard temp(token::tokenize(fcn_input));
    temp.sh_yrd();
    _function = temp.get_postfix();
}
void graph::set_domain(double nlow, double nhigh){
    _domain_low = nlow;
    _domain_high = nhigh;
}

void graph::Draw(sf::RenderWindow &window){
    //first, the axes
    sf::VertexArray axis_x(sf::LinesStrip, 2);
    axis_x[0] = translate::domain_to_window(sf::Vector2f(100,0), _domain_low, _domain_high);
    axis_x[1] = translate::domain_to_window(sf::Vector2f(-100,0), _domain_low, _domain_high);
    window.draw(axis_x);
    sf::VertexArray axis_y(sf::LinesStrip, 2);
    axis_y[0] = translate::domain_to_window(sf::Vector2f(0,100), _domain_low, _domain_high);
    axis_y[1] = translate::domain_to_window(sf::Vector2f(0,-100), _domain_low, _domain_high);
    window.draw(axis_y);

//    sf::VertexArray axis_x(sf::LinesStrip, 2);
//    axis_x[0] = sf::Vector2f(0,SCREEN_HEIGHT/2.0);
//    axis_x[1] = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT/2.0);
//    window.draw(axis_x);
//    sf::VertexArray axis_y(sf::LinesStrip, 2);
//    axis_y[0] = sf::Vector2f(SCREEN_WIDTH/2.0, 0);
//    axis_y[1] = sf::Vector2f(SCREEN_WIDTH/2.0, SCREEN_HEIGHT);
//    window.draw(axis_y);

    //now for function
    sf::VertexArray fcn_output(sf::Points);
    int count = 0;
    for (double i = _domain_low; i <= _domain_high; i+=(1.0/(SCREEN_WIDTH/(_domain_high - _domain_low))), ++count){
        sf::Vector2f temp_fcn(i, rpn::calculate(_function, i));
        temp_fcn = translate::domain_to_window(temp_fcn, _domain_low, _domain_high);
        fcn_output.append(temp_fcn);
        fcn_output[count].color = sf::Color::Red;
    }
    window.draw(fcn_output);
}
