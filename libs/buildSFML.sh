git submodule update --init
echo "Will now check for dpkg installed libs."
echo "Press ctrl+C in case you don't have sudo access."
sudo apt-get install libjpeg-dev libxrandr-dev libfreetype6-dev libX11-dev libx11-xcb-dev libxcb-image0-dev libxcb-randr0-dev libxcb1-dev libflac-dev libogg-dev libvorbis-dev libvorbisenc2 libvorbisfile3 libopenal-dev libpthread-stubs0-dev

cd SFML
cmake -DCMAKE_BUILD_TYPE=release
make
cmake -DCMAKE_BUILD_TYPE=debug
make
