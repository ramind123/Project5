#ifndef _CGAME_HPP_
#define _CGAME_HPP_
#include <string>

enum GameDuration
{
    #define DEFINE_DURATION(duration, int) duration,
    #include "game_enum.hpp"
    #undef DEFINE_DURATION
};

class CGame
{
public:
    CGame();
    CGame(std::string const&, GameDuration const&, float const&, std::string const&, std::string const&, std::string const&);
    friend std::ostream& operator<<(std::ostream&, CGame const&);
    friend std::istream& operator>>(std::istream&, CGame&);
    friend bool operator==(CGame const&, std::string const&);
    bool isEmpty() const;
    bool isAssigned() const;
    void reset();
    unsigned int getValue() const;
private:
    std::string id;
    GameDuration duration;
    float payrate;
    std::string center;
    std::string ar1;
    std::string ar2;
    GameDuration stringToDuration(std::string const&);
    float stringToFloat(std::string const&);
    std::string durationToString() const;
    void setDuration(std::string const&);
    void setPayrate(std::string const&);
    int durationToInt() const;
};

#endif