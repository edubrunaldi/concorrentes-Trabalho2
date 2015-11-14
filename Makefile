#Compilation variables. Compilation flags.
#for special includes copy this -I/path/for/somehting
CC=mpic++

# FLAGS= -I/usr/include/opencv -L/lib64 -lopencv_core -lm -lopencv_contrib -lopencv_features2d
# OPENCV_FLAGS= `pkg-config opencv --libs --cflags`
OPENCV_FLAGS= -lopencv_core -lopencv_highgui -lopencv_imgproc
OPENMPI_FLAGS= -fopenmp
FLAGS=-lm -Wall $(OPENCV_FLAGS) $(OPENMPI_FLAGS)

#File sources
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(wildcard *.h)
TARGET_DIR=./
TARGET=$(TARGET_DIR)main_mt

#Main
all: $(TARGET)
#	
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(FLAGS)

#ADT (TAD em portugues)
%.o: %.cpp %.h
	$(CC) $(FLAGS) -c $<

#if no header
%.o: %.cpp
	$(CC) $(FLAGS) -c $<

#clean .o and main
clean:
	rm -f *.o $(TARGET)

#Quick clean+all
rebuild: clean all

zip_code: 
	zip $(ZIPNAME) $(SOURCES) $(HEADERS) Makefile 

zip: 
	zip $(ZIPNAME) $(SOURCES) $(HEADERS)  $(TARGET) Makefile
