This project contains a minimum set of files to work with Qt5 + OpenCV + CMake.

- Primarily designed for CLion and Mac, but should work with other IDEs and operating system.

- You should add paths before compile. For ease of use, here is an excerpt from my .bash_profile
```
# OpenCV
export OpenCV_DIR=/Users/mhirano/opencv-3.2.0/build
```

- Use out-of-source build. Namely, run `cmake` within debug or release directory as `cmake ..`

- C++11 is activated by default if available.
