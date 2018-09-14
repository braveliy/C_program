#
# Copyright (C) 1988-2011, Nantian Co., Ltd.
#
# $CVSHeader: atmp20/Makefile,v 1.2.2.2 2011/07/05 07:31:44 mymtom Exp $
#
 
SUBDIRS	= \
		  tsp30/Tools \
		  public30 \
		  msp/mspapi \
		  msp/public \
		  msp/tools \
		  tsp30/public \
		  tsp30/MessageQ \
		  msp/mspsrv \
		  usrc30 \
		  tsp30  

TAGDIRS = \
		  inc30 \
		  uinc30 \
		  tsp30 \
		  msp \
		  usrc30/TaskCtl \
		  usrc30/clear \
		  usrc30/libtspdcc \
		  usrc30/libtspxml \
		  usrc30/libTcpAndFileSrc \
		  usrc30/public \
		  usrc30/libAgent \
		  public30 \
		  devlop30 \
		  $(HOME)/local/include

world: all

all clean:
	@CURDIR=`pwd`; \
	for DIR in $(SUBDIRS); do \
		cd $${CURDIR}; \
		echo "===> $${DIR} $@"; \
		cd $${DIR} && make $@; \
		if [ $$? -ne 0 ]; then break; fi; \
	done

tag:
	find $(SUBDIRS) \( -name "*.[ch]" -o -name "*.ec" \) \
		-type f >  cscope.files
	exctags --c-kinds=+px --fields=+iaS --extra=+q --language-force=c \
		-L cscope.files 
	cscope  -i cscope.files -kb

cleantag:
	rm -f cscope.files cscope.out tags
