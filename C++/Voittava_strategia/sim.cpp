#include <iostream>

#include "sim.h"
#include "peli.h"

using namespace std;

Sim::Sim()
{

}

void Sim::run() {
    Peli peli;
    for (int i = 0; i < samp; i++) {
        peli.startClicked();

        //int guess = 50;
        int win = 0;
        int min = 0, max = 100;
        while (peli.getCounter() > 0) {
            int guess = 0.5 * (min + max);
            peli.setDisplay(guess);
            peli.guessClicked();
            if (peli.getDisplay() > peli.getRngNro()) {
                max = guess;
            }
            if (peli.getDisplay() < peli.getRngNro()) {
                min = guess;
            }
            if (peli.getDisplay() == peli.getRngNro()) {
                win++;
                break;
            }
        }
    }
}
