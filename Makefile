#g++ -std=c++17 FileSystemCrawler.cpp -o output -lstdc++fs
#    ^^^^^ use this recipe, it works for linux at least

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