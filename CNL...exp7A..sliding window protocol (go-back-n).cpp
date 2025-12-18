//EXP 7A: Go-back-n (SLIDING WINDOW PROTOCOL)
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int windowSize, numFrames;
    cout << "Enter window size: ";
    cin >> windowSize;
    cout << "Enter number of frames to transmit: ";
    cin >> numFrames;

    int frames[50];
    cout << "Enter " << numFrames << " frames:\n";
    for (int i = 0; i < numFrames; i++) {
        cin >> frames[i];
    }

    cout << "\nTransmitting frames using Go-Back-N protocol...\n";

    int i = 0;
    while (i < numFrames) {
        // Send frames in the current window
        for (int j = 0; j < windowSize && i + j < numFrames; j++) {
            cout << "Sending frame " << frames[i + j] << endl;
        }

        // Simulate acknowledgment and random frame loss
        bool success = true;
        for (int j = 0; j < windowSize && i + j < numFrames; j++) {
            if (rand() % 2 == 0) {  // Simulate 50% chance of frame loss
                cout << "Frame " << frames[i + j] << " received successfully.\n";
            } else {
                cout << "Frame " << frames[i + j] << " lost.\n";
                success = false;  // If any frame is lost, the whole window is resent
                break;
            }
        }

        // If all frames in the window were acknowledged, move to the next window
        if (success) {
            i += windowSize;
        } else {
            cout << "\nTimeout occurred. Resending frames in the current window...\n";
        }
    }

    cout << "\nAll frames transmitted successfully with Go-Back-N protocol.\n";

    return 0;
}

