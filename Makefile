# contrib/pg_udp/Makefile

MODULE_big = pg_udp
OBJS = pg_udp.o $(WIN32RES)

EXTENSION = pg_udp
EXTVERSION = 0.1
DATA = $(EXTENSION)--$(EXTVERSION).sql
PGFILEDESC = "pg_udp - tool that helps to send UDP messages"

REGRESS = pg_udp

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/pg_udp
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
