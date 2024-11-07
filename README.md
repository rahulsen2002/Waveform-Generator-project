Waveform Generator
Overview
This C++ project generates different types of waveforms (Sine and Square) with customizable parameters such as frequency, amplitude, phase shift, and duration. It saves the generated waveform data as a CSV file, which can be visualized using graphing tools.

Features:
Waveform Types: Sine and Square waves.
Custom Parameters: Frequency, amplitude, phase shift (optional), duration, and sample rate.
Output: Saves waveform data to a CSV file for further processing or visualization.
Requirements
C++ Compiler: g++ (or any standard C++ compiler).
Libraries: Standard C++ libraries (e.g., <cmath>, <fstream>, <vector>).
How to Set Up the Project Locally
Step 1: Clone the Repository
Clone the repository to your local machine using the following command:

bash
Copy code
git clone https://github.com/your-username/waveform-generator.git
cd waveform-generator
Step 2: Compile the Program
Make sure you have g++ or any C++ compiler installed. If you're on Windows, you can use MinGW. On Linux or macOS, g++ is typically already installed or available through package managers.

Run the following command to compile the program:

bash
Copy code
g++ -o Signal Signal.cpp
This will generate an executable named Signal.exe (on Windows) or Signal (on Linux/macOS).

Step 3: Run the Program
Once compiled, run the program by executing:

Windows:# Waveform-Generator-project
Linux/macOS:
bash
Copy code
./Signal
Step 4: Input Parameters
The program will ask you to enter the following parameters:

Waveform type: (sine or square)
Frequency (Hz): Frequency of the waveform.
Amplitude: Amplitude of the waveform.
Phase shift (radians): Optional phase shift.
Duration (seconds): Duration for which the waveform will be generated.
Sample rate (samples per second): The rate at which the waveform is sampled.
Step 5: View the Output
Once the program completes, the waveform data is saved to a CSV file named waveform.csv in the same directory. This file contains two columns: Time and Value, representing the time and the corresponding waveform value.


End of README
