TARGET = fscrawler

OBJS = FileSystemCrawler.o

CXX = g++
CXXFLAGS = -std=c++17
LDFLAGS = -lstdc++fs

$(TARGET):	$(OBJS)	
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

clean_obj: 
		rm -f *.o

clean:
		rm -f *.o $(TARGET)

FileSystemCrawler.o: 	FileSystemCrawler.cpp

#Recipe used in command line
#g++ -std=c++17 FileSystemCrawler.cpp -o output -lstdc++fs
