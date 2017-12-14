#include "animate.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"


animate::animate(string temp)

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    _temp_function = temp;

    system = System(temp);
    window.setFramerateLimit(60);

    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
}

void animate::render(){
       window.clear();
       Draw();
       window.display();
}



void animate::processEvents()
{
   sf::Event event;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code){
               case sf::Keyboard::Left:
                   //shift graph to left
                   system.Pan_left();
                   render();
                   break;
               case sf::Keyboard::Right:
                   //shift graph to right
                   system.Pan_right();
                   render();
                   break;
               case sf::Keyboard::Z:
                   //zoom in
                   system.Zoom_in();
                   break;
               case sf::Keyboard::X:
                   //zoom out
                   system.Zoom_out();
                   break;
               case sf::Keyboard::N:{
                   //input new function
                   cout << "ALL operations and numbers must be separated by a space" << endl;
                   string input;
                   cout << "> "; getline(cin,input);
                   system.Input_fcn(input);
                   cout << "have saved fcn: " << input << endl;
                   break;
               }
               case sf::Keyboard::Escape:{
                   window.close();
                break;
               }
               }

               break;

               default:
                   break;
           }
       }
}
void animate::run()
{
    cout << "To pan graph, use arrow keys." << endl;
    cout << "To zoom in, press z" << endl;
    cout << "To zoom out, press x" << endl;
    cout << "To input new function, press n" << endl;
   while (window.isOpen())
   {
       processEvents();
       render(); //clear/draw/display
   }

//   ....................../´¯/)
//   ....................,/¯./
//   .................../.../
//   ............/´¯¯¯/'..'/´¯¯`·¸
//   ........../'/../.../...../¨¯\
//   ........('(...´..´...¯~/'..')
//   .........\..........'...../
//   ..........''..\...... _.·´
//   ............\..........(
//   ..............\.........\...

   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}
