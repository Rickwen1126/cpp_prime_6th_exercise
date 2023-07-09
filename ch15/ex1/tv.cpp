#include <iostream>
#include "tv.h"

bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    } else {
        return false;
    }
}

bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    } else {
        return false;
    }
}

void Tv::chanup() {
    if (channel < maxchannel) {
        channel++;
    } else {
        channel = 1;
    }
}

void Tv::chandown() {
    if (channel > 1) {
        channel--;
    } else {
        channel = maxchannel;
    }
}

void Tv::settings() const {
    using std::cout;
    using std::endl;
    cout << "TV is" << (state == Off ? " Off" : " On") << endl;
    if (state == On) {
        cout << "Volum setting = " << volume << endl;
        cout << "Channel srtting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
    }
}

void Tv::toggleRemoteState(Remote &r) {
    if (state == Off) return;

    r.state = Remote::NORMAL == r.state ? Remote::INTERACTIVE : Remote::NORMAL;
}

void Remote::show_state() const {
    using std::cout;
    using std::endl;
    cout << "Remote State is: " << state << endl;
}