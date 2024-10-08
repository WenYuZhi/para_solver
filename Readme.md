### 0 Introduction
Many times, we expect to call a solver to solve multiple models simultaneously for parallel acceleration. This can be achieved by using C++ multithreading tools to call the Gurobi solver in parallel. This post will demonstrate a demo code for your reference. The development environment is GCC 11.4, C++11, Ubuntu 22.04, and CMake 3.22. The setup is similar for Windows and Mac environments as well.

### 1 Make
```
cd src
cmake ..
make 
```

### 2 Usage

```
./para [file_name1] [file_name2] ... [file_nameN]
```
where file_name1, file_name2 and file_nameN are model file (mps,lp format).