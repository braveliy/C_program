#
# Copyright (C) 1988-2011, Nantian Co., Ltd.
#
# $CVSHeader: atmp20/Makefile,v 1.2.2.2 2011/07/05 07:31:44 mymtom Exp $
#
 
SUBDIRS	= tsp30/MessageQ 

TAGDIRS = inc30 
		  

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
