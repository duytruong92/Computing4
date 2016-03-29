/**
 *  @copyright 2016
 *  @file    guitar_hero.cpp
 *  @author  Duy Truong
 *  @date    3/27/2016  
 *  @version 1.0 
 *  
 *  @brief Main program file.
 *
 *  @section DESCRIPTION
 *  This brings the guitar_string_class and ring_buffer 
 *  together into a guitar hero program.
 *  
 *  The string buttons are "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ,"
 */

#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <map>
#include "guitar_string_class.hpp"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

namespace GuitarHero {
    static std::vector<sf::Int16>
makeSamplesFromString(GuitarString & gs) {
    std::vector<sf::Int16> samples;
    gs.pluck();
    int duration = 8;
    for (int i = 0 ; i < SAMPLES_PER_SEC * duration ; i++) {
      gs.tic();
      samples.push_back(gs.sample());
    }
    return samples;
  }
}  // namespace GuitarHero

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero");
  sf::Event event;
  double freq;
  std::vector<sf::Int16> samples;
  // Map of the Guitar strings
  std::map <int, int> guitarMap;
  guitarMap[static_cast<int>(sf::Keyboard::Num1)] = 0;
  guitarMap[static_cast<int>(sf::Keyboard::Num2)] = 1;
  guitarMap[static_cast<int>(sf::Keyboard::Num3)] = 2;
  guitarMap[static_cast<int>(sf::Keyboard::Num4)] = 3;
  guitarMap[static_cast<int>(sf::Keyboard::Num5)] = 4;
  guitarMap[static_cast<int>(sf::Keyboard::Num6)] = 5;
  guitarMap[static_cast<int>(sf::Keyboard::Num7)] = 6;
  guitarMap[static_cast<int>(sf::Keyboard::Num8)] = 7;
  guitarMap[static_cast<int>(sf::Keyboard::Num9)] = 8;
  guitarMap[static_cast<int>(sf::Keyboard::Num0)] = 9;
  guitarMap[static_cast<int>(sf::Keyboard::Q)] = 10;
  guitarMap[static_cast<int>(sf::Keyboard::W)] = 11;
  guitarMap[static_cast<int>(sf::Keyboard::E)] = 12;
  guitarMap[static_cast<int>(sf::Keyboard::R)] = 13;
  guitarMap[static_cast<int>(sf::Keyboard::T)] = 14;
  guitarMap[static_cast<int>(sf::Keyboard::Y)] = 15;
  guitarMap[static_cast<int>(sf::Keyboard::U)] = 16;
  guitarMap[static_cast<int>(sf::Keyboard::I)] = 17;
  guitarMap[static_cast<int>(sf::Keyboard::O)] = 18;
  guitarMap[static_cast<int>(sf::Keyboard::P)] = 19;
  guitarMap[static_cast<int>(sf::Keyboard::A)] = 20;
  guitarMap[static_cast<int>(sf::Keyboard::S)] = 21;
  guitarMap[static_cast<int>(sf::Keyboard::D)] = 22;
  guitarMap[static_cast<int>(sf::Keyboard::F)] = 23;
  guitarMap[static_cast<int>(sf::Keyboard::G)] = 24;
  guitarMap[static_cast<int>(sf::Keyboard::H)] = 25;
  guitarMap[static_cast<int>(sf::Keyboard::J)] = 26;
  guitarMap[static_cast<int>(sf::Keyboard::K)] = 27;
  guitarMap[static_cast<int>(sf::Keyboard::L)] = 28;
  guitarMap[static_cast<int>(sf::Keyboard::Z)] = 29;
  guitarMap[static_cast<int>(sf::Keyboard::X)] = 30;
  guitarMap[static_cast<int>(sf::Keyboard::C)] = 31;
  guitarMap[static_cast<int>(sf::Keyboard::V)] = 32;
  guitarMap[static_cast<int>(sf::Keyboard::B)] = 33;
  guitarMap[static_cast<int>(sf::Keyboard::N)] = 34;
  guitarMap[static_cast<int>(sf::Keyboard::M)] = 35;
  guitarMap[static_cast<int>(sf::Keyboard::Comma)] = 36;
  // we only use the number and chracter keyboard the rest will be = 37
  guitarMap[static_cast<int>(sf::Keyboard::Escape)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::LControl)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::LShift)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::LAlt)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::LSystem)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::RControl)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::RShift)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::RAlt)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::RSystem)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Menu)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::LBracket)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::RBracket)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::SemiColon)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Period)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Quote)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Slash)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::BackSlash)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Tilde)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Equal)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Dash)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Space)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Return)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::BackSpace)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Tab)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::PageUp)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::PageDown)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::End)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Home)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Insert)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Delete)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Add)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Subtract)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Multiply)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Divide)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Left)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Right)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Down)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Up)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad0)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad1)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad2)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad3)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad4)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad5)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad6)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad7)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad8)] = 37;
  guitarMap[static_cast<int>(sf::Keyboard::Numpad9)] = 37;

  std::map<int, int>::iterator search;

  freq = CONCERT_A * pow(2, 3.0/12.0);
  GuitarHero::GuitarString gs1(freq);
  sf::Sound sound1;
  sf::SoundBuffer buf1;
  samples = makeSamplesFromString(gs1);
  if (!buf1.loadFromSamples(&samples[0], samples.size(), 2, SAMPLES_PER_SEC))
    throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
  sound1.setBuffer(buf1);

  // Contains the sounds for the guitar
  std::vector<sf::Sound> gibson;
  for (int x = 0; x < 37; x++) {
    gibson.push_back(sound1);
    sound1.setPitch(sound1.getPitch() * pow(2, 1.0/12.0));
  }

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      // Runs the sounds for the guitar keys
      case sf::Event::KeyPressed:
        search = guitarMap.find(static_cast<int>(event.key.code));
        if (search->second >=0 && search->second <=36) {
            // play the sound
            gibson.at(search->second).play();
        }
        break;

      default:
        break;
      }
      window.clear();
      window.display();
    }
  }
  window.close();
  return 0;
}
