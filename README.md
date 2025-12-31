# LoadTube

Small project in **C using SDL3** to create a minimalist UI for downloading Youtube videos via their links.

---

## Features

- Creation of a **graphical window** using SDL3.
- Text field for entering a video link.
- Keyboard input / clipboard handling.
- Real-time display of typed text within the window.
- Video download

---

## Prerequisites

- [SDL3](https://www.libsdl.org/) and [SDL_ttf](https://github.com/libsdl-org/SDL_ttf)
- [CMake](https://cmake.org/)
- [yt-dlp](https://github.com/yt-dlp/yt-dlp?tab=readme-ov-file#installation) standalone

---

## Installation

1. Clone the repository:
```bash
git clone https://github.com/SqualFost/LoadTube.git
cd LoadTube
```

2. Install dependencies

   For macOS ([Brew](https://brew.sh)) :
   ```bash
    brew install sdl3 sdl3_ttf cmake yt-dlp
   ```

   For Linux (Ubuntu/Debian) : 
   ```bash
    sudo apt update
    sudo apt install libsdl3-dev libsdl3-ttf-dev cmake build-essential
   ```

   For Windows ([Chocolatey](https://chocolatey.org/)): 
   ```bash
    choco install sdl3 sdl3-ttf cmake
   ```
   - Might not be available since SDL3 is new

3. Open the project in your ide and configure cmake

## Compilation and execution
```bash
mkdir build
cd build
cmake ..
make
./yt-dl
```
- An SDL window will open with a text field
- Enter the video URL then click "Download"
- Text will be displayed and be used to display the download status (not done)
- The video will be downloaded in the cmake-build-debug folder

## Notes
- Everything is basic, thanks to **C** UI
- The video is dowloading there's just no text to display the status.
---

#### Open to contributions <3
