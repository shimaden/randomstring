CXX = c++
#CXXFLAGS = -c -Wall -O2 -mtune=pentium4 -march=pentium4
CXXFLAGS = -c -Wall -O2 -mtune=native -march=native
PROG = randomstring
OBJS = randomstring.o
LIBS =

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

clean:
	-rm -f $(PROG) *.o *~
