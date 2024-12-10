How to generate Library Database

```bash
sudo zypper install libtool
sudo zypper install readline-devel 
```

```bash
autoreconf -i
./configure
make
sudo make install
```

Copy generated folder `.libs` into your Project 

```bash
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH 
```