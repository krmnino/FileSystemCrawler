TARGET = fsc
OBJS = \
  map_file_handling.o \
  FileSystemCrawler.o

CXX = g++
CXXFLAGS = -std=gnu++1z -Wall -Wextra -pedantic-errors
LDFLAGS =

$(TARGET):	$(OBJS)
			$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET) lstdc++fs

clean:
		rm -f *~ *.o $(TARGET)

FileSystemCrawler.o:                FileSystemCrawler.cpp
map_file_handling.o:                map_file_handling.cpp