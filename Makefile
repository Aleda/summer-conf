# ========================================================= #
# Personal Makefile for make by [Aleda](http://aleda.cn)
#
# Last modified: 2015-04-26 12:28
#
# NOTICE:
# 	This is for mode 64 and it is just an example for you.
# 	Tailor it to your needs.
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
INCPATH=-I./include -I./src
# Tailor it to your needs
LIBS=
SRCS=$(wildcard src/*.cpp)
OBJS=$(patsubst %cpp,%o,$(SRCS))

TARGET_APP_NAME=summerconf
TARGET_AR_NAME=libsummerconf.a
# ==================User   Configure======================== #


# ==================User   Builders========================= #
.PHONY: ar clean output
all: ar .copy-conf 
	@echo "[BUILD][Target: all]"
	@echo "make all done"
clean:
	@echo "[BUILD][Target: clean]"
	rm -rf ./src/*.o ./test/*.o
	rm -rf $(TARGET_APP_NAME)
	rm -rf output
	rm $(TARGET_AR_NAME)
	make -C ./test clean
	@echo "make clean done"
output: ar
	@echo "[BUILD][Target: output]"
	mkdir -p output/include
	mkdir -p output/lib
	cp src/*.h output/include
	cp *.a output/lib
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

.PHONY: test
test: 
	@echo "[BUILD][Target: test]"
	make -C ./test
	@echo "make test done"

$(TARGET_APP_NAME): $(OBJS)
	@echo "[BUILD][Target: $(TARHET_APP_NAME)]"
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $<
	$(CXX) $(OBJS) -Xlinker "-(" $(LIBS) -Xlinker "-)" -o $@
	@echo "make $(TARGET_APP_NAME) done"

$(TARGET_AR_NAME): $(OBJS)
	@echo "[ARCHIVE][Target: $(TARGET_AR_NAME)]"
	$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "make $(TARGET_AR_NAME) done"

.copy-conf:
	@echo "[BUILD][Target: conf]"
	@echo "cp conf done"

src/%.o: src/%.cpp 
	@echo "[BUILD][Target: compiler]"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o $@ $<
	@echo "make compiler done"
# ==================User   Builders========================= #

endif #ifeq ($(shell uname -m),x86_64)


