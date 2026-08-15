#include <bits/stdc++.h>
using namespace std;

class MusicPlayer;


// ======================================================
// State Interface
// ======================================================

class PlayerState {

public:

    virtual void play(MusicPlayer& player) = 0;

    virtual void pause(MusicPlayer& player) = 0;

    virtual void stop(MusicPlayer& player) = 0;

    virtual ~PlayerState() = default;
};


// Forward declarations
class PlayingState;
class PausedState;
class StoppedState;


// ======================================================
// Context
// ======================================================

class MusicPlayer {

private:

    PlayerState* state;

public:

    MusicPlayer(PlayerState* initialState)
        : state(initialState) {}


    void setState(PlayerState* newState) {

        state = newState;
    }


    void play() {

        state->play(*this);
    }


    void pause() {

        state->pause(*this);
    }


    void stop() {

        state->stop(*this);
    }
};


// ======================================================
// Global State Objects
// ======================================================

PlayerState* playingState;
PlayerState* pausedState;
PlayerState* stoppedState;


// ======================================================
// Playing State
// ======================================================

class PlayingState : public PlayerState {

public:

    void play(MusicPlayer& player) override {

        cout << "Music is already playing.\n";
    }


    void pause(MusicPlayer& player) override {

        cout << "Music paused.\n";

        player.setState(pausedState);
    }


    void stop(MusicPlayer& player) override {

        cout << "Music stopped.\n";

        player.setState(stoppedState);
    }
};


// ======================================================
// Paused State
// ======================================================

class PausedState : public PlayerState {

public:

    void play(MusicPlayer& player) override {

        cout << "Resuming music.\n";

        player.setState(playingState);
    }


    void pause(MusicPlayer& player) override {

        cout << "Music is already paused.\n";
    }


    void stop(MusicPlayer& player) override {

        cout << "Music stopped.\n";

        player.setState(stoppedState);
    }
};


// ======================================================
// Stopped State
// ======================================================

class StoppedState : public PlayerState {

public:

    void play(MusicPlayer& player) override {

        cout << "Starting music.\n";

        player.setState(playingState);
    }


    void pause(MusicPlayer& player) override {

        cout << "Cannot pause. Music is stopped.\n";
    }


    void stop(MusicPlayer& player) override {

        cout << "Music is already stopped.\n";
    }
};


// ======================================================
// Main
// ======================================================

int main() {

    // Create state objects

    StoppedState stopped;
    PlayingState playing;
    PausedState paused;


    // Set global pointers

    stoppedState = &stopped;
    playingState = &playing;
    pausedState = &paused;


    // Create player in STOPPED state

    MusicPlayer player(stoppedState);


    player.play();
    // Starting music.


    player.pause();
    // Music paused.


    player.play();
    // Resuming music.


    player.stop();
    // Music stopped.


    player.stop();
    // Music is already stopped.


    return 0;
}