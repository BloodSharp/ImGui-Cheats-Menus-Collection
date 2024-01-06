#
# Makefile to use with emscripten
# See https://emscripten.org/docs/getting_started/downloads.html
# for installation instructions.
#
# This Makefile assumes you have loaded emscripten's environment.
# (On Windows, you may need to execute emsdk_env.bat or encmdprompt.bat ahead)
#
# Running `make` will produce three files:
#  - web/index.html
#  - web/index.js
#  - web/index.wasm
#
# All three are needed to run the demo.

ifeq ($(shell echo $(ComSpec)),C:\Windows\system32\cmd.exe)
	SLASH_PATH = "\\"
	REMOVE_FILE_COMMAND = del /f
	REMOVE_FOLDER_COMMAND = RD /S /Q
	MKDIR_COMMAND = mkdir
	COPY_COMMAND = copy
	FONTS_FOLDER = "C:\Windows\Fonts\"
else
    SLASH_PATH = /
	REMOVE_COMMAND = rm -Rf
	MKDIR_COMMAND = mkdir -p
	COPY_COMMAND = cp
	FONTS_FOLDER = c/Windows/Fonts/
endif

CC = emcc
CXX = em++
WEB_DIR = Web
EXE = $(WEB_DIR)/index.html
IMGUI_DIR = ../imgui


SOURCES = IGCMC-Main.cpp IGCMC-Interface.cpp IGCMC-ImageLoader.cpp
SOURCES += IGCMC-Aimware.cpp
SOURCES += IGCMC-NeverLose.cpp

SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl2.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp

#INCLUDE_PATHS = -I ../PreCompiled
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
UNAME_S := $(shell uname -s)
CPPFLAGS = -DB3DM_BUILDING_MENUTESTER
LDFLAGS =
EMS =

##---------------------------------------------------------------------
## EMSCRIPTEN OPTIONS
##---------------------------------------------------------------------

# ("EMS" options gets added to both CPPFLAGS and LDFLAGS, whereas some options are for linker only)
EMS += -s USE_SDL=2
EMS += -s DISABLE_EXCEPTION_CATCHING=1
LDFLAGS += -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 -s NO_EXIT_RUNTIME=0 -s ASSERTIONS=1

# Uncomment next line to fix possible rendering bugs with Emscripten version older then 1.39.0 (https://github.com/ocornut/imgui/issues/2877)
#EMS += -s BINARYEN_TRAP_MODE=clamp
#EMS += -s SAFE_HEAP=1    ## Adds overhead

# Emscripten allows preloading a file or folder to be accessible at runtime.
# The Makefile for this example project suggests embedding the misc/fonts/ folder into our application, it will then be accessible as "/fonts"
# See documentation for more details: https://emscripten.org/docs/porting/files/packaging_files.html
# (Default value is 0. Set to 1 to enable file-system and include the misc/fonts/ folder as part of the build.)
USE_FILE_SYSTEM = 1
ifeq ($(USE_FILE_SYSTEM), 0)
LDFLAGS += -s NO_FILESYSTEM=1
CPPFLAGS += -DIMGUI_DISABLE_FILE_FUNCTIONS
endif
ifeq ($(USE_FILE_SYSTEM), 1)
#LDFLAGS += --no-heap-copy --preload-file ../../misc/fonts@/fonts
LDFLAGS += --no-heap-copy --preload-file FileSystem@/FileSystem
endif

##---------------------------------------------------------------------
## FINAL BUILD FLAGS
##---------------------------------------------------------------------

CPPFLAGS += -I$(COMMON_DIR)
#CPPFLAGS += -g
CPPFLAGS += -Wall -Wformat -Os $(EMS)
LDFLAGS += --shell-file $(IMGUI_DIR)/examples/libs/emscripten/shell_minimal.html $(EMS)

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

%.o:%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_PATHS) -c -o $@ $<

%.o:$(IMGUI_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_PATHS) -c -o $@ $<

%.o:$(IMGUI_DIR)/backends/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_PATHS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(EXE)

$(WEB_DIR):
	$(MKDIR_COMMAND) $@
	$(MKDIR_COMMAND) FileSystem
	$(MKDIR_COMMAND) FileSystem$(SLASH_PATH)Fonts
	$(COPY_COMMAND) $(FONTS_FOLDER)ariblk.ttf FileSystem$(SLASH_PATH)Fonts
	$(COPY_COMMAND) $(FONTS_FOLDER)arialbd.ttf FileSystem$(SLASH_PATH)Fonts

serve: all
	python3 -m http.server -d $(WEB_DIR)

$(EXE): $(OBJS) $(WEB_DIR)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	$(REMOVE_FILE_COMMAND) $(OBJS)
	$(REMOVE_FOLDER_COMMAND) $(WEB_DIR) FileSystem