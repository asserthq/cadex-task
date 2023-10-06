# cadex-task

## Clone
```bash
$ git clone git@github.com:zdrvzbl/cadex-task.git
```

## Build
```bash
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```

## Testing
### On Unix
```bash
$ cd build
$ ctest
```
### On Windows 
```cmd
$ cd build\test
$ ctest
```

## Structure
- Static lib `curves`. Builds to `build/curves`
- App with task `sandbox` which using lib. Builds to `build/sandbox`
- Test framework app `curves_test`. Builds to `build/test`
