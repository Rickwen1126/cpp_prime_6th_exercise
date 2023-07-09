#include <iostream>
#include "tv.h"

int main() {
    using std::cout;
    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAddjusted settings for 42\" TV:\n";
    s42.settings();

    Remote grey;

    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();
    s42.toggleRemoteState(grey);
    grey.show_state();


    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" srttings: \n";
    s58.settings();
    s58.toggleRemoteState(grey);
    grey.show_state();

    return 0;
}