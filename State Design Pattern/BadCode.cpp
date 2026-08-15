#include<bits/stdc++.h>
using namespace std;

enum class State{
    PLAYING ,
    PAUSED,
    STOPPED

};

class MusicPlayer{
    private :
       State state;

    public:
     MusicPlayer():state(State::STOPPED){}

     void play(){
      if (state == State::STOPPED) {
            cout << "Starting music\n";
            state = State::PLAYING;
        }
        else if (state == State::PAUSED) {
            cout << "Resuming music\n";
            state = State::PLAYING;
        }
        else if (state == State::PLAYING) {
            cout << "Music is already playing\n";
        } 
     }

     void pause(){
          if (state == State::PLAYING) {
            cout << "Music paused\n";
            state = State::PAUSED;
        }
        else if (state == State::PAUSED) {
            cout << "Music is already paused\n";
        }
        else if (state == State::STOPPED) {
            cout << "Cannot pause. Music is stopped\n";
        }
     }

     void stop(){
          if (state == State::PLAYING ||
            state == State::PAUSED) {

            cout << "Music stopped\n";
            state = State::STOPPED;
        }
        else {
            cout << "Music is already stopped\n";
        }
     }

};

int main(){
    MusicPlayer player;

    player.play();
    player.pause();
    player.play();
    player.stop();
    return 0;
}

// Problem :
// - Violation of Open/Closed Principle
// - state explosion problem : If we will 2-3 more state in future if-else grows 
// - The main class knows about every possible state. 
// - MusicPlayer , knows everthing about every state


// Don't ask "What state am I in?" and then decide what to do. Let the current state tell you what to do.?