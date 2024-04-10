
SUBDIRS := $(wildcard */)

.PHONY: clean

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done


