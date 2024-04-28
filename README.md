# a-Twilight-Game

compilar: 

g++ -o teste main.cpp src/shapes.cpp src/screens.cpp -I include -lglut -lGLU -lGL -lm
./teste

g++ -o teste main.cpp src/characters.cpp src/colors.cpp src/motion.cpp src/screens.cpp src/shapes.cpp -I include -lglut -lGLU -lGL -lm

./teste