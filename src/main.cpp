#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

sf::SoundBuffer buffer("assets/Sounds/Acoustic.mp3");

class Sound {

private:
  std::vector<sf::Sound> soundPool;
  const int PoolSize = 10;
  float pitch = 1.f; // 1.f is default pitch

public:
  Sound() {
    for (int i = 0; i < PoolSize; i++) {
      soundPool.emplace_back(buffer);
    }
  }

  float getPitch() { return pitch; }
  void setPitch(float p) { pitch = p; }

  void play() {
    for (auto &sound : soundPool) {
      if (sound.getStatus() != sf::Sound::Status::Playing) {
        sound.setPitch(pitch);
        sound.play();
        break;
      }
    }
  }
};

int getBlackKey(int, const int);
int main() {

  // keyboard keys
  sf::Keyboard::Scan keys[] = {
      // white keys
      sf::Keyboard::Scancode::CapsLock, sf::Keyboard::Scancode::A,
      sf::Keyboard::Scancode::S, sf::Keyboard::Scancode::D,
      sf::Keyboard::Scancode::F, sf::Keyboard::Scancode::G,
      sf::Keyboard::Scancode::H, sf::Keyboard::Scancode::J,
      sf::Keyboard::Scancode::K, sf::Keyboard::Scancode::L,
      sf::Keyboard::Scancode::Semicolon, sf::Keyboard::Scancode::Apostrophe,
      sf::Keyboard::Scancode::Backslash, sf::Keyboard::Scancode::M,
      // black keys
      sf::Keyboard::Scancode::Tab, sf::Keyboard::Scancode::Q,
      sf::Keyboard::Scancode::E, sf::Keyboard::Scancode::R,
      sf::Keyboard::Scancode::T, sf::Keyboard::Scancode::U,
      sf::Keyboard::Scancode::I, sf::Keyboard::Scancode::P,
      sf::Keyboard::Scancode::LBracket, sf::Keyboard::Scancode::RBracket};

  int key_n = sizeof(keys) / sizeof(keys[0]);

  // anti aliasing
  sf::ContextSettings settings;
  settings.antiAliasingLevel = 4;

  // create window
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  const int windowWidth = 1000, windowHeight = 300;
  sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "SFML",
                          sf::State::Windowed, settings);
  int posX = (desktop.size.x - windowWidth) / 2;
  int posY = (desktop.size.y - windowHeight) / 2;
  window.setPosition({posX, posY});
  window.setTitle("Piano");

  // shape of key
  sf::RectangleShape shape;
  shape.setFillColor(sf::Color::White);
  shape.setOutlineColor(sf::Color::Black);
  shape.setOutlineThickness(-1.f);

  // load sound
  Sound sound[key_n];
  for (int i = 0; i < key_n; i++) {
    sound[i].setPitch(std::pow(2, (i - 12) / 12.f));
  }

  window.setKeyRepeatEnabled(false);
  // keep window open
  while (window.isOpen()) {
    // handle events
    while (std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      } else if (event->is<sf::Event::Resized>()) {
        sf::View view(
            sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
        window.setView(view);
      }

      // Keyboard input
      else if (auto key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->scancode == keys[0])
          sound[0].play(); // C1
        if (key->scancode == keys[1])
          sound[2].play(); // D1
        if (key->scancode == keys[2])
          sound[4].play(); // E1
        if (key->scancode == keys[3])
          sound[5].play(); // F1
        if (key->scancode == keys[4])
          sound[7].play(); // G1
        if (key->scancode == keys[5])
          sound[9].play(); // A1
        if (key->scancode == keys[6])
          sound[11].play(); // B1
        if (key->scancode == keys[7])
          sound[12].play(); // C2
        if (key->scancode == keys[8])
          sound[14].play(); // D2
        if (key->scancode == keys[9])
          sound[16].play(); // E2
        if (key->scancode == keys[10])
          sound[17].play(); // F2
        if (key->scancode == keys[11])
          sound[19].play(); // G2
        if (key->scancode == keys[12])
          sound[21].play(); // A2
        if (key->scancode == keys[13])
          sound[23].play(); // B2
        if (key->scancode == keys[14])
          sound[1].play(); // C1#
        if (key->scancode == keys[15])
          sound[3].play(); // D1#
        if (key->scancode == keys[16])
          sound[6].play(); // F1#
        if (key->scancode == keys[17])
          sound[8].play(); // G1#
        if (key->scancode == keys[18])
          sound[10].play(); // A1#
        if (key->scancode == keys[19])
          sound[13].play(); // C2#
        if (key->scancode == keys[20])
          sound[15].play(); // D2#
        if (key->scancode == keys[21])
          sound[18].play(); // F2#
        if (key->scancode == keys[22])
          sound[20].play(); // G2#
        if (key->scancode == keys[23])
          sound[22].play(); // A2#
      }
    }

    // window size
    float window_w = window.getView().getSize().x,
          window_h = window.getView().getSize().y,
          window_min = std::min(window_w, window_h);

    // fill window with color
    window.clear(sf::Color(39, 39, 39));

    // draw piano
    int whiteKeys = 14, blackKeys = 10;
    float key_w = window_w / whiteKeys;
    for (int i = 0; i < whiteKeys; i++) {
      shape.setSize({key_w, window_h});
      shape.setPosition({i * key_w, 0.f});
      if (sf::Keyboard::isKeyPressed(keys[i]))
        shape.setFillColor(sf::Color(0, 170, 255));
      else
        shape.setFillColor(sf::Color::White);
      window.draw(shape);
      // draw black keys
      if (i % 7 != 2 && i % 7 != 6) {
        shape.setSize({key_w / 2, window_h * 0.6f});
        shape.setPosition({(i + 0.50f) * key_w, 0.f});
        if (sf::Keyboard::isKeyPressed(keys[getBlackKey(i, whiteKeys)]))
          shape.setFillColor(sf::Color(0, 170, 255));
        else
          shape.setFillColor(sf::Color::Black);
        window.draw(shape);
      }
    }

    // display
    window.display();
  }
  return 0;
}

int getBlackKey(int x, const int WKeys) {
  int keysSkipped;
  switch (x) {
  case 0 ... 1:
    keysSkipped = 0;
    break;
  case 2 ... 5:
    keysSkipped = 1;
    break;
  case 6 ... 8:
    keysSkipped = 2;
    break;
  case 9 ... 12:
    keysSkipped = 3;
    break;
  case 13:
    keysSkipped = 4;
  }
  return x + WKeys - keysSkipped;
}
