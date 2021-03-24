# Makefile to build class 'hoalight' for Pure Data.
# Needs Makefile.pdlibbuilder as helper makefile for platform-dependent build
# settings and rules.

# library name
lib.name = hoalight

# input source file (class name == source file basename)
class.sources = hoalight.c

# all extra files to be included in binary distribution of the library
datafiles = README.md LICENSE.txt CHANGELOG.txt \
            $(wildcard *.pd) $(wildcard examples/*.pd)

cflags = -I./include -mmacosx-version-min=10.9
ldflags = -L./lib -lHOALightWrapper

# include Makefile.pdlibbuilder, allow override using PDLIBBUILDER_DIR variable
PDLIBBUILDER_DIR=.
include $(PDLIBBUILDER_DIR)/Makefile.pdlibbuilder
