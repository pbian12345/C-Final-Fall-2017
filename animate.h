#ifndef ANIMATE_H
#define ANIMATE_H

#include <SFML/Graphics.hpp>
#include "system.h"
class animate{
public:
    animate(string temp);               //pass in initial fcn
    void run();                         //run window
    void processEvents();               //process keyboard events (arrow keys, new fcn, and zooming)
    void render();                      //clears then draws then displays
    void Draw();                        //draws based on info from system
private:
    sf::RenderWindow window;
    System system;                      //container for all the animated objects
    string _temp_function;

};



#endif // ANIMATE_H
