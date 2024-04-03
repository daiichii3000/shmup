include Makefile.inc

all: $(BINARY)
	@echo Complete!

run: all
	$(BINARY)

$(BINARY): $(OBJS)
	$(CXX) $(OBJS) -o $(BINARY) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BINARY)

.PHONY: all run clean
