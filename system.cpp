#include "system.h"
#include "random.h"
#include <iostream>
#include <constants.h>

System::System(){

}

System::System(string temp){
    _temp_fcn = temp;
    _graph_it = graph(_temp_fcn);
}


//------------------------------------------------------------------
//------------------------------------------------------------------


void System::Draw(sf::RenderWindow& window){
    window.clear();
    _graph_it.Draw(window);
}
void System::Input_fcn(string input){
    _graph_it.set_function(input);
}
void System::Pan_right(){
    _graph_it.set_domain(_graph_it.get_dom_low() + 1, _graph_it.get_dom_high() + 1);
    cout << "domain: " << _graph_it.get_dom_low() << " : " << _graph_it.get_dom_high() << endl;
}
void System::Pan_left(){
    _graph_it.set_domain(_graph_it.get_dom_low() - 1, _graph_it.get_dom_high() - 1);
    cout << "domain: " << _graph_it.get_dom_low() << " : " << _graph_it.get_dom_high() << endl;
}
void System::Zoom_in(){
    _graph_it.set_domain(_graph_it.get_dom_low() * 0.75, _graph_it.get_dom_high() * 0.75);
}
void System::Zoom_out(){
    _graph_it.set_domain(_graph_it.get_dom_low() * 1.25, _graph_it.get_dom_high() * 1.25);
}
