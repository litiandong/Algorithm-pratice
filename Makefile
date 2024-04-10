
Green = \033[0;32m
Yellow = \033[0;33m 
Blue = \033[0;34m 

End = \033[0m

P := ./Dijkstra/ \
	./sort/heap/ \

all:
	@for dir in $(P); do\
		echo "make $$dir"; \
		$(MAKE) -C $$dir all --no-print-directory; \
	done

test: all
	@for dir in $(P); do \
		echo "$(Yellow)Test $$dir$(End)"; \
		$(MAKE) -C $$dir test -no-print-directory; \
	done

clean:
	@for dir in $(P); do \
		echo "$(Yellow)clean $$dir\n$(End)" \
		$(MAKE) -C $$dir clean --no-print-directory;\
	done


.PHONY: clean all test
