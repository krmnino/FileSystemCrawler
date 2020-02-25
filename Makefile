TARGET = fsc
OBJS = \
	FileSystemCrawler.o

CXX = g++
CXXFLAGS = -std=c++17 #-lstdc++fs
LDFLAGS =

$(TARGET):	$(OBJS)
			-o $(TARGET) $(OBJS)

clean:
		rm -f *~ *.o $(TARGET)

FileSystemCrawler.o:                FileSystemCrawler.cpp
map_file_handling.o:                map_file_handling.cpp