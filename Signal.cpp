#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <memory>  // For std::unique_ptr

using namespace std;

class Waveform {
protected:
    float frequency;
    float amplitude;
    float phase;

public:
    Waveform(float freq = 1.0, float amp = 1.0, float ph = 0.0)
        : frequency(freq), amplitude(amp), phase(ph) {}

    virtual float generate(float time) = 0;
    virtual void setFrequency(float freq) { frequency = freq; }
    virtual void setAmplitude(float amp) { amplitude = amp; }
    virtual void setPhase(float ph) { phase = ph; }

    virtual ~Waveform() = default;
};

class SineWave : public Waveform {
public:
    SineWave(float freq = 1.0, float amp = 1.0, float ph = 0.0)
        : Waveform(freq, amp, ph) {}

    float generate(float time) override {
        return amplitude * sin(2 * M_PI * frequency * time + phase);
    }
};

class SquareWave : public Waveform {
public:
    SquareWave(float freq = 1.0, float amp = 1.0, float ph = 0.0)
        : Waveform(freq, amp, ph) {}

    float generate(float time) override {
        return (sin(2 * M_PI * frequency * time + phase) >= 0) ? amplitude : -amplitude;
    }
};

void generateWaveform(Waveform* waveform, float duration, float sampleRate, vector<float>& timeValues, vector<float>& waveValues) {
    int samples = static_cast<int>(duration * sampleRate);
    for (int i = 0; i < samples; ++i) {
        float time = i / sampleRate;
        timeValues.push_back(time);
        waveValues.push_back(waveform->generate(time));
    }
}

int main() {
    // User input
    string waveType;
    float frequency, amplitude, phase, duration, sampleRate;
    cout << "Enter waveform type (sine/square): ";
    cin >> waveType;
    cout << "Enter frequency (Hz): ";
    cin >> frequency;
    cout << "Enter amplitude: ";
    cin >> amplitude;
    cout << "Enter phase shift (radians, optional - 0 for none): ";
    cin >> phase;
    cout << "Enter duration (seconds): ";
    cin >> duration;
    cout << "Enter sample rate (samples per second): ";
    cin >> sampleRate;

    unique_ptr<Waveform> waveform = nullptr;
    if (waveType == "sine") {
        waveform = make_unique<SineWave>(frequency, amplitude, phase);
    } else if (waveType == "square") {
        waveform = make_unique<SquareWave>(frequency, amplitude, phase);
    } else {
        cerr << "Invalid waveform type!" << endl;
        return 1;
    }

    // Generate waveform data
    vector<float> timeValues;
    vector<float> waveValues;
    generateWaveform(waveform.get(), duration, sampleRate, timeValues, waveValues);

    // Save the waveform data to a CSV file
    ofstream outFile("waveform.csv");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile << "Time,Value\n";
    for (size_t i = 0; i < timeValues.size(); ++i) {
        outFile << timeValues[i] << "," << waveValues[i] << "\n";
    }

    cout << "Waveform data saved to 'waveform.csv'.\n";

    return 0;
}
