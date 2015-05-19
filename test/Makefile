# ========================================================= #
# Personal Makefile for make by [Aleda](http://aleda.cn)
#
# Last modified: 2015-04-26 12:28
#
# NOTICE:
#	This is for mode 64 and it is just an example for you.
#	Tailor it to your needs.
#
# ========================================================= #

# ========================================================= #
# modified by [Aleda](http://aleda.cn) & for summer-conf
# ========================================================= #

# 64 bit
ifeq ($(shell uname -m),x86_64)
# ==================Global Configure======================== #
CC=gcc
AR=ar
CXX=g++
CXXFLAGS=-g -pipe -W -Wall -fPIC
CFLAGS=-g -pipe -W -Wall -fPIC --disable-ldap --disable-ldaps
ARFLAGS=rv
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS 
# ==================Global Configure======================== #


# ==================User   Configure======================== #
INCPATH=-I../include -I../src
# Tailor it to your needs
LIBS=../libsummerconf.a
TEST_SRCS=$(wildcard test/*.cpp)
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %cpp,%o,$(SRCS))
TEST_OBJS=$(patsubst %cpp,%o,$(TEST_SRCS))

TARGET_APP_NAME=summerconf_test
TARGET_AR_NAME=libsummerconf.a
TARGET_TEST_NAME=smrconf_test
# ==================User   Configure======================== #


# ==================User   Builders========================= #
.PHONY: all clean output
all: $(TARGET_APP_NAME) .copy-conf 
	@echo "[BUILD][Target: all]"
	@echo "make all done"

clean:
	@echo "[BUILD][Target: clean]"
	rm -rf *.o
	rm -rf $(TARGET_APP_NAME)
	@echo "make clean done"
output:
	@echo "[BUILD][Target: output]"
	mkdir -p output/include
	mkdir -p output/lib
	cp src/*.h output/include
	cp libsummer.a output/lib
	@echo "make output done"
	
.PHONY: ar
ar: $(TARGET_AR_NAME)
	@echo "[ARCHIVE][Target: ar]"
	@echo "make ar done"

.PHONY: dist
dist:
	@echo "[BUILD][Target: dist]"
	tar czvf output.tar.gz output
	@echo "make dist done"
.PHONY: distclean
distclean: clean
	@echo "[BUILD][Target: distclean]"
	rm -f output.tar.gz
	@echo "make distclean done"

$(TARGET_APP_NAME): %:%.o
	@echo "[BUILD][Target: $(TARHET_APP_NAME)]"
	$(CXX) $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS) $< -Xlinker "-(" $(LIBS) -Xlinker "-)" -o $@
	@echo "make $(TARGET_APP_NAME) done"

.copy-conf:
	@echo "[BUILD][Target: conf]"
	@echo "cp conf done"

%.o: %.cpp 
	@echo "[BUILD][Target: compiler]"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o $@ $<
	@echo "make compiler done"
# ==================User   Builders========================= #

endif #ifeq ($(shell uname -m),x86_64)


