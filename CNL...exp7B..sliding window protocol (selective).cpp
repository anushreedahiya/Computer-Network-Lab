//EXP 7B: Selective protocol (SLIDING WINDOW PROTOCOL)
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int windowSize, numFrames;
    cout << "Enter window size: ";
    cin >> windowSize;
    cout << "Enter number of frames to transmit: ";
    cin >> numFrames;

    int frames[50], acknowledged[50] = {0};

    cout << "Enter " << numFrames << " frames:\n";
    for (int i = 0; i < numFrames; i++) {
        cin >> frames[i];
    }

    cout << "\nTransmitting frames using Selective Repeat protocol...\n";

    int i = 0;
    while (i < numFrames) {
        // Send frames in the current window
        for (int j = 0; j < windowSize && i + j < numFrames; j++) {
            cout << "Sending frame " << frames[i + j] << endl;

            if (rand() % 2 == 0) {
                cout << "Frame " << frames[i + j] << " received successfully.\n";
                acknowledged[i + j] = 1; // Frame received
            } else {
                cout << "Frame " << frames[i + j] << " lost.\n";
            }
        }

        // Checking acknowledgments and retransmit lost frames
        for (int j = 0; j < windowSize && i + j < numFrames; j++) {
            if (acknowledged[i + j] == 0) {
                cout << "Retransmitting lost frame " << frames[i + j] << endl;
                cout << "Frame " << frames[i + j] << " received successfully.\n";
                acknowledged[i + j] = 1; 
            }
        }

        // Slide the window forward to the next unacknowledged frame
        while (i < numFrames && acknowledged[i] == 1) {
            i++;
        }
    }

    cout << "\nAll frames transmitted successfully with Selective Repeat protocol.\n";

    return 0;
}

