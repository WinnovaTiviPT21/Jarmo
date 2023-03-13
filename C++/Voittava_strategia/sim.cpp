#include <iostream>

#include "sim.h"
#include "peli.h"

using namespace std;

// Laskee voiton todennäköisyyden aina kun arvaus on puolestavälistä.
void Sim::run1() {
    Peli peli;

    float wins = 0;
    for (int i = 0; i < runs; i++) {
        peli.startClicked();

        int min = 0, max = 101;
        while (peli.getCounter() > 0) {
            int guess = (min + max) / 2;
            peli.setDisplay(guess);
            peli.guessClicked();
            if (peli.getDisplay() > peli.getRngNro()) {
                max = guess;
            }
            if (peli.getDisplay() < peli.getRngNro()) {
                min = guess;
            }
            if (peli.getDisplay() == peli.getRngNro()) {
                wins++;
                break;
            }
        }
    }

    float prob = wins / runs;
    cout << "Voittamisen todennakoisyys kun arvataan aina puolestavalista: " << prob << endl;
}

// Laskee voiton todennäköisyyden aina kun arvataan satunnainen luku.
void Sim::run2() {
    Peli peli;

    float wins = 0;
    for (int i = 0; i < runs; i++) {
        peli.startClicked();

        int min = 0, max = 100;
        while (peli.getCounter() > 0) {
            uniform_int_distribution<> distr(min, max);
            mt19937 gen {static_cast<unsigned int>(
                            chrono::steady_clock::now().time_since_epoch().count())
                        };

            int guess = distr(gen);
            peli.setDisplay(guess);
            peli.guessClicked();
            if (peli.getDisplay() > peli.getRngNro()) {
                max = guess;
            }
            if (peli.getDisplay() < peli.getRngNro()) {
                min = guess;
            }
            if (peli.getDisplay() == peli.getRngNro()) {
                wins++;
                break;
            }
        }
    }

    float prob = wins / runs;
    cout << "Voittamisen todennakoisyys kun arvataan aina satunnainen luku: " << prob << endl;
}
