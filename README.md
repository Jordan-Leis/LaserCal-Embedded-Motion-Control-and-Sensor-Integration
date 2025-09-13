# LaserCal: Embedded Motion Control and Sensor Integration Demo

LaserCal demonstrates how motion control and sensor processing can be combined in a small Qt/C++ application. It emulates a two-axis stage capable of linear and circular moves, generates synthetic laser displacement readings filtered with a moving average, and runs a calibration routine that stores results in an SQLite database. A touchscreen-friendly QML interface lets you command the stage and start calibrations without any real hardware.

## Features

- Simulated two-axis motion controller with linear and circular interpolation
- Laser displacement sensor simulator using a moving-average filter
- Calibration routine that logs readings to SQLite and reports averaged measurements
- Touchscreen-ready QML interface

## Building

### Dependencies

- Qt 5 with modules: Core, Quick, and Sql
- CMake 3.16+

Install dependencies on Debian/Ubuntu:

```bash
sudo apt-get update
sudo apt-get install -y qtbase5-dev qtdeclarative5-dev \
    qml-module-qtquick-controls2 qml-module-qtquick2 \
    libqt5sql5-sqlite build-essential cmake
```

### Configure and Build

```bash
cmake -S . -B build
cmake --build build
```

Run the application:

```bash
./build/LaserCal
```

## Usage

After launching the application, use the on-screen controls to jog the X and Y axes. Press **Calibrate** to execute a short automated sequence that records simulated sensor readings. Results are saved to `calibration.sqlite` and the average measurement is displayed.

## Database

The application creates a local SQLite database named `calibration.sqlite` and logs simulated measurements. The average of all measurements can be queried via the UI.
